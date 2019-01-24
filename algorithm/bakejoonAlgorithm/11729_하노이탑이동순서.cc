/*
  분할 정복 문제로 큰 문제에서 작은 문제로 쪼갠 방법이다.
  하노이탑에서 1~(n-1)까지를 x->y로 이동하려면
   1. 1~(n-1)개를 x->z
   2. n을(젤 밑에 꺼) 를 x->y
   3. 다시 1~(n-1)개를 z->y 
   순서로 해야한다.
   
   총 이동 횟수는 일반식인 (2^n)-1 로 간단하게 구할 수 있는데,
   비트연산을 사용해서 (1<<n)-1로 표현했다.
   
   (0000 0001을 왼쪽으로 한번씩 이동하면 2의 거듭제곱으로 수가 늘어난다.
   예를 들어, 1 << 3 은 2^n과 같다.)
*/
#include <iostream>
using namespace std;
//n개의 원판을 x에서 y로 이동하는 함수;
void solve(int n, int x, int y){
	if(n==0) return;
	solve(n-1, x, 6-x-y);
	printf("%d %d\n", x, y);
	solve(n-1, 6-x-y, y);
}

int main() {
	int n;
	scanf("%d",&n);
	printf("%d\n",(1<<n)-1); //(2^n)-1
	solve(n,1,3); 
	return 0;
}
