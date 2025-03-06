#include<iostream>
using namespace std;
    template <class a,class b>
    class value{
      public:
      a name;
      b salary;
      value(a n,b m){
          name =n;
          salary=m;
      }
      void display(){
          cout<<"The name is "<<name<<endl;
          cout<<"The salary is "<<salary<<endl;
      }
    };
    
int main(){
    value <string , int> person1("Ali",50000);
    person1.display();
    cout<<endl;
    value <char ,float> person2('a',5.55);
    person2.display();
    cout<<endl;
     value <int , int> person3(900,99);
     person3.display();
    return 0;
}