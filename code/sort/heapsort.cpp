#include <iostream>
#include <vector>
using namespace std;
void adjust(vector<int>& a,int len,int index){
    int left=index+1;
    int right=index+2;
    int max=index;
    if(left<len && a[left]>a[max]) max=left;
    if(right<len && a[right]>a[max]) max=right;
    if(max!=index){
        swap(a[max],a[index]);
        adjust(a,len,max);
    }
}
void heapsort(vector<int>& a,int size){
    for(int i=size/2-1;i>=0;i--){
        adjust(a,size,i);
    }//O(N)
    for(int i=size-1;i>=0;i--){
        swap(a[0],a[i]);
        adjust(a,i,0);
    }//O(NlogN)
}
int main(){
    int n;
    cin>>n;
    int num;
    vector<int> store;
    for(int i=0;i<n;i++){
        cin>>num;
        store.push_back(num);
    }
    heapsort(store,store.size());
    for(int i=0;i<store.size();i++){
        cout<<store[i]<<' ';
    }
}
