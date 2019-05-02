//내가 푼거. 다시 품
#include <iostream>
using namespace std;
bool check[10]; //숫자 사용 여부 체크
int a[10]; //만든 수열을 넣을 배열

void go(int index, int start, int n, int m){ //start라는 인수 추가
	if(index == m){
		for(int i=0; i<m; i++){
			cout<<a[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=start; i<=n; i++){ //start부터 숫자 넣기
		if(check[i]) continue;
		check[i] = true;
		a[index] = i; 
		go(index + 1, i+1, n, m); //1을 넣었다면 2를 start로 
		check[i] = false;
	}
}

int main() {
	int n,m;
	cin>>n>>m;
	go(0,1,n,m);
	return 0;
}

//n과m(1) 변형
#include <iostream>
using namespace std;
int c[10];
int a[10];
void go(int index, int start, int n, int m){
	if(index==m){
		for(int i=0; i<m; i++){
			cout << a[i] << ' ';
		}
		return;
	}
//start부터 항상 시작하므로 c[]가 필요없다. 항상 방문하지 않은 수만 넣기 때문
	for(int i=start; i<=n; i++){
		// if(c[i]) continue;
		// c[i]=true; 
		a[start]=i;
		go(index+1,i+1,n,m);
		// c[i]=false;
	}
}

int main() {
	int n,m;
	cin>>n>>m;
	go(0,1,n,m);
	cout << '\n';
	return 0;
}

