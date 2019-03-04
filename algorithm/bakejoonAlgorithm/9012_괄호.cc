/*
  강의 종료 후 복습시작. 자료구조1의 스택의 성질 이용한 첫번째 문제
  괄호 수가 같아야 한다. 그런데 ))(( 과 같은 문자열을 생각해야 한다.
  따라서 카운트로 (가 나오면 + )가 나오면 - 해서 카운트 값이 같으면 yes를 출력한다.
  힌트 조금씩 참고해가며 혼자 풀었다. 푸는 법만 알면 간단한 문제다.
*/
#include <iostream>
#include <stack>
using namespace std;
int a[50];
string s;
int main() {
	int n;
	cin>>n;
	while(n--){
		cin>>s;
		int cnt=0;
		for(int i=0; i<s.size(); i++){
			if(cnt < 0){
				break;
			}

			if(s[i] == '('){
				cnt += 1;
			}else if(s[i] == ')'){
				cnt -= 1;
			}

		}
		if(cnt == 0){
			cout<<"YES" << "\n";
		}else{
			cout<<"NO" << "\n";
		}
	}
	return 0;
}
