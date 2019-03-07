//a진법을 b진법으로 바꾸기
//생각하기 귀찮아서 코드보고 이해함
#include <iostream>
#include <string>
using namespace std;
//b진법으로 바꾸는 함수
void convert(int num, int base){
	if(num ==0) return; 
	convert(num/base,base); //ans/b를 재귀 
	printf("%d ",num%base); //재귀하면서 하나씩 나머지 출력
}

int main() {
	int a,b;
	cin>>a>>b;
	int n;
	cin>>n;
	int ans = 0;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		ans = ans*a + x; //먼저 a진법 구하기
	}
	convert(ans,b);
	return 0;
}
