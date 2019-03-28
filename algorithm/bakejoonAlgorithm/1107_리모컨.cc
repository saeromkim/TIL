/*
  혼자 못풀고 참고했다
	1. 이동할 채널 c를 정한다.
	2. c에 포함되어있는 숫자 중 고장난 버튼이 있는지 확인(possible());
	3. 고장난 버튼이 포함되어 있지 않다면 |c-n|을 계산해 +/- 버튼을 몇 번 눌러야 하는지 계산
*/
#include <iostream>
#include <cmath>
using namespace std;
bool broken[10];

int possible(int c){
	if(c == 0){ //0이면서 고장난 숫자면 0, 아니면 1
		if(broken[c]){
			return 0;
		}else{
			return 1;
		}
	}
	int len=0;
	//채널숫자를 10의 단위만큼 나누면서 각자릿값을 검사한다.
	while(c>0){
		if(broken[c % 10]){ //고장난 숫자이면 0을 리턴
			return 0;
		}
		len+=1; //아니면 눌러야하는 채널숫자+1
		c/=10;
	}
	return len;
	
}

int main() {
	int n,m;
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int btn;
		cin>>btn;
		broken[btn] = true;
	}
	
	//100만큼 이미 이동했다고 가정
	int ans=0;
	ans = n-100;
	if(ans<0) ans = -ans; //절댓값처리
	
	for(int i=0; i<1000000; i++){
		int c=i;
		int len = 0;
		//c값에서 고장난 버튼 있는지 확인
		len = possible(c); //눌러야하는 채널숫자 횟수 구함
		if(len>0){ //만약 이게 0보다 크면
			int press = c - n; //눌러야하는 +/-의 횟수를 구함
			if(press<0) press= -press;
		
			if(ans > len + press){
				ans = len + press;
			}
		}
	}
	cout<<ans;
	
	return 0;
}
