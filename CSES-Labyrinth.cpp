#include<bits/stdc++.h> 
using namespace std ;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
// moving like this : LRUD


void bfs(int row,int col,vector<vector<char>> &graph, vector<vector<int>> &vis, vector<vector<pair<int,int>>> &parent , vector<vector<char>> &dir){
	string move="LRUD";
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
			
			if(nr>=0 && nc>=0 && nr<n && nc<m && graph[nr][nc]!='#' && !vis[nr][nc]){
				q.push({nr,nc});
				parent[nr][nc]={r,c};
				dir[nr][nc]=move[i]; 
				vis[nr][nc]=1 ;
			}
		}
	}
}

int main(){
	int n,m ;
	cin >> n >> m ;
	vector<vector<char>> graph(n,vector<char>(m));
	vector<vector<int>> vis(n,vector<int>(m));
	vector<vector<char>> dir(n,vector<char>(m));
	vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m));
	int sr=0,sc=0 ;
	int er=0,ec=0 ;
	for(int i=0 ;i<n ; i++){
		for(int j=0 ;j<m ;j++){
			cin >> graph[i][j] ;
			if(graph[i][j]=='A'){
				sr=i ;
				sc=j;
			}
			if(graph[i][j]=='B'){
				er=i;
				ec=j;
			}
		}
	}

	bfs(sr,sc,graph,vis,parent,dir);
	if(vis[er][ec]==0){
		cout << "NO\n" ;
		return 0 ;
	}
	cout << "YES\n" ;

	string ans="" ;

	while(make_pair(er, ec) != make_pair(sr, sc)){
		ans+=dir[er][ec];
		int prev_r = parent[er][ec].first;
		int prev_c = parent[er][ec].second;
		er = prev_r;
		ec = prev_c;
	}

	reverse(ans.begin(),ans.end());
	cout << ans.size()<< "\n" ;
	cout << ans << "\n" ;

	return 0 ;
}