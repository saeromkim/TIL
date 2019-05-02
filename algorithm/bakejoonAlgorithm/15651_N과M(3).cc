//같은 수를 여러번 골라도 되므로, 숫자 사용 여부를 체크 하는 부분이 필요가 없다
#include <iostream>
using namespace std;
// bool check[10]; //숫자 사용 여부 체크
int a[10]; //만든 수열을 넣을 배열

void go(int index, int n, int m){
	if(index == m){
		for(int i=0; i<m; i++){
			cout<<a[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=1; i<=n; i++){
		// if(check[i]) continue;
		// check[i] = true;
		a[index] = i; 
		go(index + 1, n, m);
		// check[i] = false;
	}
}

int main() {
	int n,m;
	cin>>n>>m;
	go(0,n,m);
	return 0;
}
