/*
  카드 구매하기 2..dp로 푸는 문제임
  d[i]=i개의 카드를 구매할 때 지불해야하는 최솟값
  카드 i개를 구매하는 방법은
  d[i-j]+p[j] 는  카드 j개가 들어있는 카드팩을 구매하고, 카드 i-j개를 구매한 경우다.
  이 값의 최솟값을 i개를 구매할때까지 해주면 된다. 
*/
#include <iostream>
#include <algorithm>
using namespace std;
int d[1001];
int main() {
	int n;
    cin >> n;
	for(int i=1; i<=n; i++){
		d[i]=-1;
	}
	int p[n];
    for(int i=1; i<=n; i++){
		cin>>p[i];
	}
	d[0] = 0;
	for (int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++){
			if(d[i] == -1 || d[i] > d[i-j] + p[j]){
				d[i] = d[i-j]+p[j];
			}		
		}
	}
	cout<<d[n]<<'\n';
}
