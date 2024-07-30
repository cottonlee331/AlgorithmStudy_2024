// 백준 1260

#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void DFS(int start){
    cout<<start<<' ';
    visited[start] = true;
    for(int i = 0; i<adj[start].size(); i++){
        if(!visited[adj[start][i]]){
            DFS(adj[start][i]);
        }
    }
}

void BFS(int start){
    deque<int> que;
    visited[start] = true;
    que.push_back(start);
    while(!que.empty()){
        int curr = que.front();
        que.pop_front();

        cout<<curr<<' ';
        for(int i = 0; i<adj[curr].size(); i++){
            if(visited[adj[curr][i]]){
                continue;
            }
            visited[adj[curr][i]] = true;
            que.push_back(adj[curr][i]);
        }
    }

}

int main(){
    int n, m, v;
    cin>>n>>m>>v;

    adj.assign(n+1,vector<int>());
    visited.assign(n+1,false);

    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }

    for(int j = 1; j<n+1; j++){
        sort(adj[j].begin(),adj[j].end());
    }

    DFS(v);
    cout<<"\n";
    visited.assign(n+1,false);
    BFS(v);
}