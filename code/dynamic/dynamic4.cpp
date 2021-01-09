#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int LCS(string a,string b,int *c[],int *d[],int m,int n){
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            c[i][j]=0;
            d[i][j]=2;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i]==b[j]){
                c[i+1][j+1]=c[i][j]+1;
                d[i+1][j+1]=0;
            }
            else{
                c[i+1][j+1]=max(c[i+1][j],c[i][j+1]);
                if(c[i+1][j]>c[i][j+1]) d[i+1][j+1]=-1;
                else d[i+1][j+1]=1;
            }
        }
    }
    return c[m][n];
}
void help_print(string a,string b,int *d[],int i,int j){
    if(i==a.size() || j==b.size()) return;
    if(d[i+1][j+1]==0){
        cout<<a[i];
        help_print(a,b,d,i+1,j+1);
    }
    else if(d[i+1][j+1]==1) help_print(a,b,d,i+1,j);
    else help_print(a,b,d,i,j+1);
}
int main(){
    string a;
    string b;
    cin>>a>>b;
    int m=a.size();
    int n=b.size();
    int *c[m+1];
    int *d[m+1];
    for(int i=0;i<m+1;i++){
        c[i]=new int[n+1];
    }
    for(int i=0;i<m+1;i++){
        d[i]=new int[n+1];
    }
    int res=LCS(a,b,c,d,m,n);
    cout<<res<<endl;
    help_print(a,b,d,0,0);
}