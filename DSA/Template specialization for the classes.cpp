#include<iostream>
using namespace std;
template<class T>
class charfinder{
    
  public:
  charfinder(T a){
      cout<<"It is not the valid one  :  "<<a<<endl;
  }
};
template<>
class charfinder<char>{
    public:
    charfinder(char a){
        cout<<"IT is the valid element  :  "<<a<<endl;
    }
};
int main(){
    charfinder <int> INTEGER(3);
    charfinder<float> FLOAT(7.6);
    charfinder<char> CHAR('z');
    
    return 0;
}