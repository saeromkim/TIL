//sort와 unique를 이용하는 문제
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	int n;
	cin >> n; //13
	vector<string> a(n); 
  //문자열을 입력 받아 a벡터에 저장
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	//sort를 해준다
	sort(a.begin(), a.end(), [](string u, string v){
		if(u.size() == v.size()){
			return u < v;
		}else{
			return u.size() < v.size();
		}
	});
  //unique를 하면 begin에서 last전까지 중복없는 문자열이 온다
	auto last=unique(a.begin(), a.end());
  //last부터 end까지 중복있는 문자열을 지운다
	a.erase(last, a.end());
	
  //
	for(string x : a){
		cout << x << '\n';
	}
	
	
	return 0;
}
