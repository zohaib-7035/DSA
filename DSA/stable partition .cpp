#include <iostream>
#include <algorithm> // For std::sort
#include<vector>
using namespace std;

int main() {
    vector <int> inty= {1, 2,3,4,5,6,7,8,9,10}; // Initialize array with 6 elements
for(int n:inty){
    cout<<n<<" ";
}
cout<<endl;
//partition(inty.begin(),inty.end(),[](auto x){return x%2==0;});
stable_partition(inty.begin(),inty.end(),[](auto x){return x%2==0;});
//it make the partition of the code that matches and donot matches

for(int n:inty){
    cout<<n<<" ";
}
cout<<endl;
    return 0;
}
