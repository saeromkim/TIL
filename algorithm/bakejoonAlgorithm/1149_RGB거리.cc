//비교적 쉬운 dp문제..재귀로 풀려다 실패함
#include <iostream>
#include <algorithm>
using namespace std;
int d[1001][3];
int a[1001][3];

int main() {
	int t;
	cin >> t;
	for(int i=1; i<=t; i++){
		for(int j=0; j<=2; j++){
			cin >> a[i][j]; 
		}
	}
	for(int i=1; i<=t; i++){
		d[i][0] = min(d[i-1][1],d[i-1][2]) + a[i][0];
		d[i][1] = min(d[i-1][0],d[i-1][2]) + a[i][1];
		d[i][2] = min(d[i-1][0],d[i-1][1]) + a[i][2];
	}
	cout<<min({d[t][0],d[t][1],d[t][2]});
	return 0;
}
