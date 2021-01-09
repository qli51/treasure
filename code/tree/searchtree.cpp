#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;
vector<int> res;
struct Node{
    Node *left;
    Node *right;
    int val;
    Node(int v){
        val=v;
        left=NULL;
        right=NULL;
    }
};
Node *build(vector<int>& store,int i){
    if(i>=store.size() || store[i]==-1) return NULL;
    Node *head=new Node(store[i]);
    head->left=build(store,2*i+1);
    head->right=build(store,2*i+2);
    return head;//先递归再return最后回溯head为头
}
void mid_process(Node *p){
    if(p==NULL) return;
    mid_process(p->left);
    res.push_back(p->val);
    mid_process(p->right);
}
bool increase(vector<int>& a){
    if(a.size()==1) return true;
    for(int i=1;i<a.size();i++){
        if(a[i-1]>a[i]) return false;
    }
    return true;
}
int main(){
    string line;
    getline(cin,line);
    istringstream input(line);
    string chact;
    vector<int> store;
    while(getline(input,chact,',')){
        if(chact=="None"){
            store.push_back(-1);
        }
        else{
            int num=stoi(chact);
            store.push_back(num);
        }
    }
    Node *p=build(store,0);
    mid_process(p);
    if(increase(res)==true) cout<<"True";
    else cout<<"False";
} 