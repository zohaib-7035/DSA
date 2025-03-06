//Type of polymosphism
// 1.compile time polymosphism
//(1)function overloading
//(2)operator overloading
//2.rum time polymosphism
//(1)virtual function
#include<iostream>
using namespace std;
class Animal{
    public:
     virtual void speak(){
        cout<<"Speaking  "<<endl;
    }
  
    
};
class Dog :public Animal{
    public:
    void speak(){
        cout<<"Barking"<<endl;
    }
    void hello(){
        cout<<"Hello Zohaib"<<endl;
    }
};
int main(){
   Dog one ;
   Animal* two=& one;
   two->speak();
   one.speak();
   //agr hum virtual hata den base class se to ye base function hi call kare ga 
   
   //two->hello(); 
   //ye nai ho kio ke base yani animal ka dog wala 
   //part ni hia is liye in short ye base ka hai is liye bhi
   
    return 0;
}