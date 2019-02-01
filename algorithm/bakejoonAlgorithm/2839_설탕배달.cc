/*
  설탕 n개를 5개씩, 3개씩 딱맞게 몇봉지가 필요한지 구하는 문제
  나누어떨어지지 않으면 -1을 출력
  큰 숫자인 5부터 담으면서 n개에서 -5, -3씩 한다고 생각. count로 센다.
  사실 조건을 10개 가까이 걸면서 풀었으나 삽질이었다
  검색해서 품
*/
#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int count=0;
	while(n>0){
		if(n%5==0){
			n-=5;
			count++;
		}
		else if(n%3==0){
			n-=3;
			count++;
		}
		else if(n>5){ 
			n-=5;
			count++;
		}
		else{
			count=-1;
			break;
		}
	}
	cout<<count;
	return 0;
}
