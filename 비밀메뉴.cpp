#include<bits/stdc++.h>

using namespace std;

int k,m,n;
int secret[101];
int arr[101];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>m>>n>>k;
	for(int i=0; i<m; i++) cin>>secret[i];
	for(int i=0; i<n; i++) cin>>arr[i];

	int flag=1;
	for(int i=0; i<n-m+1; i++){
		int st=0;
		if(arr[i]==secret[st]){
			for(int j=i; j<i+m; j++){
				if(arr[j]!=secret[st++]){ flag=1; break;}
				else flag=0;
			}
			if(!flag) break;
		}
	}

	if(flag) cout<<"normal";
	else cout<<"secret";
	return 0;
}
