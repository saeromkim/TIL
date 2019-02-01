/*
  시험성적 범위별로 성적매기는거!
  switch로 범위를 지정해주는 방법은 ... 을 사용하면 되는구나!!
*/
#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	switch(n){
		case 90 ... 100: cout<<"A"; break;
		case 80 ... 89: cout<<"B"; break;
		case 70 ... 79: cout<<"C"; break;
		case 60 ... 69: cout<<"D"; break;
		default: cout<<"F";
	}
	return 0;
}
