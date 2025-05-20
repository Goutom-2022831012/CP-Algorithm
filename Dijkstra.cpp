#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e9;

void dijkstra(int start,int n,vector<vector<pair<int,int>>>&adj){
    vector<int> dist(n,MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[start] = 0;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        pair<int,int> top = pq.top();
        pq.pop();
        int u = top.second;
        int d = top.first;
        if(d>dist[u]){
            continue;
        }
        for(auto adjecent : adj[u]){
            int v = adjecent.second;
            int w = adjecent.first;
             if(dist[v]>(w+dist[u])){
                dist[v] = w+dist[u];
                pq.push(make_pair(dist[v],v));
             }
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout<<i<<endl;
        if(dist[i]==MAX){
            cout<<"impossible"<<endl;
        }
        else{
            cout<<dist[i]<<endl;
        }
    }
}
int main(){
   int n = 5; 
    vector<vector<pair<int, int>>> adj(n);

    adj[0].push_back(make_pair(2, 1));
    adj[0].push_back(make_pair(4, 2));
    adj[1].push_back(make_pair(1, 2));
    adj[1].push_back(make_pair(7, 3));
    adj[2].push_back(make_pair(3, 4));
    adj[3].push_back(make_pair(1, 4));

    int src = 0;
    dijkstra(src, n, adj);
    return 0 ;  
}