//피보나치수 점화식을 이용한 간단한 문제
#include <iostream>
using namespace std;
int d[10001];

int main() {
	int n;
	cin>>n;
	d[0]=0; //0과 1은 알고있으니
	d[1]=1;
	for(int i=2; i<=n; i++){ //2부터 해준다. i-2가 있고, 0,1의 값은 이미 알고있으니께
		d[i] = d[i-1] + d[i-2];
	}
	cout << d[n];
	return 0;
}
