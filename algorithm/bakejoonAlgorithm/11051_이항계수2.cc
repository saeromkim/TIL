/*
  이항계수를 파스칼의 삼각형을 이용해서 다이나믹으로 푸는 방법이다.
  기존의 방법은 범위가 커지면 값이 터무니 없이 커지기 때문에 O(nk)로 풀 수 있다. 
*/
#include <iostream>
using namespace std;
int d[1001][1001];
int mod = 10007;

int main() {
	int n,k;
	cin>>n>>k;
	for(int i=0; i<=n; i++){
		d[i][0] = d[i][i] = 1; //첫번째 수와 마지막 수는 1이다.
		for(int j=1; j<=i-1; j++){
			d[i][j] = d[i-1][j-1] + d[i-1][j]; //파스칼의 삼각형 정의 이용
			d[i][j] %= mod;
		}
	}
	cout<<d[n][k];
	return 0;
}
