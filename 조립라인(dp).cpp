#include<bits/stdc++.h>

using namespace std;

int n;
int a[1005]; // ai 작업장의 작업시간
int ab[1005]; // ai에서 bi+1까지 이동시간
int b[1005]; // bi 작업장의 작업시간
int ba[1005]; // bi에서 ai+1까지 이동시간

// dp?
// dp[0][i] = min(dp[0][i-1],dp[1][i-1]+ba[i-1])를 통해
// 상태에 대해서 분화한 다음 이전 값의 두가지 경우에서 작은것을 택해서 최소값 구함

int dp[2][1005]; // 0= a, 1=b 일 때

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		cin >> a[i] >> b[i] >> ab[i] >> ba[i];
	}
	cin >> a[n] >> b[n];

	dp[0][0] = a[0];
	dp[1][0] = b[0]; // 초기 값 할당

	for (int i = 1; i <= n; i++) {

		dp[0][i] = min(dp[0][i - 1], dp[1][i - 1] + ba[i - 1]);
		dp[0][i] += a[i];

		dp[1][i] = min(dp[1][i - 1], dp[0][i - 1] + ab[i - 1]);
		dp[1][i] += b[i];
	}

	cout << min(dp[0][n], dp[1][n]);
	return 0;
}