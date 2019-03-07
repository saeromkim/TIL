/*
  2부터 루트n까지 for문을 돌면서 
  n을 나눌 수 있으면 나눌 수 없을 때까지 계속 나누면 됨.
*/
#include <iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	for(int i=2; i*i<=n; i++){
		while(n%i==0){
			cout<<i<<"\n";
			n=n/i;
		}
	}
	if(n>1){
		cout<<n;
	}
	return 0;
}
