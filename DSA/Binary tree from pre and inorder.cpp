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

node *buildtree(int preorder[],int inorder[],int start, int end){
    static int i=0;
    if(start>end){
        return NULL;
    }
    int curr=preorder[i];
    i++;
    node * tree=new node(curr);
    if(start==end){
        return tree;
    }
    int pos=search(inorder,start,end,curr);
   tree -> left = buildtree( preorder, inorder,start, pos - 1);
    tree ->  right =  buildtree( preorder, inorder,pos + 1, end);

    
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
   int preorder[]={1,2,4,3,5};
   int inorder[]={4,2,1,5,3};
   node *tree=buildtree(preorder,inorder,0,4);
   
   print_inorder(tree);
    return 0;
}