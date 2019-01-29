#include <iostream>
#include <string>
using namespace std;
int main() {
	char a[8][8];
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cin>>a[i][j];
		}
	}
	int cnt=0;
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(((i%2==0) && (j%2==0) ||(i%2==1) && (j%2==1))  && (a[i][j]=='F')){  //문자열 바로 비교하고 싶을땐 char형 쓰기
				cnt+=1;
			}
		}
	}
	cout<<cnt<<'\n';
	return 0;
}
