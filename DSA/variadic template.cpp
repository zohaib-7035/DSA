#include<iostream>
using namespace std;
template<typename t>
void func(t a){
    cout<<"The value is given as "<<a<<endl;
}
template<typename t,typename... args>
void func(t a, args... b){
    cout<<"2nd function "<<a<<endl;
    func(b...);
}
int main(){
    int a;
    cin >>a ;
    func(a);
    // for the last it will use the first func
    func(1,2,3.4,5.5,"zohaib");
        func(1,2,3.4,5.5,2);

    return 0;
}