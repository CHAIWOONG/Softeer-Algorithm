#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int,int>;

int n;
queue<int> q[4]; // (0-A, 1-D, 2-C, 3-B)
queue<int> inputq[4]; // 도로별 차량 입력 vector에 대해서 들어오는 시간과 나가는 시간을 저장 
char input[200001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n; 
	//int ACmint = INT_MAX, BDmint = INT_MAX;
	int mint = INT_MAX;

	for(int i=1; i<=n; i++){
		int t; char c; cin>>t>>c;
		mint = min(t,mint);
		input[i] = c;
		if(c=='A') q[0].push(t);
		else if(c=='B') q[3].push(t);
		else if(c=='C') q[2].push(t);
		else if(c=='D') q[1].push(t);
	}

	int tmpt = mint; // 시뮬레이션 시작 시간의 설정

	while(1){
		int ACflag=0, BDflag=0;
		int Aflag=0, Bflag=0, Cflag=0, Dflag=0;

		int minqt = INT_MAX;
		for(int i=0; i<4; i++){
			if(q[i].empty()) continue;
			minqt = min(minqt, q[i].front());
		}
		if(minqt >= tmpt) tmpt = minqt;

		for(int i=0; i<4; i+=2){ // A와 C에 대해 동시확인

			if(q[i].empty()) continue;
			int headCar = q[i].front();

			if(headCar>tmpt) continue; // 아직 들어온 차가 아니므로 제외
			else if(headCar<=tmpt){ // 이미 들어와있는 차일 때, 

				int rRoad = (i+1)%4;// 오른쪽 도로상황 check

				if(q[rRoad].empty()){ // 오른쪽이 비어있으면 그냥 지나가면 된다.
					q[i].pop();
					inputq[i].push(tmpt);
					ACflag=1;
					continue;
				}
				// 비어있지 않은 경우,
				if(q[rRoad].front()<=tmpt){  // 오른쪽 차량이 우선순위이므로
					if(i==0) Aflag=1; // A 못감
					else Cflag=1;
					continue;
				}
				else if(q[rRoad].front()>tmpt){ // 오른쪽에 차량이 아직 안들어온 차량이면
					q[i].pop();
					inputq[i].push(tmpt);
					ACflag=1;
				}
			}
		}
		if(ACflag) tmpt++;
	
		for(int i=1; i<4; i+=2){ // B와 D에 대해 동시확인

			if(q[i].empty()) continue;
			int headCar = q[i].front();

			if(headCar>tmpt) continue; // 아직 들어온 차가 아니므로 제외
			else if(headCar<=tmpt){ // 이미 들어와있는 차일 때, 
			
				int rRoad = (i+1)%4;

				if(q[rRoad].empty()){
					q[i].pop();
					inputq[i].push(tmpt);
					BDflag=1;
					continue;
				}

				if(q[rRoad].front()<=tmpt){  // 오른쪽 차량이 우선순위이므로
					if(i==1) Dflag=1; // A 못감
					else Bflag=1;
					continue;
				}
				else if(q[rRoad].front()>tmpt){
					q[i].pop();
					inputq[i].push(tmpt);
					BDflag=1; 
				}
			}
		}
		if(BDflag) tmpt++;
		else if(ACflag==0 && BDflag==0) tmpt++; // 둘다 안움직였으면 시간 일단 흐름

		if(q[0].empty()&&q[1].empty()&&q[2].empty()&&q[3].empty()) break; // 전부 비었으면 종료
		if(Aflag==1 && Bflag==1 && Cflag==1 && Dflag==1) break; // 전부 교착상태
	}

	for(int i=1; i<=n; i++){
		char c = input[i];
		if(c=='A') {
			if(inputq[0].empty()){
				cout<<"-1\n";
				continue;
			}
			cout<<inputq[0].front()<<"\n";
			inputq[0].pop();
		}
		else if(c=='B') {
			if(inputq[3].empty()){
				cout<<"-1\n";
				continue;
			}
			cout<<inputq[3].front()<<"\n";
			inputq[3].pop();
		}
		else if(c=='C') {
			if(inputq[2].empty()){
				cout<<"-1\n";
				continue;
			}
			cout<<inputq[2].front()<<"\n";
			inputq[2].pop();
		}
		else if(c=='D') {
			if(inputq[1].empty()){
				cout<<"-1\n";
				continue;
			}
			cout<<inputq[1].front()<<"\n";
			inputq[1].pop();
		}
	}
	return 0;
}
