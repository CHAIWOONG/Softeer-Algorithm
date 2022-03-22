#include<bits/stdc++.h>

using namespace std;

int T,n;
vector<int> vec;
int arr[100001];
int used[100001];

// two pointer?

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){

		cin>>n;
		for(int i=0; i<n; i++) cin>>arr[i];

		if(n==1){ // 한개 주어지면 그거에 대해 출력후 종료
			
			fill(arr,arr+n,0);
			cout<<"1\n"; break;
		}


		
		sort(arr, arr+n, greater<int>()); // 내림차순 정렬
		int ans=0, en=n-1, numThree = 0;;

		while(en>=0){
			if(arr[en]==300){
				used[en]=1;
				en--;
				numThree++;
				continue;
			}
			else break;
		}
		int last=0;
		// 301 ~ 600에 대해서 진행
		for(int st=0; st<n; st++){
			int tmpst = arr[st]; // 남아있는 것 중에서 가장 큰 메모리 값
			if(used[st]) break;
			if(used[st+1]) {// st가 확인하는게 사용되었으면 다 확인이므로 종료
				if(tmpst+300<=900 && numThree){
						numThree--;
						ans++;
						break;
				}
				else { ans++; break;}
			} 
			used[st]=1;

			if(tmpst>=601){ // 601 ~ 900이면 어짜피 하나 차지하므로 넘김
				ans++;
				continue;
			}

			int tmp = tmpst; // 메모리에 시작은 일단 저장
			int flag = 0;
			while(1){
				if(flag) break;

				if((tmp+arr[en])<900){
				// 더 넣을 수 있는지 확인하러 간다
					//if(used[en]) break;
					tmp+=arr[en];
					used[en]=1;
					en--; 
					continue;
				}
				else if((tmp+arr[en])==900){
				// 여기 까지 넣은 걸로 마무리 하고 다음 체크
					used[en]=1;
					en--;
					ans++;
					tmp = 0;
					break;
				}
				else if((tmp+arr[en])>900){ 
				//  그전까지 넣은걸로 마무리 후 다음 체크 

					if(tmp+300<=900 && numThree){
						tmp=0;
						flag=1;
						numThree--;
						ans++;
						break;
					}

					tmp = 0;
					ans++;
					break;
				}
			}
		}
		ans += (numThree+2)/3;

		cout<<ans<<"\n";
		fill(arr,arr+n,0);
		fill(used,used+n,0);
	}
	return 0;
}
