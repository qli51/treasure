#include <iostream>
#include <vector>
using namespace std;
int count(string a,int *b[],int n){
    if(n==0) return 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            b[i][j]=0;
        }
    }
    int res=0;
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(a[i]==a[j] && (j-i<=2 || b[i+1][j-1]==1)){
                b[i][j]=1;
            }
            if(b[i][j]){
                res++;               
            }
        }
    }
    return res;    
}
int main(){
    string a;
    cin>>a;
    int n=a.size();
    int *b[n+1];
    for(int i=0;i<n+1;i++){
        b[i]=new int[n+1];
    }
    int res=count(a,b,n);
    cout<<res;
}