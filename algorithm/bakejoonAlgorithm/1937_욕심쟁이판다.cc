/*
  다이나믹 프로그래밍. 내리막길이랑 비슷한 문제
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[500][500];
int d[500][500];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n;
int dp(int x, int y){
	if(d[x][y] != 0) return d[x][y];
	d[x][y] = 1;
	for(int k=0; k<4; k++){
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(nx >= 0 && nx < n && ny >= 0 && ny < n){
			if(a[x][y] < a[nx][ny]){
				d[x][y] = max(d[x][y], dp(nx,ny) + 1); //가장 큰 수를 d[][]에 저장
			}
		}
	}
	return d[x][y];
}
int main() {
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			ans = max(ans, dp(i,j)); //모든 칸에 대해 dp한 후, 최댓값 구한다. (판다를 어느 지점에 풀어놓아야 하는지)
		}
	}
	cout << ans;
	return 0;
}
