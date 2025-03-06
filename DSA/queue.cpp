#include <iostream>
#include <algorithm> // For std::sort
#include<vector>
#include<list>
#include <queue>
using namespace std;

int main() {
    
queue<int> inty;
inty.push(10);
inty.push(20);
inty.push(30);
inty.push(40);
inty.push(50);

cout<<inty.front()<<endl;

cout<<inty.back()<<endl;

//inty.pop();  it always pop from first according to fifo

//cout<<inty.front()<<endl;


cout<<endl<<endl;
while(!inty.empty()){
    cout<<inty.front()<<endl;
    inty.pop();
}
cout<<endl<<inty.front()<<endl;//now everything has been poped


priority_queue <int> intz;
intz.push(10);
intz.push(20);
intz.push(50);
intz.push(30);
intz.push(40);


cout<<endl<<endl;
while(!intz.empty()){
    cout<<intz.top()<<endl;
    intz.pop();
}
//i dont know why this i happening as it is not removing the pri-queue as the simple queue
cout<<endl<<intz.top()<<endl;

    return 0;
}
