#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& a,int left,int middle,int right){
    int i=left;
    int j=middle+1;
    int *store=new int[right-left+1];
    int index=0;
    while(i<middle && j<right){
        if(a[i]<a[j]){
            store[index++]=a[i++];
        }
        else if(a[i]>a[j]){
            store[index++]=a[j++];
        }
    }
    while(i<middle){
        store[index++]=a[i++];
    }
    while(j<right){
        store[index++]=a[j++];
    }
    for(int i=0;i<right-left+1;i++){
        a[left+i]=store[i];
    }
}
void mergesort(vector<int>& a,int left,int right){
    if(left>=right) return;
    int middle=(left+right)/2;
    mergesort(a,left,middle);
    mergesort(a,middle+1,right);
    merge(a,left,middle,right);
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
    mergesort(store,0,store.size()-1);
    for(int i=0;i<store.size();i++){
        cout<<store[i]<<' ';
    }
}
