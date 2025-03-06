#include<iostream>
using namespace std;
class A{
  public:
  void find(){
      cout<<"Found"<<endl;
  }
};
class B:public A{
    public:
    void search(){
        cout<<"Searched "<<endl;
    }
};
class C:public A{
  public:
  void locate(){
      cout<<"Located"<<endl;
  }
};
int main(){
    C c1;
    c1.find();
    c1.locate();
   // c1.search();  it is not allowed as it has no any relation with it
    B b1;
    b1.search();
    b1.find();
    return 0;
}