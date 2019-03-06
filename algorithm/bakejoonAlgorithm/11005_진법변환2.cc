/*
	n을 b진법으로 변환하려면 
	n을 b로 나눈 나머지를 구하면 된다. 이때 reverse를 해줘야 하는 것 잊지말자.
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int n,b;
	cin>>n>>b;
	string ans="";
	while(n>0){
		int r = n%b;
		if(r < 10){
			ans += (char)(r + '0');
		}else{
			ans += (char)(r -10 + 'A'); //10이면 A, 35면 35-10+'A' = 'Z' 
		}
		n/=b;
	}
	reverse(ans.begin(), ans.end());
	cout<<ans;
	return 0;
}
