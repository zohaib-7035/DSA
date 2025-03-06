#include<iostream>
using namespace std;
class Human{
  public:
  void speaking(){
      cout<<"Speaking "<<endl;
  }

};
  class Male{
      public:
      void walking(){
          cout<<"Walking"<<endl;
      }
  };
  class boy:public Male,public Human{
    public:
    void playing(){
        cout<<"Playing"<<endl;
    }
  };
int main(){
   boy ali;
   ali.walking();
   ali.speaking();
   ali.playing();
    return 0;
}
