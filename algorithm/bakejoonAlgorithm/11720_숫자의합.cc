/*
  숫자 하나씩 입력 받을 때 %1d를 쓰면 된다
*/
#include <iostream>
using namespace std;

int main() {
	int t,sum=0,n;
	cin>>t;
	while(t--){
		scanf("%1d",&n);
		sum+=n;
	}
	printf("%d",sum);
	return 0;
}
