#include <iostream>
#include <vector>
using namespace std;
struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int v){
        val=v;
        left=NULL;
        right=NULL;
    }
};
Node *build(vector<int>& a,vector<int>& b){
    if(a.size()==0) return NULL;
    Node *head=new Node(a[0]);
    vector<int> a_left;
    vector<int> a_right;
    vector<int> b_left;
    vector<int> b_right;
    int count=0;
    for(int i=0;i<b.size();i++){
        if(b[i]==a[0]) break;
        count++;
    }
    for(int i=0;i<count;i++){
        b_left.push_back(b[i]);
    }
    for(int i=count+1;i<b.size();i++){
        b_right.push_back(b[i]);
    }
    for(int i=1;i<a.size();i++){
        bool is_left=false;
        for(int j=0;j<b_left.size();j++){
            if(a[i]==b[j]){
                is_left=true;
                break;
            }
        }
        if(is_left) a_left.push_back(a[i]);
        else a_right.push_back(a[i]);
    }
    head->left=build(a_left,b_left);
    head->right=build(a_right,b_right);
    return head;
}
void print_1(Node *pHead){
    if(pHead==NULL) return;
    if(pHead->left==NULL && pHead->right==NULL){
        cout<<pHead->val<<' ';
        return;
    }
    print_1(pHead->left);
    print_1(pHead->right);
}
void print_2(Node *pHead){
    if(pHead==NULL) return;
    cout<<pHead->val<<' ';
    print_2(pHead->left);
    print_2(pHead->right);  
}
void print_3(Node *pHead){
    if(pHead==NULL) return;
    print_3(pHead->left);
    print_3(pHead->right);
    cout<<pHead->val<<' ';
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
    Node *pHead1=head;
    Node *pHead2=head;
    Node *pHead3=head;
    print_1(pHead1);
    cout<<endl;
    print_2(pHead2);
    cout<<endl;
    print_3(pHead3);   
}