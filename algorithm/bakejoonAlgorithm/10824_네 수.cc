#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	
	string s_a,s_b,s_c,s_d;
	s_a=to_string(a);
	s_b=to_string(b);
	s_c=to_string(c);
	s_d=to_string(d);
	
	string x,y;
	x=s_a + s_b;
	y=s_c + s_d;
	
	long long i,j; //int범위를 벗어나기 때문에 longlong으로 지정하는 점 
	i=stoll(x);
	j=stoll(y);
	
	cout << i+j <<'\n';
	
	return 0;	
}
