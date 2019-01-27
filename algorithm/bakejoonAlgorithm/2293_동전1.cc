/*
  다이내믹 문제데스..
  123더하기 4 풀다가 푸니까 넘나리 쉬웟잖스...
  동전 종류 여러가지 있다고 생각했을 때 각각 1번동전만 썼을때 경우의 수 저장,
  거기다 2번동전만 썼을 때 경우의 수 또 저장..요런식으로 했다 데스 
*/
#include <iostream>
using namespace std;
int d[100001];
const int limit=100001;
int main() {
	d[0]=1;
	
	int n,k;
	cin>>n>>k;
	while(n--){
		int coin;
		scanf("%d",&coin);
		for(int i=1; i<=limit; i++){
			if(i-coin>=0){
				d[i]+=d[i-coin];
			}
		}
	}
	printf("%d\n",d[k]);
}
