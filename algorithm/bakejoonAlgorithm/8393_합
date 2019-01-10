/*
초간단한 문제지만 매우매우매우 해멨다.
while문을 쓰니 sum이 초기화되지 않아 틀렸다고 나온다는데...
에디터로는 잘돌아가는데 이유를 모르겠다..ㅠㅠ

#include <iostream>
using namespace std;
int main(){
	int n;
	int sum,i=0;
	cin >> n;
	
	while(n--){
		i++;
		sum+=i;
	}

	cout << sum;
	return 0;
}

이유를 알았다..질문글 올리니 누가 답변해줌

int n,sum,i = 0; 이라는 구문은 세 변수를 다 0으로 초기화시켜주는게 아니라, 맨 끝에 있는 i만 0으로 초기화 시켜줍니다. 초기화되지 않은 나머지 두 값은 쓰레기값이 들어가 있겠죠.

sum도 0으로 초기화 해주시려면 int n, sum=0,i=0;이라고 써주셔야합니다.
*/

//whlie문으로 풀기도 가능하다!!!
#include <iostream>
using namespace std;
int main(){
	int n;
	int sum=0,i=0;
	cin >> n;
	
	while(n--){
		i++;
		sum+=i;
	}

	cout << sum;
	return 0;
}
