#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
vector<string> res;
bool match(string s,unordered_set<string> &dict){
    if(dict.find(s)!=dict.end()) return true;
    else return false;
}
void process(string s, unordered_set<string> &dict,int *store[],int m){
    vector<string> res;
    for(int i=0;i<m;i++){
        for(int j=i;j<m;j++){
            store[i][j]=0;
            if(match(s.substr(i,j-i+1),dict)==true) store[i][j]=1;
        }
    }
}
void help(int index,int *store[],string s,string temp){
    if(index==s.size()){
        temp.erase(temp.size()-1,1);
        res.push_back(temp);
        return;
    }
    for(int i=0;i<s.size();i++){
        if(store[index][i]==1){
            help(i+1,store,s,temp+s.substr(index,i-index+1)+" ");
        }
    }
}
vector<string> wordBreak(string s, unordered_set<string> &dict) {
    int m=s.size();
    if(m<=0) return res;
    int *store[m];
    for(int i=0;i<m;i++){
        store[i]=new int[m+1];
    }
    process(s,dict,store,m);
    help(0,store,s,"");
    return res;               
}
int main(){
    unordered_set<string> dict;
    dict.insert("cat");
    dict.insert("cats");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("dog");
    string s;
    cin>>s;
    res=wordBreak(s,dict);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    
}