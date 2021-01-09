#include <iostream>
#include <vector>
using namespace std;
void bubblesort(vector<int>& a){
    for(int i=0;i<a.size()-1;i++){
        for(int j=0;j<a.size()-i-1;j++){
            if(a[j]>a[j+1]) swap(a[j+1],a[j]);
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
    bubblesort(store);
    for(int i=0;i<store.size();i++){
        cout<<store[i]<<' ';
    }
}
