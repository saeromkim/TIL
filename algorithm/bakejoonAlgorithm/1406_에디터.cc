/*
  커서를 기준으로 왼쪽, 오른쪽 두 개의 스택을 만든 후, 명령어 별로 스택에 넣고 빼면 됨.
  이 문제 처음에 봤을 때 와 저걸 어떻게 풀어..라고 생각하면서 코드 보고 풀었던 기억이 난다.
  지금은 코드를 보지 않고 풀 수 있게 된 걸 보면 공부하면 늘긴 느나 보다
  푸는 방법만 알면 풀 수 있는 쉬운 문제다.
  char와 string 개념이 좀 헷갈렸는데, char는 문자를 한개씩. string은 문자의 집합. 즉 문자열이라고 생각하면 된다.
  stack은 char로만 선언할 수 있다.(문자를 하나씩 넣어야하기때문인가?)
*/
#include <iostream>
#include <stack>
using namespace std;
int main() {
	string s;
	cin>>s;
	stack<char> left;
	stack<char> right;
	//스택에 문자 한개씩 푸시
	for(int i=0; i<s.size(); i++){
		left.push(s[i]);
	}
	int t;
	cin>>t;
	while(t--){
		char order;
		cin >> order;
		if(order == 'L'){
			if(!left.empty()){
				right.push(left.top());
				left.pop();
			}
		}
		if(order == 'D'){
			if(!right.empty()){
				left.push(right.top());
				right.pop();
			}
		}
		if(order == 'B'){
			if(!left.empty()){
				left.pop();
			}
		}
		if(order == 'P'){
			char s;
			cin>>s;
			left.push(s);
		}
	}
	//left의 값들을 모두 right으로 이동
	while(!left.empty()){
		right.push(left.top());
		left.pop();
	}
	//right값들을 출력
	while(!right.empty()){
		cout<<right.top();
		right.pop();
	}
	return 0;
}
