//Type of polymosphism
// 1.compile time polymosphism
//(1)function overloading
//(2)operator overloading
//2.rum time polymosphism
//(1)virtual function
#include<iostream>
using namespace std;
class A{
    public:
    void speak(){
        cout<<"Speaking 1 "<<endl;
    }
   void speak(int a){
        cout<<"Speaking 2"<<endl;
    }
     void speak(double a){
        cout<<"Speaking 3 "<<endl;
    }
};
int main(){
    A ali;
    ali.speak();
    ali.speak(1);
    ali.speak(2.4);
    return 0;
}