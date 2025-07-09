#include<bits/stdc++.h> 
using namespace std ;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
// moving like this : LRUD
int main(){
    int n,m,q ;
    cin >> n >> m >> q ;
    long long inf=1e12 ;
    vector<vector<long long>> adj(n,vector<long long>(n,inf));  

    for(int i=0 ;i<m ; i++){
        int a,b,c ;
        cin >> a >> b >> c ;
        a--;
        b--;
        adj[a][b]=min(c*1LL , adj[a][b]) ;
        adj[b][a]=min(c*1LL , adj[b][a]);
    }
    for(int i=0 ; i<n ;i++){
        adj[i][i]=0 ;
    }

    for(int i=0 ;i<n ;i++){
        for(int j=0 ;j<n ;j++){
            for(int k=0 ;k<n ;k++){
                adj[j][k]=min(adj[j][k],adj[j][i]+adj[i][k]) ;
            }
        }
    }

    while(q--){
        int a,b ;
        cin >> a >> b ;
        a--;
        b-- ;
        if(adj[a][b]==inf){
            cout << "-1\n" ;
        }
        else
            cout << adj[a][b] << "\n" ;

    }
    return 0 ;
}