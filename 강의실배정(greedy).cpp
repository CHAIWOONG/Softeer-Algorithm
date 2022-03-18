#include<bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

// 그리디 알고리즘?
// 가장 종료가 빠른 것부터 선택하여 이 후의 강의 시작시간이 겹치지 않는지 확인하여 개수 추가
int n;
vector<pii> vec;
//priority_queue<pii, vector<pii>, greater<int>> mnhp;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int st, en; cin >> st >> en; // 강의 수만큼 시작과 종료시간 입력받아 vec에 저장
		vec.push_back({ en,st }); // 종료시간을 first로 해서 저장
	}

	sort(vec.begin(), vec.end()); // 종료시간이 빠른 순서대로 오름차순 정렬

	int ans = 0, t = 0;
	for (int i = 0; i < n; i++) {
		if (t > vec[i].second) continue; // 시작 시간이 현재 종료시간보다 작으면 제외
		ans++;
		t = vec[i].first; // 시작 시간이 이전 종료시간보다 크면 선택하고 현재 종료시간 update
	}
	cout << ans;
	return 0;
}