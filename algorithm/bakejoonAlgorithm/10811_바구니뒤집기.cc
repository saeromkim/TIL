/*
  stl reverse를 활용하는 문제.
  fill(a.begin()+i, a.end(), i+1); 에서
  a.end()+1을 했다가(왜 했는지 나도 기억안남) 런타임 에러가 떴었다(...)
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n,m;
	cin >> n >> m; // 5 4

	vector<int> a(n);
	for(int i=0; i<n; i++){
		fill(a.begin()+i, a.end(), i+1); //a = {1,2,3,4,5} , 여기 범위 값 유의
	}
	int i,j;
	while(m--){
		cin >> i >> j ; //1 2 
		reverse(a.begin()+i-1, a.begin()+j); //실제 배열에서는 0부터 시작하므로 -1을 해야한다. 
	}
	for(int x : a){
		cout << x << ' ';
	}
	cout << '\n';
	return 0;
}
