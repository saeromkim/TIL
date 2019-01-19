/*
  stl강의에서 fill을 이용하는 문제
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n,m;
	cin >> n >> m;

	vector<int> a(n); //정답 코드에서는 a(n,0) 이렇게 초깃값을 0으로 해줌.
	int i,j,k;
	while(m--){
		cin >> i >> j >> k ;
		fill(a.begin()+i-1, a.begin()+j, k);
	}
	for(int x : a){
		cout << x << ' ';
	}
	cout << '\n';
	return 0;
}
