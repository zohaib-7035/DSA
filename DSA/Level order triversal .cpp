#include<iostream>
#include<queue>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
    
    node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Inorder Traversal (Left, Root, Right)
void inorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Preorder Traversal (Root, Left, Right)
void preorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder Traversal (Left, Right, Root)
void postorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// Level Order Traversal
void levelordertrivesal(node *root) {
    if (root == NULL) {
        return;
    }
    queue<node *> a;
    a.push(root);
    while (!a.empty()) {
        node *tree = a.front(); // The current node being processed
        a.pop();
        cout << tree->data << " ";
        
        // Correctly access the left and right children of the current node
        if (tree->left) { 
            a.push(tree->left);
        }
        
        if (tree->right) {
            a.push(tree->right);
        }
    }
}

int main() {
    node *tree = new node(1);
    tree->left = new node(2);
    tree->right = new node(3);
    tree->left->left = new node(4);
    tree->left->right = new node(5);
    tree->right->left = new node(6);
    tree->right->right = new node(7);

    cout << "Level order traversal: " << endl;
    levelordertrivesal(tree);
    return 0;
}
