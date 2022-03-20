#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii=pair<int,int>;

int row,col,rsr,rsc;
char board[51][51];
int tdis[51][51];
int rvis[51][51];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

queue<pii> tq; // 태민이의 이동에 대한 queue
queue<pii> rq; // 비의 이동에 대한 queue

void bfs(){ // 태범의 이동과 비의 이동을 따로 따로 구현

	while(!tq.empty() ||!rq.empty() ){
		int tqsz = tq.size();
		int rqsz = rq.size();

		while(tqsz--){
			pii tmp = tq.front(); tq.pop();

			if(board[tmp.X][tmp.Y]=='H'){ // 태범이 현재 자리가 집이면 종료
				cout<<tdis[tmp.X][tmp.Y]-1;
				return;
			}
			if(rvis[tmp.X][tmp.Y]) continue; // 태이 현재자리에 비가 들어오면 제외

			for(int i=0; i<4; i++){
				int nx = tmp.X + dx[i];
				int ny = tmp.Y + dy[i];

				if(nx<0||nx>=row||ny<0||ny>=col) continue;
				if(rvis[nx][ny] || board[nx][ny]=='X') continue;
				if(tdis[nx][ny]) continue;
				tdis[nx][ny] = tdis[tmp.X][tmp.Y]+1;
				tq.push({nx,ny});
			}
		}
		while(rqsz--){
			pii tmp = rq.front(); rq.pop();

			for(int i=0; i<4; i++){
				int nx = tmp.X + dx[i];
				int ny = tmp.Y + dy[i];

				if(nx<0||nx>=row||ny<0||ny>=col) continue;
				if(rvis[nx][ny] || board[nx][ny]=='X' || board[nx][ny]=='H') continue;
				rvis[nx][ny] = 1;
				rq.push({nx,ny});
			}
		}
	}
	cout<<"FAIL";
	return;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>row>>col;
	for(int i=0; i<row; i++){
		string s; cin>>s;
		for(int j=0; j<s.length(); j++){ 
			board[i][j] = s[j];
			if(s[j]=='W'){
				tq.push({i,j});
				tdis[i][j]=1;
			}
			if(s[j]=='*'){
				//rsr=i; rsc=j;
				rq.push({i,j});
				rvis[i][j]=1;
			}
		}
	}
	bfs();
	return 0;
}
