#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int linenum, worknum;

int line[101][101]; // [i][j] = i ���ο��� j �۾��忡���� �ð�
int swtch[101][101][101]; //[i][j][k] = i ������ j �۾��忡�� k������ j+1 �۾������� ���µ� �ɸ��� �ð�

ll dp[101][101];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> linenum >> worknum;

	for (int j = 1; j <= worknum; j++) {
		for (int N = 1; N <= linenum; N++) { // ������ ����ŭ �޴´�.
			cin >> line[N][j];
		}
		if (j == worknum) break;  // ������ �۾����� ���� �۾������� ���°� ����

		for (int N = 1; N <= linenum; N++) { // ������ ����ŭ �޴´�.
			for (int otN = 1; otN <= linenum; otN++) {
				if (otN == N) continue;
				cin >> swtch[N][j][otN];
			}
		}
	}

	for (int N = 1; N <= linenum; N++) { // �� ���κ� ù �۾����� �����ð��� �־ �ʱ�ȭ
		dp[N][1] = line[N][1];
	}

	for (int j = 2; j <= worknum; j++) {

		for (int N = 1; N <= linenum; N++) {

			ll tmp = LLONG_MAX;
			for (int otN = 1; otN <= linenum; otN++) {
				if (otN == N) continue;
				tmp = min(tmp, dp[otN][j - 1] + swtch[otN][j - 1][N]); // �۾��� �̵����� ���� ���� �ð��� �޾ƿ´�.
			}
			dp[N][j] = min(dp[N][j - 1], tmp);
			dp[N][j] += line[N][j]; // �ڱ� �ڽ��� �۾��忡�� ���ϴ� �ð��� �����ش�
		}
	}

	ll ans = LLONG_MAX;
	for (int N = 1; N <= linenum; N++) {
		ans = min(ans, dp[N][worknum]);
	}

	cout << ans;
	return 0;
}