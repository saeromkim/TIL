/*
  stl강의에서 fill을 이용하는 문제
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n,m;
	cin >> n >> m; // 5 4

	vector<int> a(n); //정답 코드에서는 a(n,0) 이렇게 초깃값을 0으로 해줌.
	int i,j,k;
	while(m--){
		cin >> i >> j >> k ; //1 2 3 
		fill(a.begin()+i-1, a.begin()+j, k); // 0+1-1= 0번째 부터 0+2(인데 2번은 제외) 까지,  3번으로 채우기
	}
	for(int x : a){
		cout << x << ' ';
	}
	cout << '\n';
	return 0;
}
