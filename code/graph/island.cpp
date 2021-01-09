#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node{
    int y;
    int x;
    Node(int a,int b){
        y=a;
        x=b;
    }
};
int count(vector<vector<int>> a,int row,int col){
    int res=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(a[i][j]==1){
                res++;
                Node temp(i,j);
                queue<Node> store;
                store.push(temp);
                while(!store.empty()){
                    Node f=store.front();
                    store.pop();
                    if(f.x-1>=0 && a[f.y][f.x-1]==1){
                        Node temp1(f.y,f.x-1);
                        store.push(temp1);
                        a[f.y][f.x-1]=0;
                    }
                    if(f.x+1<col && a[f.y][f.x+1]==1){
                        Node temp2(f.y,f.x+1);
                        store.push(temp2);
                        a[f.y][f.x+1]=0;
                    }
                    if(f.y-1>=0 && a[f.y-1][f.x]==1){
                        Node temp3(f.y-1,f.x);
                        store.push(temp3);
                        a[f.y-1][f.x]=0;
                    }
                    if(f.y+1<row && a[f.y+1][f.x]==1){
                        Node temp4(f.y+1,f.x);
                        store.push(temp4);
                        a[f.y+1][f.x]=0;
                    }                
                }            
            }
        }
    }
    return res;
}
int main(){
    int m;
    int n;
    cin>>m>>n;
    vector<int> temp(n,0);
    vector<vector<int>> store(m,temp);
    vector<int> res;
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int y,x;
        cin>>y>>x;
        store[y][x]=1;
        res.push_back(count(store,m,n));   
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<' ';
    }
}