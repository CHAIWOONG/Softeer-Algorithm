#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll mod = 1000000007;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll k, p, n;
	ll ans;
	cin >> k >> p >> n;

	ans = k * p % mod;
	n--;
	while (n--) {
		ans = ans * p % mod; // �ð����⵵�� ���� �Ź� mod�� �����༭ �����ؾ� �Ѵ�
	}

	cout << ans;
	return 0;

}