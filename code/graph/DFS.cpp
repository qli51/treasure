#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define N 5;
int *visit=new int[N]();
void DFS(int start){
    stack<int> s;
    s.push(start);
    visit[start]=1;
    while(!s.empty()){
        bool is_push=false;
        int top=s.top();
        for(int i=0;i<N;i++){
            if(!visit[i] && map[top][1]==1){
                visit[i]=1;
                s.push(i);
                is_push=true;
                break;
            }
        }
        if(!is_push){
            s.pop();
            cout<<top<<endl;
        }
    }
}

void DFS(int start){
    visit[start]=1;
    for(int i=0;i<N;i++){
        if(!visit[i] && map[start][i]==1){
            DFS(i);
        }
    }
    cout<<start<<endl;
}


