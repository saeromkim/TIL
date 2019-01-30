/*
  dp다. d[i][j]는 i번째 곡을 j 볼륨으로 연주할 수 있으면 1, 아니면 0이다.
  for문 범위때문에 정말 헤맸다. ㅠㅠ
  breakpoint를 걸면서 디버깅한 값을 보면서 표를 그려 정리해보니 이해가 되었다.
  범위가 헷갈릴때 처음상태를 0번째 배열에 넣는다고 생각 해주면 될 것이다.
*/
#include <iostream>
using namespace std;
int v[101];
bool d[101][1001]; //bool형은 전역변수로 선언시 0으로 초기화된다.
int main() {
	//입력값 받기
	int n,s,m;
	cin>>n>>s>>m;
	for(int i=1; i<=n; i++){
		cin>>v[i];
	}
	d[0][s]=true; //첫번째 볼륨을 설정해준다.
	/*
		아래는 dp
		i일때 i+1번째의 곡에 가능한 숫자를 비교해야하므로 
		n번째까지 한다면 n+1번째까지 값을 넣는다. 
		그러므로 0번부터 n-1번까지 해야 1번부터 n번째 곡에 가능한 볼륨을 체크할 수 있다.
	*/
	for(int i=0; i<n; i++){ 
		for(int j=0; j<=m; j++){ //j는 현재 볼륨숫자
			if(d[i][j]==false){
				continue;
			}else{ 
				if(j-v[i+1] >= 0){
					d[i+1][j-v[i+1]]=true;
				}
				if(j+v[i+1] <= m){
					d[i+1][j+v[i+1]]=true;
				}
			}
		}
	}
	int ans=-1;
	for(int i=0; i<=m; i++){
		if(d[n][i]){
			ans=i;
		}
	}
	
	cout<<ans<<'\n';

}
