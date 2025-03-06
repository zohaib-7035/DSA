#include<iostream>
#include<fstream>
using namespace std;

int main(){
    // string out1="I love you";
    // ofstream out("Out.txt");
    // out<<out1;
    
    ifstream IN("Out.txt");
    string IN1;
    // IN>>IN1;
    getline(IN,IN1); 
        cout<<IN1<<endl;
      getline(IN,IN1);
    cout<<IN1<<endl;
    return 0;
}