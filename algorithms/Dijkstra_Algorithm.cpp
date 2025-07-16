#include<bits/stdc++.h>
using namespace std ;

int main(){
    int n,m ;
    cin >> n >> m ;

    vector<vector<pair<int,int>>> adj(n) ;

    for(int i =0 ; i < m; i++){
        int a,b,c ;
        cin >> a >>b >>c ;
        a-- ;
        b-- ;
        adj[a].emplace_back(b,c) ;
        adj[b].emplace_back(a,c) ;
    }
    
    long long inf=1e18 ;
    vector<long long> dis(n,inf) ;
    priority_queue<pair<long long,int>,vector<pair<long long,int>> , greater<pair<long long,int>>> pq ;

    pq.emplace(0,0) ;
    dis[0]=0 ;

    while(!pq.empty()){
        auto [distance,node]=pq.top();

        pq.pop();

        if(distance > dis[node]) continue ;

        for(auto &val : adj[node]){
            int nbr=val.first ;
            int wt=val.second ;

            if(distance+wt<dis[nbr]){
                dis[nbr]=distance+wt ;
                pq.emplace(dis[nbr],nbr) ;
            }
        }

    }
    for(auto &val : dis){
        cout << val << " " ;
    }
    cout << "\n" ;
    return 0 ;
}
