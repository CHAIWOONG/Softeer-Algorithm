#include<bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

// �׸��� �˰���?
// ���� ���ᰡ ���� �ͺ��� �����Ͽ� �� ���� ���� ���۽ð��� ��ġ�� �ʴ��� Ȯ���Ͽ� ���� �߰�
int n;
vector<pii> vec;
//priority_queue<pii, vector<pii>, greater<int>> mnhp;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int st, en; cin >> st >> en; // ���� ����ŭ ���۰� ����ð� �Է¹޾� vec�� ����
		vec.push_back({ en,st }); // ����ð��� first�� �ؼ� ����
	}

	sort(vec.begin(), vec.end()); // ����ð��� ���� ������� �������� ����

	int ans = 0, t = 0;
	for (int i = 0; i < n; i++) {
		if (t > vec[i].second) continue; // ���� �ð��� ���� ����ð����� ������ ����
		ans++;
		t = vec[i].first; // ���� �ð��� ���� ����ð����� ũ�� �����ϰ� ���� ����ð� update
	}
	cout << ans;
	return 0;
}