#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct node {
    int data;
    node *left;
    node *right;
    
    node(int value) : data(value), left(NULL), right(NULL) {}
};

node *buildtreefromstack(stack<int>& st) {  
    if(st.empty()) {
        return NULL;
    }
    int value = st.top();
    st.pop();
    node *root = new node(value);
    root->right = buildtreefromstack(st);
    root->left = buildtreefromstack(st);
    return root;
}

void orderwisetraversal(node *root) {
    if(root == NULL) {
        return;
    }
    
    queue<node *> q;
    q.push(root);
    while(!q.empty()) {
        node *tree = q.front();
        q.pop();
        cout << tree->data << " ";
        
        if(tree->left) {
            q.push(tree->left);
        }
        if(tree->right) {
            q.push(tree->right);
        }
    }
    cout << endl;
}

stack<int> puttreeinstack(node *root) {
    stack<int> st;
    if(root == NULL) {
        return st;
    }

    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node *tree = q.front();
        q.pop();
        st.push(tree->data);
        
         if(tree->left) {
            q.push(tree->left);
        }
        if(tree->right) {  
            q.push(tree->right);
        }
       
    }
    return st;
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    stack<int> st = puttreeinstack(root);

    node *reversedRoot = buildtreefromstack(st);

    cout << "Level order traversal of the reversed tree: " << endl;
    orderwisetraversal(reversedRoot);

    return 0;
}

