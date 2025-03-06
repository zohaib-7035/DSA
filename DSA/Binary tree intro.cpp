#include <iostream>
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

class BST {
public:
    node *root;
    
    BST() {
        root = NULL;
    }
    
    BST(int value) {
        root = new node(value);
    }
    
    node* insert(node *curr, int value) {
        if (curr == NULL) {
            return new node(value);
        }
        if (value < curr->data) {
            curr->left = insert(curr->left, value);
        } else {
            curr->right = insert(curr->right, value);
        }
        return curr;
    }
};

void inorder(node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";

}
int main() {
    BST tree(5);
    tree.root = tree.insert(tree.root, 6);
    tree.root = tree.insert(tree.root, 3);
    tree.root = tree.insert(tree.root, 8);
    tree.root = tree.insert(tree.root, 4);
    tree.root = tree.insert(tree.root, 2);
    tree.root = tree.insert(tree.root, 1);
    
    cout<<"The output for the inorder"<<endl;
    inorder(tree.root);
   
    cout<<endl<<"The output for the preorder"<<endl;
    preorder(tree.root);
    
    cout<<endl<<"The output for the postorder"<<endl;
    postorder(tree.root);
    return 0;
}
