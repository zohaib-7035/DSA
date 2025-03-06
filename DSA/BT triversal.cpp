#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;
    node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};

class BT{
    public:
    node *root;
    
    
    //constructor
    BT(int value){
        root=new node(value);
    }
    
    
    
    void insert(int value){
        insert_helper(root , value);
     
    }
    
    void insert_helper(node *& curr,int value){
        if(curr==NULL){
            curr=new node(value);
          return ;
        }
        if(curr->data > value){
            insert_helper(curr->left , value); 
        }
        else{
            insert_helper(curr->right , value);
        }
    }
    
    
    
    void print_inorder(){
        inorder(root);
        cout<<endl;
    }
    
    void inorder(node *curr){
        if(curr==NULL){
            return;
        }
        inorder(curr->left);
        cout<<curr->data<<" ";
        inorder(curr->right);
        
        
    }
    
    void print_preorder(){
        preorder(root);
        cout<<endl;
        return;
    }
    
     void preorder(node *curr){
        if(curr==NULL){
            return;
        }       
        cout<<curr->data<<" ";
        preorder(curr->left);
        preorder(curr->right);

    }
    
    
     void print_postorder(){
        postorder(root);
        cout<<endl;
        return;
    }
    
     void postorder(node *curr){
        if(curr==NULL){
            return;
        }       
        postorder(curr->left);
        postorder(curr->right);
        cout<<curr->data<<" ";

    }
    
};
int main(){
    
     BT tree(10);        
    tree.insert(5);    
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);
    cout<<"Inorder"<<endl;
    tree.print_inorder();
    cout<<"Postorder"<<endl;
    tree.print_postorder(); 
    cout<<"Preorder"<<endl;
    tree.print_preorder();
    
    return 0;
}