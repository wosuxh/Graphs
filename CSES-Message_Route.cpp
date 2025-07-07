#include<bits/stdc++.h> 
using namespace std ;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
// moving like this : LRUD
int main(){
	int n,m ;
	cin >> n >> m ;

	vector<vector<int>> adj(n);
	for(int i=0 ;i<m ;i++){
		int a,b ;
		cin >> a >> b;
		a--;
		b--;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> parent(n,-1);
	queue<int> q ;
	q.push(0) ;
	parent[0]=0 ;
	while(!q.empty()){
		int node=q.front();

		q.pop();

		for(auto &val : adj[node]){
			if(parent[val]==-1){
				q.push(val);
				parent[val]=node;
			}
		}
	}
	if(parent[n-1]==-1){
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	vector<int> ans ;

	int temp=n-1;

	while(temp!=0){
		ans.push_back(temp);
		temp=parent[temp];
	}
	ans.push_back(0);
	reverse(ans.begin(),ans.end());
	cout << int(ans.size()) << "\n" ;
	for(auto &val:ans)
		cout << val+1 << " " ;

	return 0 ;
}