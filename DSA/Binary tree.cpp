#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BT {
public:
    node *root;

    BT(int value) {
        root = new node(value);
    }

    void print_inorder() {
        inorder(root);
        cout << endl;
    }

    void inorder(node *curr) {
        if (curr == NULL) {
            return;
        }
        inorder(curr->left);
        cout << curr->data << " ";
        inorder(curr->right);
    }

    void print_preorder() {
        preorder(root);
        cout << endl;
    }

    void preorder(node *curr) {
        if (curr == NULL) {
            return;
        }
        cout << curr->data << " ";
        preorder(curr->left);
        preorder(curr->right);
    }

    void print_postorder() {
        postorder(root);
        cout << endl;
    }

    void postorder(node *curr) {
        if (curr == NULL) {
            return;
        }
        postorder(curr->left);
        postorder(curr->right);
        cout << curr->data << " ";
    }
};

node* insert(node *root, int value) {
    if (root == NULL) {
        return new node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void print_level_order(node *root) {
    if (root == NULL) return;

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node *a = q.front();
        q.pop();
        if (a != NULL) {
            cout << a->data << " ";
            if (a->left) q.push(a->left);
            if (a->right) q.push(a->right);
        } else if (!q.empty()) {
            q.push(NULL);
        }
    }
    cout << endl;
}

void sum_at_k_level(node *root, int j) {
    if (root == NULL) return;

    queue<node *> q;
    q.push(root);
    q.push(NULL);
    int sum = 0;
    int i = 0;

    while (!q.empty()) {
        node *a = q.front();
        q.pop();

        if (a != NULL) {
            if (i == j) {
                sum += a->data;
            }
            if (a->left) q.push(a->left);
            if (a->right) q.push(a->right);
        } else {
            if (i == j) {
                cout << "The sum is " << sum << endl;
                return;
            }
            if (!q.empty()) {
                q.push(NULL);
            }
            i++;
            sum = 0;
        }
    }

    cout << "Level " << j << " does not exist in the tree." << endl;
}

int count_node(node *root) {
    if (root == NULL) {
        return 0;
    }
    return count_node(root->left) + count_node(root->right) + 1;
}

int sum_node(node *root) {
    if (root == NULL) {
        return 0;
    }
    return root->data + sum_node(root->left) + sum_node(root->right);
}

int calculate_height(node *root) {
    if (root == NULL) {
        return 0;
    }
    int lh = calculate_height(root->left);
    int rh = calculate_height(root->right);
    return max(lh, rh) + 1;
}

int cal_diameter(node *root) {
    if (root == NULL) {
        return 0;
    }
    int lh = calculate_height(root->left);
    int rh = calculate_height(root->right);
    int curr_dia = lh + rh + 1;
    int ld = cal_diameter(root->left);
    int rd = cal_diameter(root->right);
    return max(curr_dia, max(ld, rd));
}

void sum_function(node *&root) {
    if (root == NULL) {
        return;
    }
    sum_function(root->left);
    sum_function(root->right);

    if (root->left != NULL) {
        root->data += root->left->data;
    }

    if (root->right != NULL) {
        root->data += root->right->data;
    }
}

bool isbalance(node *root) {
    if (root == NULL) {
        return true;
    }
    if (!isbalance(root->left)) {
        return false;
    }
    if (!isbalance(root->right)) {
        return false;
    }

    int lh = calculate_height(root->left);
    int rh = calculate_height(root->right);
    return abs(lh - rh) < 2;
}

void flatten_tree(node *&root) {
    if (root == NULL) {
        return;
    }

    flatten_tree(root->left);
    flatten_tree(root->right);

    if (root->left != NULL) {
        node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        node *t = root->right;
        while (t->right != NULL) {
            t = t->right;
        }
        t->right = temp;
    }
}

void right_view(node *root) {
    if (root == NULL) {
        return;
    }

    queue<node *> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            node *a = q.front();
            q.pop();
            if (i == n - 1) {
                cout << a->data << " ";
            }
            if (a->left) {
                q.push(a->left);
            }
            if (a->right) {
                q.push(a->right);
            }
        }
    }
    cout << endl;
}

bool search(node *root, int value) {
    if (root == NULL) {
        return false; // Base case: the value is not found
    }
    
    if (root->data == value) {
        return true; // Value found
    } else if (value < root->data) {
        return search(root->left, value); // Search in the left subtree
    } else {
        return search(root->right, value); // Search in the right subtree
    }
}

node * to_delete(node *root, int value) {
    if (root == NULL) {
        return NULL;
    }
    
    if (root->data < value) {
        root->right = to_delete(root->right, value);
    } else if (root->data > value) {
        root->left = to_delete(root->left, value);
    } else {
        if (root->left == NULL) {
            node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            node *temp = root->left;
            delete root;
            return temp;
        }

        node *temp1 = root->right;
        while (temp1->left != NULL) {
            temp1 = temp1->left;
        }

        root->data = temp1->data;
        root->right = to_delete(root->right, temp1->data);
    }
    return root;
}

int main() {
    BT tree(10);
    tree.root = insert(tree.root, 5);
    tree.root = insert(tree.root, 7);
    tree.root = insert(tree.root, 12);
    tree.root = insert(tree.root, 18);

    cout << "Inorder" << endl;
    tree.print_inorder();
    cout << "Postorder" << endl;
    tree.print_postorder();
    cout << "Preorder" << endl;
    tree.print_preorder();

    cout << "Printing the level order traversal" << endl;
    print_level_order(tree.root);
    sum_at_k_level(tree.root, 1);

    cout << "The count of the nodes is " << count_node(tree.root) << endl;
    cout << "The sum of the nodes is " << sum_node(tree.root) << endl;

    cout << "The max height of the binary tree is " << calculate_height(tree.root) << endl;

    cout << "The diameter of the binary tree is " << cal_diameter(tree.root) << endl;

    cout << "The tree after the sum_function is " << endl;
    sum_function(tree.root);
    print_level_order(tree.root);

    cout << "Balanced(1) or not_balanced(0) = " << isbalance(tree.root) << endl;

    // flatten_tree(tree.root);
    // cout<<"The array is given as "<<endl;
    // print_level_order(tree.root);
    cout << "Right view of the binary tree is given as " << endl;
    right_view(tree.root);
    
    cout <<"The output is "<<search(tree.root,5)<<endl<<endl;



    node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 18);

    cout << "Inorder before deletion: ";
    print_level_order(root);
    cout << endl;

    root = to_delete(root, 5); 
    cout << "Inorder after deleting 5: ";
    print_level_order(root);
    cout << endl;

    root = to_delete(root, 10);  
    cout << "Inorder after deleting 10: ";
    print_level_order(root);
    cout << endl;

    return 0;
}