#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isvalid(vector<string>& temp,int y,int x){
    for(int i=0;i<temp.size();i++){
        if(temp[i][x]=='Q') return false;
    }
    for(int i=y-1,j=x-1;i>=0 && j>=0;i--,j--){
        if(temp[i][j]=='Q') return false;
    }
    for(int i=y-1,j=x+1;i>=0 && j<temp.size();i--,j++){
        if(temp[i][j]=='Q') return false;
    }
    return true;
}
void help(int cury,vector<string>& temp,vector<vector<string>>& res){
    int n=temp.size();
    if(cury==n){
        res.push_back(temp);
        return;
    }
    for(int i=0;i<n;i++){
        if(isvalid(temp,cury,i)==true){
            temp[cury][i]='Q';
            help(cury+1,temp,res);
            temp[cury][i]='.';
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<string>> res;
    vector<string> temp(n,string(n,'.'));
    help(0,temp,res);
    for(int i=0;i<res[0].size();i++){
        cout<<res[0][i]<<endl;
    }
}