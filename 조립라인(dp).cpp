#include<bits/stdc++.h>

using namespace std;

int n;
int a[1005]; // ai �۾����� �۾��ð�
int ab[1005]; // ai���� bi+1���� �̵��ð�
int b[1005]; // bi �۾����� �۾��ð�
int ba[1005]; // bi���� ai+1���� �̵��ð�

// dp?
// dp[0][i] = min(dp[0][i-1],dp[1][i-1]+ba[i-1])�� ����
// ���¿� ���ؼ� ��ȭ�� ���� ���� ���� �ΰ��� ��쿡�� �������� ���ؼ� �ּҰ� ����

int dp[2][1005]; // 0= a, 1=b �� ��

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
	dp[1][0] = b[0]; // �ʱ� �� �Ҵ�

	for (int i = 1; i <= n; i++) {

		dp[0][i] = min(dp[0][i - 1], dp[1][i - 1] + ba[i - 1]);
		dp[0][i] += a[i];

		dp[1][i] = min(dp[1][i - 1], dp[0][i - 1] + ab[i - 1]);
		dp[1][i] += b[i];
	}

	cout << min(dp[0][n], dp[1][n]);
	return 0;
}