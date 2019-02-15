//90번째 피보나치수는 int범위를 초과하기 때문에 long long으로 바꿔야함
#include <iostream>
using namespace std;
long long d[10001]; //이 부분만 long long으로 바꾸면 됨

int main() {
	int n;
	cin>>n;
	d[0]=0; 
	d[1]=1;
	for(int i=2; i<=n; i++){ 
		d[i] = d[i-1] + d[i-2];
	}
	cout << d[n];
	return 0;
}
