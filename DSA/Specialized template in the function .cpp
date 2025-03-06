#include<iostream>
using namespace std;
template <typename T>
void print(T a){
    cout<<"The Function is the generic one  "<<endl;
}
template <>
void print<int>(int a){
    cout<<"This fucntion is only for the the int valiable "<<endl;
}
int main(){
    print(6);
    print('d');
    print("ali");
    print(4.44);
    return 0;
}
