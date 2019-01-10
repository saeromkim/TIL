/*
테스트케이스의 개수를 알 수 없는 경우다.
while문안에 입력을 받을 동안만 루프를 돌게 해주면 된다.
*/
#include <iostream>
using namespace std;
int main(){
	int a,b;
	while(cin >> a >> b){
		cout << a+b << '\n';
	}
	return 0;
}
