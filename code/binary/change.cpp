#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
//m(10进制数值)，n(进制数)准换成对应进制数的数值
int main(){
    int m;
    int n;
    cin>>m>>n;
    string res="";
    string table="0123456789ABCDEF";
    int temp=m;
    while(temp!=0){
        if(temp<0) temp=-temp;
        res=table[temp%n]+res;
        temp/=n;
    }
    if(m<0){
        res="-"+res;
    }
    cout<<res;   
}

/*b(进制)a(对应进制的数值)转换成10进制数
int process(string a,string b){
    int n=stoi(a);
    int res=0;
    int count=0;
    for(int i=b.size()-1;i>=0;i--){
        if(b[i]>='A') res+=(b[i]-'A'+10)*pow(n,count);
        else res+=(b[i]-'0')*pow(n,count);
        count++;
    }
    return res;
}
*/