#include<iostream>
#include<string>
using namespace std;
int main(){
    []{cout<<"Hi,how are you\n";}();
    //it is not allowed  [](){cout<<"Hi,how are you\n";};
   //  [](){return 100;}
  //when u return something then small backets come to the middle
 
 // auto sum=[](auto a, auto b){return a+b;};
   
   auto sum=[](auto a, auto b){ cout<<"The sum is given as :"<<endl; return a+b;};
   cout <<sum(2,4)<<endl;
      cout <<sum(2.5,4.5)<<endl;
    string a="ali";
    string b="akbar";
   cout<<sum(a,b)<<endl;
    //we can also use it as 
   // cout<<sum(string("ali "),string("akbar"));
  //but we cannot do it 
 //cout<<sum("ali ","akbar");
  
  return 0;
}