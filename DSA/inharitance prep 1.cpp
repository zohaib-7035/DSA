#include<iostream>
using namespace std;
class shape {
  public:
   virtual void display(){
      cout <<"Shape "<<endl;
  }
   float getarea(){
      return 0.0f;
  }
};
 class rectangle :public shape{
      int length;
      int height;
      public:
      rectangle(int l,int w){
          length=l;
          height=w;
      }
      void display(){
          cout<<"Area is "<<length*height<<endl;
      }
      int getarea(){
          return length*height;
      }
  };
  class circle:public shape{
      int radius;
      public:
      circle(int a){
          radius=a;
      }
      void display(){
          cout<<"The area of circle is "<<3.14*radius*radius<<endl;
      }
      float getarea(){
          return 3.14*radius*radius;
      }
  };
int main(){
    shape * s[2] ;
        s[0]=new rectangle(5,5);
       s[1]=new circle(1);
       for(int i=0;i<2;i++){
           s[i]->display();
           s[i]->getarea();
       }
       
         for(int i = 0; i < 2; i++) {
        delete s[i];
    }
    
    return 0;
}
