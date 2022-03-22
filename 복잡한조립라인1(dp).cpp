#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int linenum, worknum;

int line[101][101]; // [i][j] = i 라인에서 j 작업장에서의 시간
int swtch[101][101][101]; //[i][j][k] = i 라인의 j 작업장에서 k라인의 j+1 작업장으로 가는데 걸리는 시간

ll dp[101][101];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> linenum >> worknum;

	for (int j = 1; j <= worknum; j++) {
		for (int N = 1; N <= linenum; N++) { // 라인의 수만큼 받는다.
			cin >> line[N][j];
		}
		if (j == worknum) break;  // 마지막 작업장은 다음 작업장으로 가는게 없음

		for (int N = 1; N <= linenum; N++) { // 라인의 수만큼 받는다.
			for (int otN = 1; otN <= linenum; otN++) {
				if (otN == N) continue;
				cin >> swtch[N][j][otN];
			}
		}
	}

	for (int N = 1; N <= linenum; N++) { // 각 라인별 첫 작업장의 조립시간을 넣어서 초기화
		dp[N][1] = line[N][1];
	}

	for (int j = 2; j <= worknum; j++) {

		for (int N = 1; N <= linenum; N++) {

			ll tmp = LLONG_MAX;
			for (int otN = 1; otN <= linenum; otN++) {
				if (otN == N) continue;
				tmp = min(tmp, dp[otN][j - 1] + swtch[otN][j - 1][N]); // 작업장 이동에서 가장 적은 시간을 받아온다.
			}
			dp[N][j] = min(dp[N][j - 1], tmp);
			dp[N][j] += line[N][j]; // 자기 자신의 작업장에서 일하는 시간을 더해준다
		}
	}

	ll ans = LLONG_MAX;
	for (int N = 1; N <= linenum; N++) {
		ans = min(ans, dp[N][worknum]);
	}

	cout << ans;
	return 0;
}