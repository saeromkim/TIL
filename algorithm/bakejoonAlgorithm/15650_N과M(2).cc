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

