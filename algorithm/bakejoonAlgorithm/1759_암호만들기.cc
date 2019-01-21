/*
  재귀사용하는 문제..겁나 어렵군
  재귀문제는 좀더 많이 풀어보면서 익혀야겠다. 아직까진 많이 낯설다.
  이제 2문제 정도 풀어본게 다니까 조급하게 생각하지 말아야겠다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//자음 모음 체크 함수
bool check(string &pwd){
	int ja=0;
	int mo=0;
	for(char x:pwd){
		if(x=='a' || x=='e'||x=='i'||x=='o'||x=='u'){
			mo+=1;
		}else{
			ja+=1;
		}
	}
	if(ja>=2 && mo>=1){
		return true;
	}else{
		return false;
	}
}
//재귀함수
void go(int n, vector<char> &alpha, string pwd, int i){ //파라미터에 벡터 받을 때 &로 포인터로 받는 것 명
	if(n==pwd.length()){
		if(check(pwd)){
			cout<< pwd <<'\n';		
		}
		return;
	}
	if(i==alpha.size()){
		return;
	}
	go(n, alpha,pwd+alpha[i],i+1);
	go(n, alpha,pwd,i+1);
}
int main() {
	int n, c;
	cin >> n >> c;
	vector<char> alpha(c);
	for(int i=0; i<c; i++){
		cin >> alpha[i];
	}
	sort(alpha.begin(), alpha.end());
	
	go(n,alpha,"",0);
	
	return 0;
}

