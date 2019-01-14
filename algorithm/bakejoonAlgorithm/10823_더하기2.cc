#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(){
	//getline의 세번째 인자는 구분자(어디까지 입력을 받을 것 인지)
	string s;
	int sum=0;
	string line;
	while(cin >> line){
		s+=line;
	}
	
	istringstream sin(s); //s를 표준입출력 cin처럼 사용, sstream include필요
	
	string number;
	while(getline(sin,number,',')){
		sum+=stoi(number);
	}	
	cout << sum << '\n';
	return 0;	
}
