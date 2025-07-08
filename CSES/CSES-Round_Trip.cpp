#include<bits/stdc++.h> 
using namespace std ;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
// moving like this : LRUD

bool dfs(int node , int prev, vector<vector<int>> &adj , vector<int> &vis , vector<int> &parent , int &st , int &ed){
	vis[node]=1 ;
	parent[node]=prev;
	for(auto &val : adj[node]){
		if(!vis[val]){
			if(dfs(val,node,adj,vis,parent,st,ed)) return true ;
		}
		else if(val!=prev){
			st=val ;
			ed=node ;
			return true ;
		}
	}
	return false;
}

int main(){
	int n , m ;
	cin >> n >> m ;

	vector<vector<int>> adj(n);

	for(int i=0 ;i<m ; i++){
		int a, b ;
		cin >> a >> b ;
		a-- ; 
		b-- ;

		adj[a].push_back(b) ;
		adj[b].push_back(a) ;
	}

	int st =-1 ;
	int ed=0 ;
	vector<int> parent(n);
	vector<int> vis(n) ;
	for(int i=0 ;i<n ;i++){
		if(!vis[i]){
			if(dfs(i,-1,adj,vis,parent, st, ed)) break;
			else continue ;
		}

	}
	if(st==-1){
		cout << "IMPOSSIBLE\n" ;
		return 0 ;
	}
	vector<int> ans; 
	ans.push_back(st);

	while(ed!=st){
		ans.push_back(ed) ;
		ed=parent[ed] ;
	}
	ans.push_back(st) ;

	cout << ans.size() << "\n" ;
	for(auto &val : ans) cout << ++val << " ";
	return 0 ;
}