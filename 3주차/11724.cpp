// 백준 11724

#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;


void DFS(int start){
    visited[start] = true;
    for(int i = 0; i<adj[start].size();i++){
        if(!visited[adj[start][i]]){
            DFS(adj[start][i]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m; 
    cin>>n>>m;

    adj.assign(n+1,vector<int>());
    visited.assign(n+1,false);
    int result = 0;

    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int j = 1; j<=n; j++){
        if(visited[j]){
            continue;
        }
        else{
            result++;
            DFS(j);
        }
    }

    cout<<result;

}
