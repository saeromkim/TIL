/*
  인접 행렬의 제곱을 이용해서 해결하는 문제
  그래프로 분류되어 있고 코드를 이해하기 쉽지 않다. 
  우선 차근차근 읽어보긴 했는데 정확하게 이해가 가질 않는다.
*/

#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<bool>> matrix;
matrix operator * (const matrix &a, const matrix &b){
	int n = a.size();
	matrix c(n, vector<bool>(n));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				if(a[i][k] && b[k][j]){
					c[i][j] = true;
				}
			}
		}
	}
	return c;
}
matrix pow(matrix a, int m){
	int n = a.size();
	matrix ans(n, vector<bool>(n));
	for (int i=0; i<n; i++) ans[i][i] = true;
	while(m>0){
		if(m % 2 == 1) {
			ans = ans * a;
		}
		a = a * a;
		m /= 2;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, m;
	cin >> n >> k >> m;
	matrix a(n, vector<bool>(n));
	for(int i=0; i<n; i++){
		int x, y;
		cin >> x>> y;
		a[i][x-1] = true;
		a[i][y-1] = true;
	}
	matrix ans = pow(a, k);
	while (m--) {
		int x, y;
		cin >> x >> y;
		if(ans[x-1][y-1]){
			cout << "death" << '\n';
		} else {
			cout << "life" << '\n';
		}
	}
	return 0;
}
