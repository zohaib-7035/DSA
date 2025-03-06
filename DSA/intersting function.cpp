#include<iostream>
using namespace std;
void intersting(){
    cout<<"I am ok are u also ok or not "<< endl;
}
int main(){
    void (*helloboy)()=intersting;
    intersting();
    helloboy();
    (*helloboy)();
    return 0;
}