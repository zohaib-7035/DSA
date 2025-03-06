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
};
int main(){
   struct node *tree=new node(1);
    tree->right=new node(2);
    tree->left=new node (3);
    tree->right->right=new node(7);
    tree->right->left=new node(6);
    tree->left->left=new node (4);
    tree->left->right=new node (5);
    return 0;
}