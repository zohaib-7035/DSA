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
        node *tree = a.front(); 
        a.pop();
        cout << tree->data << " ";
        
        if (tree->left) { 
            a.push(tree->left);
        }
        
        if (tree->right) {
            a.push(tree->right);
        }
    }
}


int sumatknode(node *root,int k){
    if(root==NULL){
        return -1;
    }
    queue <node *>a;
    a.push(root);
    int l=0;
    int sum=0;
    while(!a.empty()){
        int s=a.size();
        for(int i=0;i<s;i++){
            node *tree=a.front();
            a.pop();
            if(l==k){
                sum+=tree->data;
            }
            
            
            
             
        if (tree->left) { 
            a.push(tree->left);
        }
        
        if (tree->right) {
            a.push(tree->right);
        }
        }
        l++;
    }
    return sum;
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
    cout<<endl;
    cout<<"The sum at the kth node is "<<endl;
    cout<<sumatknode(tree,2)<<endl;
    return 0;
}