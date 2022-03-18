#include<bits/stdc++.h>

using namespace std;

// dp 최장 부분증가수열?
int n, ans = 0;
int arr[3001];
int dp[3001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		int len = 0; // 매번 해당 idx에서 나올 수 있는 최장 길이 갱신
		for (int j = 1; j <= i; j++) { // 해당 idx의 앞의 값부터 확인 진행
			if (arr[j] < arr[i]) {
				if (len < dp[j]) len = dp[j];
				// 해당idx 가 앞의 값보다 큰데, 저장된 길이가 확인한 길이보다 길다면 update 
			}
		}
		dp[i] = len + 1; // 자기자신 넣어서 len+1해서 update
		ans = max(dp[i], ans);
	}

	cout << ans;
	return 0;
}