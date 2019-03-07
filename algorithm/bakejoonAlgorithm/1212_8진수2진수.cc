/*
  8->2 진법 변환
  노가다로 풀었음.ㅋ
*/
#include <iostream>
using namespace std;

int main() {
	string s;
	getline(cin,s);
	int n = s.size();
	if(s == "0"){
		cout<<0;
		return 0;
	}
	for(int i=0; i<s.size(); i++){
		switch(s[i]-'0'){
			case 0:
				cout<<"000";
				break;
			case 1:
				if(i==0)
					cout<<"1";
				else
					cout<<"001";
				break;
			case 2:
				if(i==0)
					cout<<"10";
				else
					cout<<"010";
				break;
			case 3:
				if(i==0)
					cout<<"11";
				else
					cout<<"011";
				break;
			case 4:
				cout<<"100";
				break;
			case 5:
				cout<<"101";
				break;
			case 6:
				cout<<"110";
				break;
			case 7:
				cout<<"111";
				break;
		}
	}
	return 0;
}

//백준 코드
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
string eight[8] = {"000","001","010","011","100","101","110","111"};
int main(){
    string s;
    cin >> s;
    bool start = true;
    if (s.length() == 1 && s[0]-'0' == 0) {
        cout << "0";
    }
    for (int i=0; i<s.length(); i++) {
        int n = s[i]-'0';
        if (start == true && n < 4) {
            if (n == 0) {
                continue;
            } else if(n == 1) {
                cout << "1";
            } else if (n == 2) {
                cout << "10";
            } else if (n == 3) {
                cout << "11";
            }
            start = false;
        } else {
            cout << eight[n];
            start = false;
        }
    }
    return 0;
}
