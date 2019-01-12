//소수는 2보다 크거나 같고, 루트n보다 작거나 같은 자연수로 나누어떨어지지 않는 수
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int prime(int n){
		if(n<2){
			return false;
		}
		for(int i=2; i*i<=n; i++){
			if(n%i==0){
				return false;
			}
		}
		return true;
}
int main(){
	int t,n,cnt=0;
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&n);
		if(prime(n)){
			cnt+=1;
		}
	}
	printf("%d",cnt);
	return 0;
}
