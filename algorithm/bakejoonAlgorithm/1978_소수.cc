/*
  루트n까지만 검사해서 소수인지 판별하기.
  (소수:약수가 1과 자기 자신 밖에 없는 수. 즉 n이 소수 : 2 ~ n-1 로 나누어 떨어지면 안됨. 
  아래 코드는 2~ n-1 을 2~루트n까지만 검사) 
  go함수는 소수정의를 그대로 이용
  i*i<=n 은 i<=루트n과 같다.
*/
#include <iostream>
using namespace std;
int go(int n){
	if(n<2){
		return false;
	}
	for(int i=2; i*i<=n; i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

int main() {
	int t;
	cin>>t;
	int cnt=0;
	while(t--){
		int n;
		cin>>n;
		if(go(n)){
			cnt+=1;
		};
	}
	cout<<cnt;
	
	return 0;
}
