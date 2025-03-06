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

int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

node *buildtree(int postorder[],int inorder[],int start, int end){
    static int i=4;
    if(start>end){
        return NULL;
    }
    int curr=postorder[i];
    i--;
    node * tree=new node(curr);
    if(start==end){
        return tree;
    }
    int pos=search(inorder,start,end,curr);
    tree ->  right =  buildtree( postorder, inorder,pos + 1, end);// we write for right first bcz in 
    //postorder from last right node come first instead of the left
    tree -> left = buildtree( postorder, inorder,start, pos - 1);

    
    return tree;
    
}
void print_inorder(node *tree){
    if(tree==NULL){
        return ;
    }
    print_inorder(tree->left);
    cout<<tree->data<<" ";
    print_inorder(tree->right);
    
    
}
int main(){
   int postorder[]={1,2,4,3,5};
   int inorder[]={4,2,1,5,3};
   node *tree=buildtree(postorder,inorder,0,4);
   
   print_inorder(tree);
    return 0;
}