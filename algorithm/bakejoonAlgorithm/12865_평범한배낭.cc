#include <iostream>
#include <algorithm>
using namespace std;
int d[101][100000]; 
//d[i][j]=i번째 물건까지 고려했고, 배낭에 넣은 물건 무게 합이 j일때, 가치의 최댓값
int w[101];
int v[101];
int go(int n, int k){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=k; j++){
			d[i][j] = d[i-1][j]; 
			//i번째 물건을 가방에 넣지 않은 경우 물건들 가치합의 최댓값. 
			//i-1번째인데 무게는 그대로이다
			if(j-w[i]>=0){
				d[i][j] = max(d[i][j], d[i-1][j-w[i]]+v[i]); 
				//i번째 물건을 가방에 넣은 경우의 최댓값. d[i-1][j-w[i]]+v[i] 
				//i-1번째면 i번째 무게를 빼고, 
				//i번째 가치를 넣은 값과 현재 값을 비교하여 더 큰 값을 넣는다.
			}
		}
	}
	return d[n][k];
}

int main() {
	int n,k;
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>w[i]>>v[i];
	}
	cout<<go(n,k);
	
	return 0;
}
