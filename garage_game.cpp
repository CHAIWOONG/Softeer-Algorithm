#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii=pair<int,int>;

int n,ans=0;
int board[46][16];
int score[4]; // 해당 차례에서 얻은 점수 저장
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

queue<pii> q;

void copyBd(int ori[][16], int tmpBd[][16]){

	for(int i=1; i<=3*n; i++) for(int j=1; j<=n; i++){
		tmpBd[i][j] = ori[i][j];
	}
}

int bfs(int x, int y, int (*vis)[16],int k){

	q.push({x,y});
	vis[x-2*n][y]=1;
	int tmpCar = board[x][y];
	int mxX=-INT_MAX, mxY=-INT_MAX, mnX=INT_MAX, mnY=INT_MAX;
	int vcnt=1;

	// 영역 구하기
	while(!q.empty()){
		pii tmp = q.front(); q.pop();
		board[tmp.X][tmp.Y] = 0; // board의 점수 제거

		for(int i=0; i<4; i++){
			int nx = tmp.X + dx[i];
			int ny = tmp.Y + dy[i];

			if(nx<=2*n||nx>3*n||ny<=0||ny>n) continue;
			if(vis[nx-2*n][ny]||board[nx][ny]!=tmpCar) continue;

			q.push({nx,ny});
			vis[nx-2*n][ny]=1;
			//vec.push_back({nx,ny});
			mnX = min(mnX,nx); mnY = min(mnY,ny);
			mxX = max(mxX,nx); mxY = max(mxY,ny);
			vcnt++;
		}
	}

	int area = (mxX-mnX+1)*(mxY-mnY+1); // 직사각형 구하기
	int carscore = tmpCar*vcnt;

	// 사라지는 곳 제거하기
	if(k<2){
		for(int i=mxX; i>=mnX; i--) for(int j=mnY; j<=mxY; j++){
			if(board[i][j]) continue;
			int tmpR = i-1;

			while(tmpR>=1){
				if(board[tmpR][j]){
					board[i][j] = board[tmpR][j];
					board[tmpR][j] = 0;
					break;
				}
				tmpR--;
			}
		}
	}
	return area+carscore;
}

void dfs(int k, int score){

	int vis[16][16] = {0,};
	int tmpBd[46][16];
	
	copyBd(board,tmpBd);
	
	if(k==3){
		ans=max(ans,score);
		return;
	}
	for(int i=3*n; i>2*n; i--) for(int j=1; j<=n; j++){
		if(vis[i-2*n][j] || !board[i][j]) continue;

		score += bfs(i,j,vis,k); 
		// copyBd(tmpBd,board);
		// q.push({i,j}); 
		// vis[i-2*n][j]=1;
		// int tmpCar = board[i][j];
		// int mxX=-INT_MAX, mxY=-INT_MAX, mnX=INT_MAX, mnY=INT_MAX;
		// int vcnt=1;

		// // 영역 구하기
		// while(!q.empty()){
		// 	pii tmp = q.front(); q.pop();
		// 	board[tmp.X][tmp.Y] = 0; // board의 점수 제거

		// 	for(int i=0; i<4; i++){
		// 		int nx = tmp.X + dx[i];
		// 		int ny = tmp.Y + dy[i];

		// 		if(nx<=2*n||nx>3*n||ny<=0||ny>n) continue;
		// 		if(vis[nx-2*n][ny]||board[nx][ny]!=tmpCar) continue;

		// 		q.push({nx,ny});
		// 		vis[nx-2*n][ny]=1;
		// 		mnX = min(mnX,nx); mnY = min(mnY,ny);
		// 		mxX = max(mxX,nx); mxY = max(mxY,ny);
		// 		vcnt++;
		// 	}
		// }
		// int area = (mxX-mnX+1)*(mxY-mnY+1); // 직사각형 구하기
		// int carscore = tmpCar*vcnt;

		// // 사라지는 곳 제거하기
		// if(k<2){
		// 	for(int i=mxX; i>=mnX; i--) for(int j=mnY; j<=mxY; j++){
		// 		if(board[i][j]) continue;
		// 		int tmpR = i-1;

		// 		while(tmpR>=1){
		// 			if(board[tmpR][j]){
		// 				board[i][j] = board[tmpR][j];
		// 				board[tmpR][j] = 0;
		// 				break;
		// 			}
		// 			tmpR--;
		// 		}
		// 	}
		// 	score += area+carscore;
		// 	dfs(k+1,score); // 다음 차수로 넘어간다.
		// }
		//score += area+carscore;
		dfs(k+1,score); // 다음 차수로 넘어간다.
		copyBd(tmpBd,board); // 상태 복귀
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1; i<=3*n; i++) for(int j=1; j<=n; j++) cin>>board[i][j];

	dfs(0,0);
	return 0;
}
