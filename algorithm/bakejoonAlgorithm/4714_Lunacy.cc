/*
  소수점 자릿수 출력 연습하기 좋았던 문제.cout 고집을 버리고 편한 printf쓰자.
*/
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	float n;
	while(cin>>n){
		if(n<0) break;
		cout<<"Objects weighing ";
		printf("%.2f",n);
		cout<<" on Earth will weigh ";
		n=n*0.167;
		round(n);
		printf("%.2f",n);
		cout<<" on the moon.\n";
	}
	return 0;
}
