#include<bits/stdc++.h>

using namespace std;

int n, m;
int lift[100001];
int strong[100001]; // 자기가 강하다고 인식하면 0, 강하지 않다고 인식하면 1
//vector<int> adj[100001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>lift[i];
	}

	for(int i=0; i<m; i++){
		int a,b; cin>>a>>b;
		//adj[a].push_back(b);

		if(lift[a]>lift[b]) strong[b]=1;
		else if(lift[a]<lift[b]) strong[a]=1;
		else { // 같을 때,
			strong[a]=1;
			strong[b]=1;
		}
	}

	int ans=0;
	for(int i=1; i<=n; i++){
		if(!strong[i]) ans++;
	}

	cout<<ans;
	return 0;
}
