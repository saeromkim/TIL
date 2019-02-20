/*
  다이나믹 (재귀/top-down)문제. 난 재귀 이용하는게 더 편하고 익숙하다
  점화식만 잘 세우면 무난하다. 진짜 다이나믹 문제들은 다 비슷해서 오히려 쉽게 느껴진다 ㅠㅠ 
  일부러 어려운 문제들을 풀게하고 그 전 문제들은 쉽게 느껴지게 하는게 백준님 전략인가보다..
  d[i][j] = (i,j)에서 시작해서 (n,m)으로 가는 내리막 길의 개수
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[500][500];
int d[500][500];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n, m;
int dp(int x, int y){
	if(x == n-1 && y == m-1) return 1; //n-1,m-1이면 도착
	if(d[x][y] != -1) return d[x][y]; //d[][]에 -1이 아닌 값이 있다는 건 이미 계산 했다는 것
  d[x][y]=0;  //0으로 초기화한다. 그래야 음수에 계속 값을 더하지 않음.
	for(int k=0; k<4; k++){
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m){
			if(a[x][y] > a[nx][ny]){ //배열의 상화좌우 중 작은 값이 있으면
				d[x][y] += dp(nx,ny); //dp한 값을 d에 넣는다.
			}
		}
	}
	return d[x][y]; 
}
int main() {
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
		}
	}
	memset(d,-1,sizeof(d)); //최솟값 비교를 위해 모두 -1로 초기화 한다.
	cout << dp(0,0); //(0,0)부터 재귀 시작
	return 0;
}
