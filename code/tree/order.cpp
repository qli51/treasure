#include <iostream>
#include <vector>
using namespace std;
void preorder(Node *p){
    if(p==NULL) return;
    stack<Node> s;
    Node *cur=p;
    while(!s.empty() || cur!=NULL){
        while(cur!=NULL){
            s.push(cur);
            cout<<cur->val;
            cur=cur->left;
        }
        cur=s.top();
        s.pop();
        cur=cur->right;
    }
}


void inorder(Node *p){
    if(p==NULL) return;
    stack<Node> s;
    Node *cur=p;
    while(!s.empty() || cur!=NULL){
        while(cur!=NULL){
            s.push(cur);
            cur=cur->left;
        }
        cur=s.top();
        s.pop();
        cout<<cur->val;
        cur=cur->right;
    }
}

void pastorder(Node *p){
    if(p==NULL) return;
    stack<Node> s;
    Node *cur=p;
    Node *last=NULL;
    while(!s.empty() || cur!=NULL){
        while(cur!=NULL){
            s.push(cur);
            cur=cur->left;
        }
        cur=s.top();
        if(cur->right!=NULL && last!=cur->right){ //不为空，且没有被访问过
            cur=cur->right;
        }
        else if(cur->right==NULL || last==cur->right){
            cout<<cur->val;
            s.pop();
            last=cur;
            cur=NULL;
        }
    }
}