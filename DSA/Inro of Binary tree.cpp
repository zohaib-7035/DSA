#include<iostream>
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

// Helper function to insert left and right children
void insertLeft(node* parent, int value) {
    parent->left = new node(value);
}

void insertRight(node* parent, int value) {
    parent->right = new node(value);
}

int main() {
    // Creating the root node of the tree
    node *tree = new node(1);

    // Inserting nodes using helper functions
    insertLeft(tree, 3);           // Left child of root (3)
    insertRight(tree, 2);          // Right child of root (2)

    insertLeft(tree->left, 4);     // Left child of node 3 (4)
    insertRight(tree->left, 5);    // Right child of node 3 (5)

    insertLeft(tree->right, 6);    // Left child of node 2 (6)
    insertRight(tree->right, 7);   // Right child of node 2 (7)

    return 0;
}
