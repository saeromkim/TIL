/*
	최대공약수는 gcb라고 한다.
	최대공약수는 유클리드 호제법을 이용하면 빠르다.O(logN)
	최대 공약수 (유클리드호제법) : a를 b로 나눈 나머지를 r이라고 했을 때 gcb(a,b) = gcb(b,r) 과 같다.
  최소공배수 l (LCM) : l = g*(a/g)*(b/g)
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
	int m,n;
	cin>>m>>n;
	int g;
	g=gcd(m,n);
	cout<<g<<"\n";
	cout<<lcm(g,m,n);
	
	return 0;
}
