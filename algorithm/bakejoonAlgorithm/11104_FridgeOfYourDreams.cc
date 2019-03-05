//2진수를 10진수로 변환하는 문제. stl bitset을 이용하면 간단.
#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		bitset<24> n;
		cin>>n;
		cout<<n.to_ulong()<<'\n';
	}
	return 0;
}
