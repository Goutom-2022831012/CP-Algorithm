#include<bits/stdc++.h>
using namespace std;

void Dfs(vector<vector<int>>&adj,vector<bool>&visited,int node){
    if(visited[node]) return ;
     visited[node] = true ; 
        cout<<node<<endl;
            for(int v : adj[node]){
                if(!visited[v]){
                    Dfs(adj,visited,v);
                }
            }       
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    vector<bool> visited(n,false);
    int u , v ; 
    for(int i = 0 ; i < m ; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Dfs(adj,visited,0);
    return 0 ;
}