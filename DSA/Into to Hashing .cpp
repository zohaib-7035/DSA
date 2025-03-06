#include<iostream>
#include<string>
#include<map>
#include<unordered_map>
#include<vector>
#include <climits>
using namespace std;


int max_freq(vector<int> v, int n) {
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++) {
        m[v[i]]++;
    }

    int index = 0;
    int maxi = INT_MIN;
    for (auto i : m) {
        if (i.second > maxi) {
            maxi = i.second;
            index = i.first;
        }
    }

    return index;
}

int main(){
    
    unordered_map<string,int> m;
    
    pair<string,int> p1=make_pair("zohaib",3);
    
    m.insert(p1);
    
      pair<string,int> p2("shahid",5);
      
      m.insert(p2);
    
    cout << m["zohaib"] << endl;
    cout << m["shahid"] << endl;
    
    m.insert(p2);
    
  m["zohaib"]=6;
  m["shahid"]=7;
  
  cout << m["zohaib"] << endl;
    cout << m["shahid"] << endl;
    cout<<"It will be zero for the given below "<<endl;
    cout<<m["Muhammad"]<<endl;
    
    cout<<"Size is given as "<<m.size()<<endl;
    
    
    cout<<"to check the presence fo the particular key "<<m.count("hi")<<endl;
    cout<<"For zohaib "<<m.count("zohaib")<<endl;
    
    
    cout<<"To traverese the map "<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    
    
    
    vector<int> v = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};  
    int n = v.size();

    int result = max_freq(v, n);
    cout << "The element with the highest frequency is: " << result << endl;
    return 0;
}