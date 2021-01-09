#include <iostream>
#include <vector>
using namespace std;
void zerosort(vector<int>& a){
    int k=0;
    int i=0;
    while(i<a.size()){
        if(a[i]!=0){
            swap(a[i],a[k]);
            k++;
        }
        i++;
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
    zerosort(store);
    for(int i=0;i<store.size();i++){
        cout<<store[i]<<' ';
    }
}
