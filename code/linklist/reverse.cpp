#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
struct Node{
    int val;
    Node *next;
    Node(int v){
       val=v;
       next=NULL;
    }
};
Node *build(vector<int>& a,int i){
    if(i>=a.size()) return NULL;
    Node *head=new Node(a[i]);
    head->next=build(a,i+1);
    return head;    
}
Node *reverse(Node *p){
    if(p==NULL || p->next==NULL) return NULL;
    Node *pre=NULL;
    Node *next=NULL;
    while(p!=NULL){
        next=p->next;
        p->next=pre;
        pre=p;
        p=next;
    }
    return pre;
}
Node* reverse2(Node *pHead,int k){
    if(pHead==NULL) return NULL;
    Node *left=pHead;
    Node *right=pHead;
    Node *pre=pHead;
    for(int i=0;i<k;i++){
        if(right!=NULL) right=right->next;
        else return left;
    }
    Node *head=left;
    while(left!=right){
        Node *next=left->next;
        left->next=pre;
        pre=left;
        left=next;
    }
    head->next=reverse2(right,k);
    return pre;        
}
int main(){
    string s;
    string ss;
    vector<int> store;
    getline(cin,s);
    istringstream input(s);
    while(getline(input,ss,' ')){
        store.push_back(stoi(ss));
    }
    Node *head=build(store,0);
    Node *p=head;
    Node *r=reverse(p);
    cout<<r->val;
}