//d[i][j]=길이가 i이자 마지막 숫자가 j인 계단 수의 개수
//d[i][j]=d[i-1][j-1]+d[i-1][j+1]
#include <iostream>
#include <cstdio>
#include <stdio.h>
using namespace std;
long long mod=1000000000;
long long d[101][10];
int main(){
	int n;
	cin >> n;
	for(int i=1; i<=9; i++){
		d[1][i]=1;
	} 
	for(int i=2; i<=n; i++){
		for(int j=0; j<=9; j++){
			if(j-1>=0){
				d[i][j]+=d[i-1][j-1];
			}
			if(j+1<=9){
				d[i][j]+=d[i-1][j+1];
			}
			d[i][j]%=mod;
		}
	}
	long long ans=0;
	for(int i=0; i<=9; i++){
		ans+=d[n][i];	
	}
	ans%=mod;
	cout << ans;
}
