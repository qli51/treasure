#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
struct Node{
    int key;
    int val;
    Node(int k,int v){
        key=k;
        val=v;
    }
};
class LRU{
private:
    int capacity;
    list<Node> cachelist;
    unordered_map<int,list<Node>::iterator> cachemap;

public:
    LRU(int n){
        capacity=n;
    }
    void set(int k,int v){
        if(cachemap.find(k)==cachemap.end()){
            if(cachelist.size()>=capacity){
                cachemap.erase(cachelist.back().key); //end()返回的末位的迭代器，back()返回的是最后一位元素
                cachelist.pop_back();
            }
            cachelist.push_front(Node(k,v));
            cachemap[k]=cachelist.begin();
        }
        else{
            cachemap[k]->val=v;
            cachelist.splice(cachelist.begin(),cachelist,cachemap[k]); //将cachelist中由cachemap[k]指出的元素插入到cachelist的cachelist.begin()位置的元素之前
            cachemap[k]=cachelist.begin();
        }
    }
    int get(int k){
        if(cachemap.find(k)==cachemap.end()) return -1;
        cachelist.splice(cachelist.begin(),cachelist,cachemap[k]);
        cachemap[k]=cachelist.begin();
        return cachemap[k]->val;
    }
};
int main(){
    int n,l;
    cin>>n>>l;
    LRU store(n);
    char c;
    int num1,num2;
    for(int i=0;i<l;i++){
        cin>>c;
        if(c=='s'){
            cin>>num1>>num2;
            store.set(num1,num2);
        }
        else if(c=='g'){
            cin>>num1;
            int num=store.get(num1);
            cout<<num<<endl;
        }
    }
}