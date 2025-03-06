#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int,greater<int>>s;//It is used to putting value in set in decsending order
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
for(auto i:s){
    cout<<i<<endl;
}
cout<<"2nd way to print is given below "<<endl;
for(auto i=s.begin();i!=s.end();i++){
    cout<<*i<<endl;
}
cout<<"Opposite printint of the set is given below "<<endl;
for(auto i=s.rbegin();i!=s.rend();i++){
    cout<<*i<<endl;
}
set<int>st;//It is used to putting value in set in decsending order
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(4);
    st.insert(5);
cout<<"The output for the lower and the upper bound "<<endl;
cout<<*st.lower_bound(0)<<endl;//It return the element that is greater and equal to the '0'
cout<<*st.lower_bound(3)<<endl;
cout<<*st.upper_bound(0)<<endl;//It return the element that is first greater in the set
cout<<*st.upper_bound(1)<<endl;
cout<<*st.upper_bound(5)<<endl;

st.erase(1);
st.erase(st.begin());
cout<<"The output after the erasing is given below "<<endl;
for(auto i:st){
    cout<<i<<endl;
}
cout<<"The size of the set is given as "<<st.size()<<endl;
return 0;
}