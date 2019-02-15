/*
  nCk 즉, n개 중에서 k개를 고르는 문제다.
  n! / (k!*(n-k)!) 식을 이용하면 된다.
*/
#include <iostream>
using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	int ans=1;
	for(int i=1; i<=n; i++){
		ans *= i;
	}
	for(int i=1; i<=k; i++){
		ans /= i;
	}
	for(int i=1; i<=n-k; i++){
		ans /= i;
	}
	cout<<ans;
	return 0;
}
