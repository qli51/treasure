#include <iostream>
#include <vector>
using namespace std;
vector<int> res;
struct Node{
    Node *left;
    Node *right;
    int val;
    Node(int v){
        left=NULL;
        right=NULL;
        val=v;
    }
};
Node* build(vector<int>& a,vector<int>& b){
    if(a.size()==0) return NULL;
    Node *head=new Node(a[0]);
    int count=0;
    for(int i=0;i<b.size();i++){
        if(b[i]==a[0]) break;
        count++;        
    }
    vector<int> a_left;
    vector<int> a_right;
    vector<int> b_left;
    vector<int> b_right;
    for(int i=0;i<count;i++){
        a_left.push_back(a[i+1]);
        b_left.push_back(b[i]);
    }
    for(int i=count+1;i<a.size();i++){
        a_right.push_back(a[i]);
        b_right.push_back(b[i]);
    }
    head->left=build(a_left,b_left);
    head->right=build(a_right,b_right);
    return head;
}
int sum(Node *p){
    if(p==NULL) return 0;
    return p->val+sum(p->left)+sum(p->right);
}
Node* transfer(Node *p){
    if(p==NULL) return NULL;
    Node *head=new Node(sum(p)-p->val);
    head->left=transfer(p->left);
    head->right=transfer(p->right);
    return head;
}
void process(Node *head){
    if(head==NULL) return;
    process(head->left);
    res.push_back(head->val);
    process(head->right);
}
int main(){
    vector<int> a;
    vector<int> b;
    int num;
    while(cin>>num){
        a.push_back(num);
        if(cin.get()=='\n') break;
    }
    while(cin>>num){
        b.push_back(num);
        if(cin.get()=='\n') break;
    }
    Node *head=build(a,b);
    Node *p=transfer(head);
    process(p);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<' ';
    }
}