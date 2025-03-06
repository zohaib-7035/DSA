#include<iostream>
#include<map>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class Graph{
  public:
  unordered_map<int,list<int>> adj;
  
  
  void insert(int u, int v ,bool d){
      adj[u].push_back(v);
      if(d==0){
          adj[v].push_back(u);
      }
  }
  
  
  void print(){
      for(auto i: adj){
          cout<<i.first<<" -> ";
          for(auto j:i.second){
              cout<<j<<" ";
          }
          cout<<endl;
      }
  }
  
  
  void BFS(int start){
      unordered_map<int,bool> visited;
      queue<int> q;
      q.push(start);
      visited[start]=true;
      
      while(!q.empty()){
          
          int _front=q.front();
          q.pop();
          cout<<_front<<" ";
          
          for(auto i: adj[_front]){
              if(visited[i]!=true){
                  q.push(i);
                  visited[i]=true;
              }
          }
          
      }
      cout<<endl;
  }
  
  void helper(int start,unordered_map<int,bool> &visited){
      
      visited[start]=true;
      cout<<start<<" ";
      for(auto i: adj[start] ){
          if(!visited[i]){
              helper(i,visited);
          }
      }
      
  }
  
  void DFS(int start){
      unordered_map<int,bool> visited;
      helper(start,visited);
      cout<<endl;
  }
  
  
};
int main() {
    Graph g;

    g.insert(0, 1, 0);
    g.insert(0, 2, 0);
    g.insert(1, 2, 0);
    g.insert(2, 3, 0);
    g.insert(3, 4, 0);



    cout << "Graph Adjacency List:" << endl;
    g.print();


   cout << "BFS Traversal starting from node 0:" << endl;
    g.BFS(0);
    
    
   cout << "DFS Traversal starting from node 0:" << endl;
    g.DFS(0);
    
    return 0;
}