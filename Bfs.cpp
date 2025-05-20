#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>&adj,vector<bool>&visited,queue<int>&q){
    if(!visited[0]) visited[0] = true ; 
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<<endl;
            for(int v : adj[u]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                }
            }
        
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    vector<bool> visited(n,false);
    queue<int>q;
    int u , v ; 
    for(int i = 0 ; i < m ; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(adj,visited,q);
    return 0 ;
}