/*
카드 n개를 구매하는 비용의 최댓값을 구하는 문제다.
가장 마지막에 구매한 카드팩에 들어있는 카드의 수를 i라고 했을 때, 
i를 구매하기 전의 카드의 수는 n-i개 이다. 
d[n] = 카드 n개 구매하는 최대 비용
따라서 점화식, 카드 n개를 구매하는 최대 비용은 d[n] = max(P[i]+d[n-i]) 이다. 
시간 복잡도 = N(문제 수) * N(한 문제를 푸는데 걸리는 시간) = N^2
(문제 1개를 푸는 시간 = O(n))

실제 코드에서는 d[n] = max(d[n], d[n-i]+P[n]) 과 같이 사용
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> a(n+1);
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	vector<int> d(n+1);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			d[i] = max(d[i], (d[i-j]+a[j]));
		}
	}
	cout << d[n] << '\n';
	return 0;
}
