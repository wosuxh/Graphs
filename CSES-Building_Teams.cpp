#include<bits/stdc++.h> 
using namespace std ;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
// moving like this : LRUD
bool dfs(int node , vector<vector<int>> &adj , vector<int> &vis, vector<int> &team, int p){
	vis[node]=1 ;
	team[node]=p ;
	for(auto &val : adj[node]){
		if(!vis[val]){
			if(!dfs(val,adj,vis,team,3-p))return false;
		}
		if(vis[val]){
			if(team[val]==p)
				return false ;
		}	
	}
	return true ;
}
int main(){
	int n , m; 
	cin >> n >> m ;
	vector<vector<int>> adj(n) ;

	for(int i=0 ;i<m ;i++){
		int a,b;
		cin >> a >> b ;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> team(n);
	vector<int> vis(n) ;
	for(int i=0 ;i<n ;i++){
		if(!vis[i]){
			if(dfs(i,adj,vis,team,1)==false){
				cout << "IMPOSSIBLE\n" ;
				return 0 ;
			}
		}
	}
	for(auto &val :team) cout <<val << " "  ;
	return 0 ;
}