#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class heap{
    public:
    int arr[100];
    int size;
    
  heap(){
      arr[size]=-1;
      size=0;
  }
    
    void insert(int a){
        size+=1;
        arr[size]=a;
        int index=size;
        while(index > 1){
            if(arr[index/2] < arr[index]){
            swap(arr[index],arr[index/2]);
            index=index/2;
        } 
      
        
    else{
        return ;
    }
        }
    }
    void print(){
        cout<<"The heap is given as "<<endl;
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        
    }
    
    
    void deletion(){
        if(size == 0){
            cout<<"Nothing to delete"<<endl;
            return ;
    }
    arr[1]=arr[size];
    size--;
        int i=1;
        while(i < size){
            int left= i*2;
            int right = i*2 + 1;
            if(left <= size and arr[left] > arr[i]){
                swap(arr[left],arr[i]);
                i=left;
            }
            else if(right <= size and arr[right] > arr[i]){
                swap(arr[right],arr[i]);
                i=right;
            }
            else{
                return ;
            }
        }
    }
};


// void heapify(vector<int> & arr , int n , int i){
//     int largest=i;
//     int left=i*2;
//     int right=2*i+1;
//     if(left < n and arr[left] > arr[largest]){
//         largest=left;
//     }
//     else  if(right < n and arr[right] > arr[largest]){
//         largest=right;
//     }
    
    
//     if(largest != i){
//         swap(arr[largest],arr[i]);
//         heapify(arr,n,largest);
//     }
// }


int Kth_smallest_element(int arr[],int n,int k){
    
    priority_queue<int> q;
    for(int i=0;i<n;i++){
        q.push(arr[i]);
    }
    
    for(int i=k;i<=n;i++){
        if(arr[i] < q.top()){
            q.pop();
            q.push(arr[i]);
        }
    }
    int ans=q.top();
    return ans;
}


void heapify(vector<int> & arr , int n , int i){
    int largest=i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n and arr[left] > arr[largest]){
        largest=left;
    }
    else  if(right < n and arr[right] > arr[largest]){
        largest=right;
    }
    
    
    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}


vector <int> merge_2B_heap(vector<int> v1,vector<int> v2){
    
    vector<int> ans;
    for(auto i:v1){
        ans.push_back(i);
    }
    for(auto i:v2){
        ans.push_back(i);
    }
    int n = ans.size();
    for (int i = (n / 2) - 1; i >= 0; i--) {      
    heapify(ans, n, i);
    }
return ans;
}

void printHeap(const vector<int>& heap) {
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;
}
int main(){
    
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    
    h.deletion();
    h.print();
    
    //Heapify
    // int arr[]={-1,54,53,55,52,50};
    // int n=5;
    // for(int i=n/2;i>0;i--){
    // heapify(arr,5,i);
    // }
    // cout<<"The output after heapify "<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    
    // int arr1[]={7,10,4,20,15};
    // cout<<"The kth samllest element is "<< Kth_smallest_element(arr1,5,4)<<endl;;
    
    
    
    vector<int> heap1 = {10, 7, 5, 3};
    vector<int> heap2 = {20, 15, 8, 4};

    vector<int> mergedHeap = merge_2B_heap(heap1, heap2);

    cout << "Merged Heap: ";
    printHeap(mergedHeap);
    
    return 0;
}