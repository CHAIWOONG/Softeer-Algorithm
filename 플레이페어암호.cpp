#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pcc = pair<char,char>;
using pii = pair<int,int>;

string key,msg;
char board[30][30];
int used[30]; // 알파벳 사용 확인
vector<pcc> vec; // 메세지 두글자 나눠 넣기	
pii alpha[30]; // 해당 알파벳이 표에서 위치한 좌표를 저장할 배열

void mkBd(){
	
	int keylen = key.length();
	int bdcnt=0;
	int stR=0, stC=0, keyidx=0;

	while(keyidx!=keylen){
		if(!used[key[keyidx]-'A']){ 
			board[stR][stC] = key[keyidx];
			alpha[key[keyidx]-'A'].X = stR;
			alpha[key[keyidx]-'A'].Y = stC;
		}
		else{
			keyidx++;
			continue;
		}

		used[key[keyidx]-'A']=1;
		keyidx++; bdcnt++; 
		stC++;
		if(stC==5){stC=0; stR++;}
	}

	int stRow = bdcnt/5, stCol = bdcnt%5, idx=0;
	if(bdcnt==25) return; // ***이미 다찼으면 제외 해줘야됨 (예외조건)

	while(1){
		
		if(!used[idx]){ 
			if((char)('A'+idx)=='J'){idx++; continue;}
			board[stRow][stCol] = (char)('A'+idx);
			alpha[idx].X = stRow;
			alpha[idx].Y = stCol;
		}
		else{
			idx++;
			continue;
		}
		used[idx]=1;
		if((stRow==4) && (stCol==4)) break;
		idx++; stCol++;
		if(stCol==5){stCol=0; stRow++;}
	}
}

void msgDiv(){

	int msglen = msg.length();
	int idx=0;

	while(1){

		if(msglen==1){ // 메세지가 한자리였으면 그냥 X랑 짝시키고 종료해야됨
			vec.push_back({msg[idx],'X'});
			break;
		}
		
		if(msg[idx]!=msg[idx+1]){ // 두가지가 서로 다르면 그냥 저장
			vec.push_back({msg[idx], msg[idx+1]});
			idx+=2;
		}
		else if(msg[idx]==msg[idx+1]){ // 두가지가 같을 떄,
			if(msg[idx]=='X'){ // 하나가 X 면 XQ로 저장
				vec.push_back({'X','Q'});
				idx++;
			}
			else{ // 아니면 X넣고 저장
				vec.push_back({msg[idx], 'X'});
				idx++;
			}
		}
		if(idx==(msglen-1)) {vec.push_back({msg[idx], 'X'}); break;} // 하나만 남으면 그냥 X와 같이 저장
		if(idx>=msglen) break;
	}
}

void mkPw(){
	for(auto& element: vec){

		int fIdx = element.first-'A';
		int sIdx = element.second-'A';
		if(alpha[fIdx].X == alpha[sIdx].X){ // 두 글자가 같은 행에 존재하는 경우 (col+1)
			char a,b;
			a = board[alpha[fIdx].X][((alpha[fIdx].Y)+1)%5];
			b = board[alpha[sIdx].X][((alpha[sIdx].Y)+1)%5];
			cout<<a<<b;
		}
		else if(alpha[fIdx].Y == alpha[sIdx].Y){ // 두 글자가 같은 열에 존재하는 경우 (row+1) 
			char a,b;
			a = board[((alpha[fIdx].X)+1)%5][alpha[fIdx].Y];
			b = board[((alpha[sIdx].X)+1)%5][alpha[sIdx].Y];
			cout<<a<<b;
		}
		else if((element.first=='X') && (element.second=='X')) cout<<"ZZ"; //  둘다 X인 경우는 ZZ로 예외
		else{ // 둘다 다른행,열인 경우 서로의 열을 가지도록 변경
			char a,b;
			a = board[alpha[fIdx].X][alpha[sIdx].Y];
			b = board[alpha[sIdx].X][alpha[fIdx].Y];
			cout<<a<<b;
		}
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>msg>>key;

	mkBd(); // 보드 생성
	msgDiv(); // 메세지 분할
	mkPw(); // 

	return 0;
}
