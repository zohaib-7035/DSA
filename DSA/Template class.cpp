#include<iostream>
using namespace std;
template <class T>
class vector {
  public:
  T * arr;
  int size;
  void displayinfo(){
      cout<<"The size is "<<size <<endl;
      for(int i=0;i<size;i++){
          cout<<arr[i]<<endl;
      }
  }
  vector(T *a,T s){
      arr=a;
      size=s;
  }
  vector(){
      size =0;
      arr=0;
  }
};
int main(){
    int arr[]={1,2,3,4,5};
    vector <int>myarr(arr,5);
    myarr.displayinfo();
    char name[]="ali";
    vector<char> myname(name,3);
    myname.displayinfo();
    return 0;
}