#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin>>s;
	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());
	int n;
	n = stoi(s);
	cout<<n;
	
	return 0;
}
