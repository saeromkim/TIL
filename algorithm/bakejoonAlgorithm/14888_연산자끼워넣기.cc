/*
  재귀를 이용했다. 혼자 풀었다!
  풀면서 느낀 점!
  - min max 값 설정 유의
  - 문제 풀기 전 혼자 생각할 시간 30분 꼭 갖기!!!!
  - 지금까지 풀이 먼저 보고 어떻게 풀 건지 생각도 안하고 답부터 봤는데..
  - 이제부터는 풀이를 먼저 꼭 생각해봐야겠다.
  - 역시 공부하면 되는구나 생각이 든다. 자신감이 생긴다!!열심히 하자
  - plus, minus, max는 namespace std를 사용하기 때문에 변수 이름이 겹쳐 오류가 뜬다.
  - 변수 이름 정하기 어렵다 ㅠ
*/
#include <iostream>
using namespace std;
int a[101];
int n;
int vplus,vminus,multi,divi;
int vmin=1000000001;
int vmax=-1000000001;
int sum=0;
void go(int i,int sum,int vplus,int vminus,int multi,int divi){
	if(i==n){
		if(vmax<sum){
			vmax=sum;
		}
		if(vmin>sum){
			vmin=sum;
		}
		return;
	}
	if(i>n) return;
	if(vplus>0) go(i+1, sum+a[i], vplus-1,vminus,multi,divi);
	if(vminus>0) go(i+1, sum-a[i], vplus,vminus-1,multi,divi);
	if(multi>0) go(i+1, sum*a[i], vplus,vminus,multi-1,divi);
	if(divi>0) go(i+1, sum/a[i], vplus,vminus,multi,divi-1);
}
int main() {
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	cin>> vplus >> vminus >> multi >> divi;
	go(1,a[0],vplus,vminus,multi,divi); 
	cout << vmax <<'\n';
	cout << vmin <<'\n';
	
	return 0;
} 

