//같은 수를 여러번 골라도 되고, 비내림차순이어야 한다. (오름차순)
//start 인수를 추가하여 start에서부터 숫자를 넣는다.
#include <iostream>
using namespace std;
// bool check[10]; //숫자 사용 여부 체크
int a[10]; 

void go(int index, int start, int n, int m){
	if(index == m){
		for(int i=0; i<m; i++){
			cout<<a[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=start; i<=n; i++){
		a[index] = i;
		go(index + 1, i, n, m);
	}
}

int main() {
	int n,m;
	cin>>n>>m;
	go(0,1,n,m);
	return 0;
}
