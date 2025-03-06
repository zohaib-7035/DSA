#include<iostream>
using namespace std;
class Human{
  public:
  void speaking(){
      cout<<"Speaking "<<endl;
  }

};
  class Male: public Human{
      public:
      void walking(){
          cout<<"Walking"<<endl;
      }
  };
int main(){
    Male ali;
    ali.walking();
    ali.speaking();
    return 0;
}
