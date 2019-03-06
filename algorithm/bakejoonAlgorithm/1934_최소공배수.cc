/*
   유클리드호제법으로 최대공약수를 구한다음 이를 이용해 최소공배수를 구한다.
   (최소공배수 l = g*(a/g)*(b/g)
*/
#include <iostream>
using namespace std;
int gcd(int a, int b){
	while(b != 0){
		int r = a%b; //a나누기 b의 나머지 r
		a = b; 
		b = r; 
	}
	return a; //b가 0이 될때까지 나누다가 a를 출력
}
int lcm(int g,int a,int b){
	int l;
	l=g*(a/g)*(b/g);
	return l;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>m>>n;
		int g;
		g=gcd(m,n);
		cout<<lcm(g,m,n)<<"\n";
	}
	
	return 0;
}
