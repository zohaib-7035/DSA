#include<iostream>
using namespace std;

int main(){
    
    int n,m;
    cout<<"The length of the array "<<endl;
    cin>>n>>m;
        int array[n][m];
    cout<<"Enter the value of the array "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        cin>>array[i][j];
    }
    cout<<"Your spiral matrix is given below "<<endl;
    int sr=0,er=n-1;
    int cs=0,ce=m-1;
    
    
   while(sr<=er && cs<=ce){
       
       
       for(int i=cs;i<=ce;i++){
           cout<<array[sr][i]<<" ";
       }
       sr++;
       
       
       for(int i=sr;i<=er;i++){
           cout<<array[i][ce]<<" ";
       }
       ce--;
       


       for(int i=ce;i>=cs;i--){
           cout<<array[er][i]<<" ";
       }
       er--;
          
          

       for(int i=er;i>=sr;i--){
           cout<<array[i][cs]<<" ";
       }
       cs++;
       
         
   }
       
    
    
    
    
    return 0;
}