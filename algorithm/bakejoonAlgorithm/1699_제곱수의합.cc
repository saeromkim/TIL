//D[i] = 자연수 n을 제곱수의 합으로 나타낼 때에 최소 항의 개수
//D[i] = min(D[i-j^2] + 1)
#include <iostream>
#include <algorithm>
using namespace std;
int d[100001];
int main(){
	 int n;
	 cin >> n;

	 for(int i=1; i<=n; i++){
	 	d[i]=i; //정답은 1^2 을 i개 쓴 것보다 항상 작으니 i로 초기화 
	 	for(int j=1; j*j<=i; j++){
	 		if(d[i] > d[i-j*j]+1){
	 			d[i]=d[i-j*j]+1;	
			}
		}
	 }
	
    cout << d[n] << '\n';
	return 0;
}
