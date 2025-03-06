#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue <int> pq;
    pq.push(3);
    pq.push(2);
    pq.push(7);
    pq.push(5);
    pq.push(6);
  cout<<"The top most node is given as "<<pq.top()<<endl;
  pq.pop();
    cout<<"Now the top most node is given as "<<pq.top()<<endl;
cout<<"The size of the pq is given as "<<pq.size()<<endl;//as first element will be the -1 so it giving the 4
if(pq.empty()){
    cout<<"Pq is NULL"<<endl;
}
else{
    cout<<"Pq is not NULL"<<endl;
}
cout<<endl<<endl<<endl<<endl;

//for min-heap

 priority_queue < int , vector<int> ,greater<int> > p;
    p.push(3);
    p.push(2);
    p.push(7);
    p.push(5);
    p.push(6);
  cout<<"The top most node is given as "<<p.top()<<endl;
  p.pop();
    cout<<"Now the top most node is given as "<<p.top()<<endl;
cout<<"The size of the p is given as "<<p.size()<<endl;//as first element will be the -1 so it giving the 4
if(p.empty()){
    cout<<"P is NULL"<<endl;
}
else{
    cout<<"P is not NULL"<<endl;
}

    return 0;
}