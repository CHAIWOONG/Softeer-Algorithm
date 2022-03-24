#include<bits/stdc++.h>
#define X first
#define Y second

// bfs

using namespace std;
using pii = pair<int,int>;

int board[102][102];
int vis[102][102];

int n,m, ice=0, ans=0; // n= row, m = col
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue<pii> q;

void melt(){
	for(int i=0; i<=n+1; i++) for(int j=0; j<=m+1; j++){
		if(vis[i][j]>=4){ // 얼음인데 공기와 두변이상 맞닿은 것임
			board[i][j]=0;
			ice--;
		}
		vis[i][j]=0; // 초기화
	}
}

void bfs(int x, int y){

	q.push({x,y});
	vis[x][y] = 1;

	while(!q.empty()){
		pii tmp = q.front(); q.pop();

		for(int i=0; i<4; i++){
			int nx = tmp.X+dx[i];
			int ny = tmp.Y+dy[i];

			if(nx<0||nx>n+1||ny<0||ny>m+1) continue;
			if(vis[nx][ny]==1) continue; // 방문한 공기면 제외
			if(board[nx][ny]){ // 얼음이면, 두변 이상이 맞닿는지 체크해야된다.
				vis[nx][ny] +=2;
				continue; // queue에는 넣지 않음
			}
			q.push({nx,ny});
			vis[nx][ny]=1;
		}
	}	
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){ 
		cin>>board[i][j];
		if(board[i][j]) ice++;
	}

	if(ice==0){
		cout<<"0";
		return 0;
	}

	while(1){

		for(int i=0; i<=n+1; i++) for(int j=0; j<=m+1; j++){ 
			if((i==0||i==n+1) || (j==0||j==m+1)){ // 가장자리에 있는 공기만 시작점이 될 수 있다
				if(vis[i][j]==0){
					bfs(i,j);
				}
			}
		}

		melt();
		ans++;
		if(ice==0) break;
	}
	
	cout<<ans;

	return 0;
}
