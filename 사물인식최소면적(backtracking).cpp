#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii=pair<int,int>;

// 색 좌표 k값에 대한 백트래킹?

int n,K, ans=INT_MAX;
vector<pii> colorVec[21]; // 색깔 값에 대한 좌표 저장 vector

void dfs(int k, int mnX, int mnY, int mxX, int mxY){

	if(k==K+1){
		int area = (mxX-mnX) * (mxY-mnY);
		ans = min(ans,area);
		return;
	}
	for(int i=0; i<colorVec[k].size(); i++){
		pii tmp = colorVec[k][i];
		int tMnx=mnX, tMny=mnY, tMxx=mxX, tMxy=mxY;
		if(mnX>tmp.X) tMnx = tmp.X;
		if(mnY>tmp.Y) tMny = tmp.Y;
		if(mxX<tmp.X) tMxx = tmp.X;
		if(mxY<tmp.Y) tMxy = tmp.Y;
		
		int area = (tMxx-tMnx) * (tMxy-tMny);
		if(ans<=area) continue;
    // 시간복잡도의 최소화를 위해서, 중간단계에서 area가 ans보다 크면 
    // 답의 가망이 없는 것이므로 그냥 제외시킨다.
		dfs(k+1,tMnx,tMny,tMxx,tMxy);
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n>>K;
	for(int i=0; i<n; i++){
		int a,b,c; cin>>a>>b>>c;
		colorVec[c].push_back({b,a});
	}

	dfs(1,INT_MAX,INT_MAX,-INT_MAX,-INT_MAX);
	cout<<ans;
	return 0;
}
