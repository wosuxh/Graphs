#include<bits/stdc++.h> 
using namespace std ;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void bfs(int row,int col,vector<vector<char>> &graph, vector<vector<int>> &vis){
	int n=graph.size();
	int m=graph[0].size();
	vis[row][col]=1 ;

	queue<pair<int,int>> q ;
	q.push({row,col});

	while(!q.empty()){
		int r=q.front().first ;
		int c=q.front().second ;
		q.pop();

		for(int i=0 ;i<4 ;i++){
			int nr=r+dx[i];
			int nc=c+dy[i];
			if(nr>=0 && nc>=0 && nr<n && nc<m && graph[nr][nc]=='.' && !vis[nr][nc]){
				q.push({nr,nc});
				vis[nr][nc]=1 ;
			}
		}
	}
}
int main(){
	int n ,m ;
	cin >> n >> m ;
	vector<vector<char>> graph(n,vector<char>(m));

	for(int i=0 ;i<n ;i++){
		for(int j=0 ;j<m ;j++){
			cin >> graph[i][j];
		}
	}

	vector<vector<int>> vis(n,vector<int>(m));
	int ans=0 ;
	for(int i=0 ;i<n ;i++){
		for(int j=0 ;j<m ;j++){
			if(graph[i][j]=='.' && !vis[i][j]){
				bfs(i,j,graph,vis);
				ans++;
			}
		}
	}
	cout<< ans << "\n" ;
	return 0 ;
}