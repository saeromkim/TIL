#include <iostream>
#include <cstring> //memset을 쓰기 위한 헤더파일
using namespace std;
int a[2001];
int d[2001][2001]; //(i,j)로 가야하는 차례일때 지금까지 수의 최댓값 
int n,m;
int go(int i, int j){
	if(i==j) { //i부터 j까지를 검사하는데 둘이 같다, 즉 길이가 1일 경우는 1을 리턴한다. 
		return 1;
	}else if(i+1==j){ //길이가 2일 경우(i=1, j=2라면, 1+1=2 성립)
		if(a[i]==a[j]) return 1; //첫번째, 두번째 둘다 같으면 1(aa)
		else return 0; //아니면(ab) 0
	}
	if(d[i][j]>=0) return d[i][j]; //여기서 0이거나 양수일 경우 메모이제이션을 해준다. (-1로 초기화 하므로, 0을 꼭 포함해야 함에 주의)
	if(a[i]!=a[j]) return d[i][j] = 0; //양 끝이 다르면 0
	else return d[i][j]=go(i+1,j-1); //양 끝이 다르면 그 다음 두 숫자 팰린드롬 검사한다.
}
int main() {
	//시간초과가 자꾸 나서 추가해줌
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  
	cin>>n;
	for(int i=1; i<=n; i++){
			cin>>a[i];
	}
	memset(d,-1,sizeof(d)); //d[][]의 값을 모두 -1로 초기화해준다.
	int m;
	cin>>m;
	int s,e;
	for(int i=1; i<=m; i++){
			cin>>s>>e;
			cout<<go(s,e)<<'\n';
	}
	return 0;
}
