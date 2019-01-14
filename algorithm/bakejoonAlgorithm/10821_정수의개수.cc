#include <iostream>
#include <string>
using namespace std;
int main(){
	//getline의 세번째 인자는 구분자(어디까지 입력을 받을 것 인지)
	string s;
	int cnt=0;
	while(getline(cin,s,',')){
		cnt+=1;
	}	
	cout << cnt << '\n';
	return 0;	
}
