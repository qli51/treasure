#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    string b;
    cin>>a>>b;
    int n=a.size();
    int m=b.size();
    int *store[n+1];
    for(int i=0;i<n+1;i++){
        store[i]=new int[m+1];
    }
    for(int i=0;i<=n;i++){
        store[i][0]=i;
    }
    for(int i=0;i<=m;i++){
        store[0][i]=i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i]==b[j]) store[i+1][j+1]=store[i][j];
            else{
                store[i+1][j+1]=store[i][j]+1;
                store[i+1][j+1]=min(store[i+1][j+1],store[i][j+1]+1);
                store[i+1][j+1]=min(store[i+1][j+1],store[i+1][j]+1);
            }
        }
    }
    cout<<store[n][m];
    
}