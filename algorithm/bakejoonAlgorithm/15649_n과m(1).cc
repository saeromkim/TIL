//정답
//재귀함수를 이용함. 백준 
// m이 2일 때, _ _ 를 자리수라고 쳤을 때 첫번째 자리를 i=1일때 재귀~~ i=2일때 재귀~~ 이런식으로 돌림
//첫번째 자리 정하고, 
#include <iostream>
#include <algorithm>
using namespace std;
bool c[10]; int a[10];
void go(int index, int n, int m){
	if(index==m){
		for(int i=0; i<m; i++){
			cout << a[i]<<'\n';
		}
		return;
	}
	for(int i=1; i<=n; i++){
		if(c[i]) continue; 
		c[i]=true; a[index]=i;
		go(index+1,n,m);
		c[i]=false;
	}
}
int main(){
	int n,m;
	cin >> n>>m;
	go(0,n,m);
	
	return 0;
}

//처음 풀었을 때
//도저히 모르겠어서 검색후 이해함
//방문한 곳을 체크하여 그곳을 제외하고, 재귀함수를 사용하여 순서대로 출력한다.
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
bool visit[10];
int arr[10];

void func(int cnt){
	if(cnt==m){
		for(int i=0; i<m; i++){ //m길이만큼 출력
			cout << arr[i] + 1 << ' '; //현재 arr에서 1을 더한 값을 출력한다. 
		}
		cout<<'\n';
	}
	for(int i=0; i<n; i++){ //n만큼 반복한다
		if(!visit[i]){ //방문한적이 없을 때
			visit[i] = true; //방문했다고 체크
			arr[cnt] = i; // 현재 순서 저장
			func(cnt + 1); //다음 순서에 재귀함수 호출
			visit[i] = false; //다음 줄에서 다시 체크할 수 있게 방문값 초기화
		}
	}
}

int main(){
	 cin >> n >> m;
	 func(0); //
  
	 return 0;
}
