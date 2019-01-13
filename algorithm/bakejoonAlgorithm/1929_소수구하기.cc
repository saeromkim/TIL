//2부터 n까지의 모든 수의 배수를 지운다
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int n=1000000;
bool check[n+1]; //지워졌으면 true 
int main(){
	check[0]=check[1]= true;
	for(int i=2; i*i<=n; i++){
		if(check[i]==false){
			for(int j=i+i; j<=n; j+=i){
				check[j]=true;
			}
		}
	}
	int a, b;
	cin >> a >> b;
	for (int i=a; i<=b; i++){
		if (check[i]==false){
			cout << i << '\n';
		}
	}
	
	return 0;
}
