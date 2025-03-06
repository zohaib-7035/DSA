#include<iostream>
#include <utility> 

using namespace std;
template<class t1,class t2>
class grade{
    public:
    t1 a;
    t2 b;
  public:
void swap(t1 &a, t2 &b) {
    t2 temp = a;
    a = b;
    b = temp;
    cout << "Swapped values: " << a << " and " << b << endl;
}
  void average(){
      t2 avg=(a+b)/2;
      cout<<"The average is "<<avg<<endl;
  }
  
};
int main(){
    grade <int ,float> A;
    A.a=10;
    A.b=21;
    A.swap(A.a,A.b);
    A.average();
    return 0;
}