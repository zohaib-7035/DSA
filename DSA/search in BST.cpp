#include<iostream>
#include<queue>
#include<limits.h>
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

int count(node * root){
    if(root==NULL){
        return 0;
    }
    
    int c=0;
    queue<node *>a;
    a.push(root);
    while(!a.empty()){
        node *tree=a.front();
        a.pop();
        if(tree){
            c++;
        }
        if(tree->left){
            a.push(tree->left);
        }
        
        if(tree->right){
            a.push(tree->right);
        }
    }
    return c;
}

int countNode(node * n){
    if(n==NULL){
        return 0;
    }
    return countNode(n->left)+countNode(n->right)+1;
}


int sumofallnode(node *root){
    if(root==NULL){
        return 0;
    }
    return sumofallnode(root->left)+sumofallnode(root->right)+root->data;
}

int calculateheight(node * root){
    if(root==NULL){
        return 0;
    }
    
    int l=calculateheight(root->left);
    int r=calculateheight(root->right);
    return  max(l,r) + 1;
    
    
    
}



int calculatediameter(node *root){
    if(root==NULL){
        return 0;
    }
    int LH=calculateheight(root->left);
    int RH=calculateheight(root->right);
    int CD=LH+RH+1;
    int LD=calculatediameter(root->left);
    int RD=calculatediameter(root->right);

    return max(CD,max(LD,RD));
}



void sumreplacment(node *root){
    
    if(root==NULL){
        return ;
    }
    sumreplacment(root->left);
    sumreplacment(root->right);
    if(root->left){
    root->data=root->data + root->left->data ;
    }
    
    if(root->right){
    root->data=root->data + root->right->data ;
    }
    
}


bool isbalanced(node *root){
    if(root==NULL){
        return true;
    }
    
   
    
    int LH=calculateheight(root->left);
    int RH=calculateheight(root->right);
    if(abs(LH-RH) > 1){
        return false;
    }
    
    return  isbalanced(root->left) && isbalanced(root->right);


}



void checkrightveiw(node *root){
    if(root==NULL){
        return;
    }
    
    queue<node *>  q;   
    q.push(root);
    while(!q.empty()){
        int s=q.size();
        for(int i=0;i<s;i++){
            node *curr=q.front();
            q.pop();
            if(i==s-1){
                cout<<curr->data<<" ";
            }
            if(curr->left){
                q.push(curr->left);
            }
            
            if(curr->right ){
                q.push(curr->right);
            }
            
        }
    }
    
    
}

void checkleftview(node *root ){
    if(root==NULL){
        return;
    }
    
    queue<node *>  q;   
    q.push(root);
    while(!q.empty()){
        int s=q.size();
        for(int i=0;i<s;i++){
            node *curr=q.front();
            q.pop();
            if(i==0){
                cout<<curr->data<<" ";
            }
            if(curr->left){
                q.push(curr->left);
            }
            
            if(curr->right){
                q.push(curr->right);
            }
            
        }
    }
    
    
}
void flatten(node *&root){
    
    
    if(root==NULL){
        return ;
    }
    flatten(root->left);
    flatten(root->right);
    if(root->left){
        node * temp=root->right;
        root->right=root->left;
        root->left=NULL;
        node * curr=root->right;
        while(curr->right){
            curr=curr->right;
        }
        curr->right=temp;
    }
}

node * insertBST(node *root , int value){
    if (root==NULL){
        return new node(value);
    }
    if(root->data > value){
        root->left=insertBST(root->left,value);
    }
    else if(root->data < value){
        root->right=insertBST(root->right,value);
    }
    return root;
    
    
}

node * searchinBST(node * root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    if(root->data > key){
        return searchinBST(root->left,key);
    }
      if(root->data < key){
        return searchinBST(root->right,key);
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
    cout<<endl;
    cout<<"The sum at the kth node is "<<endl;
    cout<<sumatknode(tree,2)<<endl;
    cout<<"The count of the node is given as  "<<countNode(tree)<<endl;
    cout<<"The count of the node without a recursive function is "<<count(tree)<<endl;
    
    
    cout<<"The sum of all the node is "<<sumofallnode(tree)<<endl<<endl;
    
    
    cout<<"The maximum height of the binary tree is "<<calculateheight(tree)<<endl;
    
    cout<<"The maximum of diameter in this tree is "<<calculatediameter(tree)<<endl;
    
    sumreplacment(tree);

    cout << "Binary tree after sum replacement is: " << endl;
    levelordertrivesal(tree);
    cout << endl;
    
    cout<<"The answer for the isbalanced is given as "<<isbalanced(tree)<<endl;
    
   
    
     node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    
    
     cout<<"The values for the right veiw of the binary tree is "<<endl;
    checkrightveiw(root);
    cout<<endl;
    
    cout<<"The value of the left view of the binary tree is "<<endl;
    checkleftview(root);
    cout<<endl;
     node* r = new node(1);
    r->left = new node(2);
    r->right = new node(5);
    r->left->left = new node(3);
    r->left->right = new node(4);
    r->right->right = new node(6);
    
    flatten(r);
    cout<<"The value of the flatten binary tree "<<endl;
    preorderTraversal(r);
    cout<<endl;
    
    
    node* root2 = NULL;

    // Inserting nodes into the BST
    root2 = insertBST(root2, 50);
    insertBST(root2, 30);
    insertBST(root2, 20);
    insertBST(root2, 40);
    insertBST(root2, 70);
    insertBST(root2, 60);
    insertBST(root2, 80);

    cout << "In-order traversal of the BST: ";
    inorderTraversal(root2);
    cout << endl;

   cout<<"The output for the searchinBST is "<<endl;
   node *a=searchinBST(root2,70);
   cout<<a->data<<" "<<endl;
   
   
   
    return 0;
}