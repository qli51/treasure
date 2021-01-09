#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> store;
void perm(string a,int i){
    if(i==a.size()-1){
        store.push_back(a);
        return;
    }
    for(int t=i;t<a.size();t++){
        if(t==i || a[t]!=a[i]){
            swap(a[i],a[t]);
            perm(a,i+1);
            swap(a[i],a[t]);
        }
    }
}
int main(){
    string a="123";
    perm(a,0);
    for(int i=0;i<store.size();i++){
        cout<<store[i]<<endl;
    }
}

