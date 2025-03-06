#include<iostream>
using namespace std;
#define end return 0
void intersting(){
    cout<<"I am ok are u also ok or not "<< endl;
}
int main(){
    void (*helloboy)()=intersting;
    intersting();
    helloboy();
    (*helloboy)();
    end;
}