#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <set>
using namespace std;
set<string> res;
void process(queue<char> in,stack<char> temp,string store,bool pop){
    if(in.empty()){
        while(!temp.empty()){
            store+=temp.top();
            temp.pop();
        }
        res.insert(store);
        return;
    }
    if(pop){
        if(!temp.empty()){
            store+=temp.top();
            temp.pop();
        }
        else return;
    }
    else{
        temp.push(in.front());
        in.pop();
    }
    process(in,temp,store,true);
    process(in,temp,store,false);
}
int main(){
    string s;
    cin>>s;
    queue<char> in;
    stack<char> temp;
    string store="";
    for(int i=0;i<s.size();i++){
        in.push(s[i]);
    }
    process(in,temp,store,false);
    for(set<string>::iterator iter=res.begin();iter!=res.end();iter++){
        cout<<*iter<<endl;
    }
}