#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii=pair<int,int>;

int h,w;
char board[26][26];
int vis[26][26];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0}; // 동,남,서,북

queue<pair<pii,int>> q;  // 현재위치와 바라보는 방향 저장
vector<pair<pii,int>> vec; // 시작점과 시작 방향 저장할 vector
string ans; // 명령어 저장 문자열

void bfs(int x, int y, int dir){ // 시작 좌표와 시작 방향 받아옴

	q.push({{x,y},dir});
	vis[x][y]=1;
	int strgtFlag = 0; // 같은 방향 직진 몇번했는지 체크 flag (2배수면 명령어로 저장되어야 함)

	while(!q.empty()){
		pii tmp = q.front().first; 
		int tmpdir = q.front().second; q.pop();
	
		for(int i=0; i<4; i++){
			int nx = tmp.X+dx[i];
			int ny = tmp.Y+dy[i];

			if(nx<=0||nx>h||ny<=0||ny>w) continue;
			if(vis[nx][ny]||board[nx][ny]=='.') continue;

			if(tmpdir!=i){
				if((tmpdir+1)%4==i) {
					cout<<"R";
					//ans.push_back('R');
				}
				else if((i+1)%4==tmpdir){ 
					cout<<"L";
					//ans.push_back('L');
				}
			}

			strgtFlag++;
			if(strgtFlag==2){
				strgtFlag=0;
				//ans.push_back('A'); //명령어 저장
				cout<<"A";
			}
			q.push({{nx,ny},i});
			vis[nx][ny]=1;
		}
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>h>>w;
	for(int i=1; i<=h; i++) for(int j=1; j<=w; j++) cin>>board[i][j];

	// 시작,끝점을 찾는다. 시작,끝점은 #에 인접한 것중에 3개가 빈칸이어야 한다.
	// 로봇이 2칸씩 움직이므로 경로의 가로가 연속으로 겹치는 점은 없게된다.
	for(int i=1; i<=h; i++) for(int j=1; j<=w; j++){
		int flag=0;
		vector<int> tmpv; // 방향 저장
		if(board[i][j]=='#'){
			
			for(int n=0; n<4; n++){
				int nx = i+dx[n];
				int ny = j+dy[n];
				if(nx<=0||nx>h||ny<=0||ny>w) continue;
				if(board[nx][ny]=='#'){  // 인접한 것중에 #의 개수 판단
					flag++;
					tmpv.push_back(n);
				}
			}
		}
		if(flag==1){
			vec.push_back({{i,j},tmpv[0]});
			break;
		}
	}

	cout<<vec[0].first.X<<" "<<vec[0].first.Y<<"\n";

	if(vec[0].second==0) cout<<">\n";
	else if(vec[0].second==1) cout<<"v\n";
	else if(vec[0].second==2) cout<<"<\n";
	else if(vec[0].second==3) cout<<"^\n";

	bfs(vec[0].first.X, vec[0].first.Y, vec[0].second);
	return 0;
}
