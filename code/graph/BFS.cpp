#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define N 5;
int visit=new int[N]();
void BFS(int start){
    queue<int> q;
    q.push(start);
    visit[start]=1;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        cout<<front<<endl;
        for(int i=0,i<N;i++){
            if(!visit[i] && map[front][i]==1){
                visit[i]=1;
                q.push(i);
            }
        }
    }
}

