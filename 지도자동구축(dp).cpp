#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll dp[16]; // [i] = i번째 iteration에서의 한 변에서의 점의 개수

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n;
	
	dp[0] = 2; // 2*2
	dp[1] = 3; // (2+1)*(2+1)
	dp[2] = 5; // (3+2) * (3+2)
	// 

	for(int i=3; i<=15; i++){
		dp[i] = (dp[i-1]+dp[i-1]-1);
	}

	cout<<dp[n]*dp[n];

	return 0;
}
