#include<bits/stdc++.h>

using namespace std;

int n,m,k;
int a[3001];
int b[3001];
int c[3001][3001];
// dp?

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;

	for(int i=0; i<n; i++) cin>>a[i];
	for(int j=0; j<m; j++) cin>>b[j];

	int mx = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i]!=b[j]) continue;
			if(i==0 || j==0) c[i][j]=1;
			else c[i][j] = c[i-1][j-1] +1;
			mx = max(mx,c[i][j]);
		}
	}
	cout<<mx;
	return 0;
}
