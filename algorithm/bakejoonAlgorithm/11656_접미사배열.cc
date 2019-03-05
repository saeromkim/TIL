/*
  배열값이 변하는 벡터에다 저장해서 출력하면 됨.
  벡터는 push를 사용
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin>>s;
	vector<string> ss;
	string temp;
	for(int i=0; i<s.size(); i++){
		 temp = s.substr(i);
		 ss.push_back(temp);
	}
	sort(ss.begin(),ss.end());
	for(int i=0; i<ss.size(); i++){
		cout<<ss[i]<<"\n";
	}
	return 0;
}
