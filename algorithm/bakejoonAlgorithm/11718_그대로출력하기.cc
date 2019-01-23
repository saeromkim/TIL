#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	while(getline(cin,s)){ //getline함수를 사용하는게 
		cout<<s<<'\n';
	}
	return 0;
}
