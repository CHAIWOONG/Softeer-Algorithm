#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii=pair<int,int>;

int row,col,Q;
int board[130][130];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue<pii> q;

void bfs(int x, int y, int c){

	int vis[130][130];
	fill(&vis[0][0], &vis[row+1][col+1], 0); // 명령어마다 초기화 해줘야한다
	
	q.push({x,y}); vis[x][y]=1;
	int tmpColor = board[x][y]; // 원래 x,y의 색깔
	//cout<<tmpColor<<"\n";

	while(!q.empty()){
		pii tmp = q.front(); q.pop();
		board[tmp.X][tmp.Y]=c; // 명령어에 따른 색으로 바꿔줌

		for(int i=0; i<4; i++){
			int nx = tmp.X+dx[i];
			int ny = tmp.Y+dy[i];

			if(nx<=0||nx>row||ny<0||ny>col) continue;
			if(vis[nx][ny]||board[nx][ny]!=tmpColor) continue;
			vis[nx][ny]=1;
			q.push({nx,ny});
		}
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>row>>col;
	for(int i=1; i<=row; i++) for(int j=1; j<=col; j++){
		cin>>board[i][j];
	}

	cin>>Q;
	for(int i=0; i<Q; i++){
		int x,y,c; cin>>x>>y>>c;
		bfs(x,y,c); // 좌표와 변경 색깔에 대한 bfs 함수 실행
	}

	for(int i=1; i<=row; i++){
		for(int j=1; j<=col; j++)
			cout<<board[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";
	return 0;
}
