/*
	0의 개수는 5의 개수만 알면 됐으나,
  조합에서 0의 개수는 2와 5의 개수 모두를 알아야 한다.
  문제에서 m과 n의 범위는 20억으로, nCm을 할 경우 int범위가 넘어가므로 long long 을 사용해야함.
  조합 공식을 그대로 구현하면 된다. mCn = (m! / n!) / (m-n)!
*/
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	long long m,n;
	cin>>m>>n;
	long long t=0,f=0;
  //조합 공식에 따라, 먼저 m까지의 2와 5의 개수를 구하고,
	for(long long i=2; i<=m; i*=2){
			t += m/i;
	}
  for(long long i=5; i<=m; i*=5){
			f += m/i;
	}
  //m-n에서 2와 5를 한 번씩 빼고, n까지의 2와 5의 개수를 또 뺀다.
	for(long long i=2; i<=m-n; i*=2){
			t -= (m-n)/i;
	}
	for(long long i=2; i<=n; i*=2){
			t -= n/i;
	}
	for(long long i=5; i<=m-n; i*=5){
			f -= (m-n)/i;
	}
	for(long long i=5; i<=n; i*=5){
			f -= n/i;
	}
	cout<<min(t,f);
	return 0;
}
