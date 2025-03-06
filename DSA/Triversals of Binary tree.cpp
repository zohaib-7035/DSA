#include<iostream>
using namespace std;
struct node {
  int data;
 struct node *left;
 struct node *right;
  node(int value){
      data=value;
      left=NULL;
      right=NULL;
  }
  void preorder(node *root){
      if(root==NULL){
          return ;
      }
      cout<<root->data<<" ";
      preorder(root->left);
      preorder(root->right);
      
      
      
  }
  void inorder(node * root){
      if (root==NULL){
          return ;
      }
      inorder(root->left);
      cout<<root->data<<" ";
      inorder(root->right);
  }
  
  void postorder(node * root){
      if (root==NULL){
          return ;
      }
      postorder(root->left);
      postorder(root->right);
            cout<<root->data<<" ";

  }
  
};
int main(){
   struct node *tree=new node(1);
    tree->right=new node(3);
    tree->left=new node (2);
    tree->right->right=new node(7);
    tree->right->left=new node(6);
    tree->left->left=new node (4);
    tree->left->right=new node (5);
    tree->preorder(tree);
    cout<<endl;
        tree->inorder(tree);
    cout<<endl;
        tree->postorder(tree);
    return 0;
}