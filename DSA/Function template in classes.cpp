#include<iostream>
using namespace std;
template<class t1,class t2>
class grade{
    public:
    t1 a;
    t2 b;
  public:
  
  void average(){
      t2 avg=(a+b)/2;
      cout<<"The average is "<<avg<<endl;
  }
  
};
int main(){
    grade <int ,float> A;
    A.a=10;
    A.b=21;
    A.average();
    return 0;
}