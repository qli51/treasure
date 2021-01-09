#include <iostream>
#include <vector>
using namespace std;
void selectsort(vector<int>& a){
    for(int i=0;i<a.size()-1;i++){
        for(int j=i+1;j<a.size();j++){
            if(a[j]<a[i]) swap(a[i],a[j]);
        }
    }
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
    selectsort(store);
    for(int i=0;i<store.size();i++){
        cout<<store[i]<<' ';
    }
}
