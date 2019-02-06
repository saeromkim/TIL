/*
  괄호 다이나믹으로 풀기
  코드는 간단한데 점화식은 d[L] = (시그마)d[i-2]*[L-i] 인데
  코드는 왜 저렇게 되는지 이해가 안간다.
  코드는 백준코드 참고했다.
  다시 풀어봐야 겠다.
*/
#include <iostream>
using namespace std;
long long d[2501];
long long mod=1000000007ll;
int main() {
	d[0]=1;
	for(int i=1; i<=2500; i++){
		d[i]=0;
		for(int j=0; j<i; j++){
			d[i] += d[j] * d[i-j-1];
			d[i]%=mod;
		}
		d[i]%=mod;
	}
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<< (n%2==0 ? d[n/2] : 0) <<'\n';
	}
	
	return 0;
}
