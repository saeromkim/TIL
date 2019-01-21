//재귀를 이용하는 문제다. 전역변수를 적절히 잘 활용하도록 하자. 
#include <iostream>
#include <vector>
using namespace std;
vector<int> num(20);
int n,s;
int cnt=0;
void go(int i,int sum){
	if(i==n){
		if(sum==s){
			cnt += 1;
		}
		return;
	}
	go(i+1, sum + num[i]);
	go(i+1, sum);
}
int main() {
	cin >> n >> s;
	for(int i=0; i<n; i++){
		cin >> num[i];
	}
	go(0,0);
	if(s==0) cnt -= 1; //sum이 0이면 아무것도 포함하지 않는 경우를 빼준다. 즉 공집합을 제외해야함.
	cout << cnt <<'\n';
	
	return 0;
}

