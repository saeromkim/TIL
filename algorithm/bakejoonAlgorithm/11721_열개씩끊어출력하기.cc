/*
  c++보다 c를 사용했을 때 더 간단한 문제
  char 유형을 쓰는 것에 익숙하지 않은데 더 연습하자
  *scanf함수 내에서 지역 변수에 접근하기 위해서는 해당 변수의 주소를 알아야한다. 
  따라서 &를 붙여준다.
  char를 사용할 때 scanf("%10s",s) 여기서 s, 배열이름 s는 배열의 주소를 나타내므로 & 연산을 할 필요가 없다. 
*/
#include <cstdio>
using namespace std;

int main() {
	char s[101]; //c에서는 char사용한다. 배열처럼 쓸 수 있다.
  while(scanf("%10s",s)==1){ //10개씩 받았을때
		printf("%s\n",s); //출력한다.
	}
	return 0;
}
