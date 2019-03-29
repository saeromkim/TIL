/*
  1~n까지 모든 값의 자릿수를 더하며
  10 , 100, 1000 ...일 때마다 더하는 j값을 +1해준다
*/
#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int cmp=10;
	int j=1;
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(i==cmp){
			cmp*=10;
			j++;
		}
		cnt+=j;
	}
	cout<<cnt;
	
	return 0;
}
