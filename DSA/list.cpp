#include <iostream>
#include <algorithm> // For std::sort
#include<vector>
#include<list>
using namespace std;

int main() {
list <int> inty;
for(int i=0;i<10;i++){
    inty.push_back(i);
}
cout<<inty.front()<<endl<<endl;

cout<<inty.back()<<endl;

inty.pop_back();
inty.pop_front();
cout<<endl<<endl;
for(int i:inty){
    cout<<i<<endl;
}

cout<<endl;
inty.reverse();
for(int i:inty){
    cout<<i<<endl;
}

cout<<endl;

inty.sort();
for(int i:inty){
    cout<<i<<endl;
}



    return 0;
}
