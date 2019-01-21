/*
  재귀로 풀었다. 
  day : 상담 할지 말지 정해야하는 날
  sum : day-1 까지 얻은 수익
  정답인 경우
  불가능한 경우
  다음으로 넘어가는 경우
  이렇게 3가지 경우를 생각하도록 한다
*/
#include <iostream>
using namespace std;
int t[21],p[21];
int n;
int ans=0;
void go(int day,int sum){
	if(day==n+1){ //정답인 경우 : day가 n+1이면 상담을 안할꺼니까 출력한다
		if(ans<sum){ //이익의 최대값을 출력한다
			ans=sum; //이때 ans에 모두 더하는게 아니라 지금 현재의! 이익을 출력한다.
		}
		return;
	}
	if(day>n+1) return; //불가능한 경우: day가 n+1을 넘어갈 수 없다.
	go(day+t[day], sum + p[day]); //다음으로 넘어가는 경우 : 상담 함
	go(day+1, sum); //다음으로 넘어가는 경우 : 상담 안함
}
int main() {
	cin >> n;
	for(int i=1; i<=n; i++){ //일부러 1부터 넣고 거기에 모두 맞췄으나 0부터하고 day==n
		cin >> t[i] >> p[i]; 
	}
	go(1,0); //첫째날부터~
	cout << ans <<'\n';
	
	return 0;
}

