#include<iostream>
using namespace std;
int main(){
    // float a= 2.3;
    char a= 'a';
    try{
        cout<<"i am finding any error in the code "<<endl;
        cout<<"Now thowing to check"<<endl;
        throw a;
    }
    catch(int ){
        cout<<"Now i am checking for the error in the code"<<endl;
            }
            catch(float){
                cout<<"Now i am doing it for the float value "<<endl;
            }
            catch(...){
                cout<<"something went wrong"<<endl;
            }
    return 0;
}