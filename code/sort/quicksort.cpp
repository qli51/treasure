#include <iostream>
#include <vector>
using namespace std;
void quicksort(vector<int>& store,int left,int right){
    if(left>=right) return;
    int i=left;
    int j=right;
    int temp=store[left];
    while(i<j){
        while(i<j && store[j]>temp){
            j--;
        }
        if(i<j){
            store[i]=store[j];
            i++;
        }
        while(i<j && store[i]<temp){
            i++;
        }
        if(i<j){
            store[j]=store[i];
            j--;
        }
    }
    store[i]=temp;
    quicksort(store,left,i-1);
    quicksort(store,i+1,right);
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
    quicksort(store,0,store.size()-1);
    for(int i=0;i<store.size();i++){
        cout<<store[i]<<' ';
    }
}
