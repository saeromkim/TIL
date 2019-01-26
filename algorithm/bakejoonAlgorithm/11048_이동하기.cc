//bottom-up방식
#include <iostream>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	int a[1001][1001];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>a[i][j];
		}
	}
	int d[1001][1001]; //(i,j)로 가야하는 차례일때 지금까지 수의 최댓값 
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			d[i][j]=max(d[i][j-1], max(d[i-1][j],d[i-1][j-1]))+a[i][j]; //최댓값을 이동하면서 계속 추가
		}
	}
	cout<<d[n][m]<<'\n';
	return 0;
}

//top-down방식 n,m에서부터 0,0으로 가며 최댓값을 구한다고 생각
#include <iostream>
using namespace std;
int a[1001][1001];
int d[1001][1001]; //(i,j)로 가야하는 차례일때 지금까지 수의 최댓값 
int go(int i, int j){
	if(i<1 || j<1) return 0; //(i,j)가 0이거나 음수면 0을 리턴 
	if(d[i][j]>=0) return d[i][j]; //-1로 초기화되어있기 때문에 0인 경우에도 메모이제이션 해준다.
	d[i][j]=max(go(i-1,j), max(go(i-1,j-1),go(i,j-1)))+a[i][j];
	return d[i][j];
}
int main() {
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>a[i][j];
			d[i][j]=-1; //입력이 0일 경우를 대비해 -1로 모두 초기화해준다. 거꾸로 계산하기 때문에 해줘야함
		}
	}

	cout<<go(n,m)<<'\n';
	return 0;
}
