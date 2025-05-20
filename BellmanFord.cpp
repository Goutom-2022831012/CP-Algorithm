#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
bool bellmenford(int start,vector<vector<pair<int,int>>>&adj,vector<int>&dist , int nodes){
    dist[start] = 0;
    for(int i = 0 ; i< nodes-1 ;i++ ){
        for(auto it : adj[i]){
            int u = it.first;
            int w = it.second;
            if(dist[u]>w+dist[i]){
                dist[u] = dist[i] + w ;
            }
        }
    }
    for(int i = 0 ; i < nodes ; i++){
        for(auto it : adj[i]){
            int u = it.first;
            int w = it.second;
            if(dist[u] != inf &&dist[u]<w+dist[i]){
                return false;
            }
        }
    }
    return true ;
}

int main(){
   ios::sync_with_stdio(0);
cin.tie(0);

int n, m;
cin >> n >> m;
vector<vector<pair<int, int>>> adj(n);
vector<int> dist(n, inf);
int u, v, w;
for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
}
int start;
cin>>start;

    if(bellmenford(start,adj,dist,n)) cout<<"NO Negative cycle";
    else cout<<"Negative Cycle";
return 0 ;
}