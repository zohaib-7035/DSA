#include<iostream>
#include<vector>
using namespace std;
struct corners{
    int a,b,c,d;
   friend ostream &operator<<(ostream &out, const corners &corner) {
        out << "The value of the corners is given below:\n";
        out << "a: " << corner.a << " ";
        out << "b: " << corner.b << " ";
        out << "c: " << corner.c << " ";
        out << "d: " << corner.d << "\n";
        return out;
    }
};
int main(){
    vector<int> inty ;
    inty.push_back(1);
        inty.push_back(2);
    inty.push_back(3);
    inty.push_back(4);
    inty.push_back(5);
    cout<<"First method to access it "<<endl;
for(auto i=inty.begin();i!=inty.end();i++){
    cout<<*i<<endl;
}
cout<<"Second method to access it"<<endl;
for(auto i=0;i!=inty.size();i++){
    cout<<inty[i]<<endl;
}


vector<corners> s1{{1,2,3,4}};
 s1.push_back({5,6,7,8});
for(auto i=0;i<s1.size();i++){
    cout<<s1[i];
}





    return 0;
}