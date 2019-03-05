/*
  string은 문자열을 입력받지만 공백전까지만 입력을 받는다. 
  따라서 한 줄을 모두 입력받을땐 getline()을 사용한다는 걸 명심하자.
*/
#include <iostream>
using namespace std;

int main() {
	string s;
	getline(cin,s);
	for(int i=0; i<s.size(); i++){
		if (s[i] >= 'a' && s[i] <= 'm') {
            s[i] = s[i] + 13;
        } else if (s[i] >= 'n' && s[i] <= 'z') {
            s[i] = s[i] - 13;
        } else if(s[i] >= 'A' && s[i] <= 'M') {
            s[i] = s[i] + 13;
        } else if(s[i] >= 'N' && s[i] <= 'Z') {
            s[i] = s[i] - 13;
        }
	}
	for(int i=0; i<s.size(); i++){
		cout<<s[i];
	}
	return 0;
}
