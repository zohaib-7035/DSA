#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main(){
    //unordered_map<int,int> m;  for int and int 
    
    unordered_map<string,int> m;
    
    
    pair<string,int> p1=make_pair("mera",1);
    m.insert(p1);
    
    pair<string,int> p2("name",3);
    m.insert(p2);
    
     m["zohaib"]=1;
     
     cout<<m["zohaib"]<<endl;
     
         m["zohaib"]=2;
              cout<<m["zohaib"]<<endl;

         cout<<m.at("name")<<endl;
         //  cout<<m.at("hai")<<endl;  It will give the error as it does not exsits but can use the following statment
               
    cout<<m["hai"]<<"<<<>>>"<<endl; //will give 0 as it is not exsited in the map but has created its corner at with exsitence 0 time
     
    cout<<m.at("hai")<<endl;//now it is allowed and give the 0
     
     cout<<m.size()<<endl;
     
     cout<<m.count("shahid")<<endl;
     cout<<m.count("zohaib")<<endl;// it will give the bool for checking the presence by 1 or 0

     
     m.erase("zohaib");
          cout<<m.size()<<endl;//it will erease the zohaib
    m["zohaib"]=2;
    
           cout<<m.size()<<endl;   
           
           
           cout<<"The printing for the first way is given below "<<endl;
           for(auto i:m){
               cout<<i.first<<" "<<i.second<<endl;
           }
           cout<<"Printing by the second way is given below "<<endl;
           //printing by the iterator is given below 
           unordered_map<string,int> ::iterator it = m.begin();
           while(it != m.end()){
               cout<<it->first<<" "<<it->second<<endl;
               it++;
           }
           //it is not in the order in which it is created so if we want to do that then we will make map
           //by replacing unordered_map by the map then it will print in creating order
           
           
           
           
           
           
           
           
           
           
           
           
           

    return 0;
}