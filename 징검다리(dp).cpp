#include<bits/stdc++.h>

using namespace std;

// dp ���� �κ���������?
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
		int len = 0; // �Ź� �ش� idx���� ���� �� �ִ� ���� ���� ����
		for (int j = 1; j <= i; j++) { // �ش� idx�� ���� ������ Ȯ�� ����
			if (arr[j] < arr[i]) {
				if (len < dp[j]) len = dp[j];
				// �ش�idx �� ���� ������ ū��, ����� ���̰� Ȯ���� ���̺��� ��ٸ� update 
			}
		}
		dp[i] = len + 1; // �ڱ��ڽ� �־ len+1�ؼ� update
		ans = max(dp[i], ans);
	}

	cout << ans;
	return 0;
}