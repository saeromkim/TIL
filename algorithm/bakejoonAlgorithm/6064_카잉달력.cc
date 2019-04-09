/*
	첫번째 방법))
	x,y의 최소공배수를 넘겼을 때 -1
	m*i+x == n*j+y 일때 정답
	만약 둘 중 어느 하나가 크거나 작을 경우 i와j의 값을 1씩 더하면서 다시 체크
	두번째 방법))
	위의 식을 일반화 하면 10*i-6 = 12*j이다.
	10*i-6 % 12가 0이면 12의 배수라는 뜻이므로..
	그때 답이 된다.
*/
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	return 0;
}
