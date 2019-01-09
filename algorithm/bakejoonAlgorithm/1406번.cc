/*
에디터
1. scanf/printf사용
2. stack 만든다 왼쪽 오른쪽 두개
3. 문자 입력 받아서 왼쪽에 모두 넣는다.
4. 명령어 입력 받는다
5. 명령어 각각 if문으로 만든다 (이 때, 각 스택이 empty가 아닐 경우에만 진행해야 한다)
6. 왼쪽에 있는 걸 모두 오른쪽 스택으로 옯긴다
7. 오른쪽 스택에 있는걸 모두 출력한다.(하나씩 지우면서 스택이 empty가 될때까지)
*/
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
char a[600000]; //최대 600,000글짜까지 입력할 수 있는 편집기 
int main(){
	//s 문자열(길이 n)
	//m 연산의 수 
	scanf("%s",a); //배열에 문자열 입력받는다 
	stack<char> left,right;
	int n = strlen(a);  //n은 문자열의 길이 	
	for(int i=0; i<n; i++){
		left.push(a[i]);
	}
	
	int m;
	scanf("%d",&m);
	while(m--){
		char c;
		scanf(" %c",&c);
		if(c == 'L'){
			if(!left.empty()){			
				right.push(left.top());
				left.pop();
			}
		}
		if(c=='D'){
			if(!right.empty()){
				left.push(right.top());
				right.pop();
			}
		}
		if(c=='B'){
			if(!left.empty()){
				left.pop();
			}
		}
		if(c=='P'){
			char x;
			scanf(" %c",&x);
			left.push(x);
		}
	}
	while(!left.empty()){
		right.push(left.top());
		left.pop();
	}
	while(!right.empty()){
		printf("%c",right.top());
		right.pop();
	}
	printf("\n");
	return 0;
}
