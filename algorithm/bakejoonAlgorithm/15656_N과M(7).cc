//N개의 자연수 중에서 M개를 고른 수열, 같은 수 여러번 가능
//num 배열을 입력받아 배열 안의 숫자를 순서대로 넣으면 됨
//check 필요없음
#include <iostream>
#include <algorithm>
using namespace std;
// bool check[10]; 
int a[10]; 
int num[10]; //주어지는 n개의 자연수

void go(int index, int n, int m){
	if(index == m){
		for(int i=0; i<m; i++){
			cout<<a[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=0; i<n; i++){
		// if(check[i]) continue;
		// check[i] = true;
		a[index] = num[i];
		go(index + 1, n, m);
		// check[i] = false;
	}
}

int main() {
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>num[i];
	}
	sort(num, num+n);
	go(0,n,m);
	return 0;
}
