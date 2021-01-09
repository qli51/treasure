#include <iostream>
#include <vector>
using namespace std;
void insertsort(vector<int>& a){
    for(int i=1;i<a.size();i++){
        for(int j=0;j<i;j++){
            if(a[j]>a[i]) swap(a[j],a[i]);
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
    insertsort(store);
    for(int i=0;i<store.size();i++){
        cout<<store[i]<<' ';
    }
}
