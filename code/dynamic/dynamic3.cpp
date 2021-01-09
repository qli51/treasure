#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//求最大回文子串
int process(vector<int>& a,int *c[],int n){
    if(n==0) return 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i][j]=0;
        }
    }
    for(int i=n-1;i>=0;i--){
        c[i][i]=a[i];
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                c[i][j]=c[i+1][j-1]+2*a[i];
            }
            else{
                c[i][j]=max(c[i+1][j],c[i][j-1]);
            }
        }
    }
    return c[0][n-1];
}
int main(){
    int n;
    int num;
    vector<int> a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        a.push_back(num);
    }
    int *c[n];
    for(int i=0;i<n;i++){
        c[i]=new int[n];
    }
    int res=0;
    for(int i=0;i<a.size();i++){
        res+=a[i];
    }
    int count=process(a,c,n);
    res=2*res-count;
    cout<<res;
}