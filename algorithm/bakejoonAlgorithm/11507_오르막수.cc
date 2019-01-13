//쉬운 계단 수와 유사한 문제
//k가 j보다 크면 안된다.
//d[i][j]+=d[i-1][k] (0 <= k <= j)
#include <iostream>
#include <cstdio>
#include <stdio.h>
using namespace std;
long long mod=10007;
long long d[1001][10];
int main(){
	int n;
	cin >> n;
	for(int i=0; i<=9; i++){
		d[1][i]=1;
	} 
	for(int i=2; i<=n; i++){
		for(int j=0; j<=9; j++){
			for(int k=0; k<=j; k++){
				d[i][j]+=d[i-1][k];
				d[i][j]%=mod;
			}
		}
	}
	long long ans=0;
	for(int i=0; i<=9; i++){
		ans+=d[n][i];	
	}
	ans%=mod;
	cout << ans;
}
