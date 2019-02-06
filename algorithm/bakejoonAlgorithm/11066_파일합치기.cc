/*
  다이나믹 문제.
  d[i][j] = i부터 j까지 파일을 더했을 때 최소비용
*/
#include <cstdio>
#include <cstring>
using namespace std;
int d[501][501]; //소설을 구성하는 장 수 500이 최대
int a[501]; 
int go(int i, int j){
	if(d[i][j] != -1) return d[i][j]; //d의 값을 이미 계산을 한 적이 있어서 -1이 아닐 경우 출력
	if(i==j) return 0; //1장일 경우 0
	int &ans = d[i][j]; //현재 정답은 i부터 j까지
	int sum = 0; 
	for(int k=i; k<=j; k++){
		sum += a[k]; //파일 크기 모두 더한 값 sum
	}
	for(int k=i; k<=j; k++){
		int temp = go(i,k) + go(k+1, j) + sum; //k를 기준으로 왼 + 오 + 왼,오 더하는 방법(마지막 두개 더하는 방법)
		if(ans == -1 || ans>temp){ //ans가 -1이거나 최솟값을 구함
			ans = temp;
		}
	}

	return ans;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		memset(d,-1,sizeof(d)); //모든 최소비용값은 -1로 초기화 해 둔다. 
		for(int i=1; i<=n; i++){
			scanf("%d",&a[i]);
		}
		printf("%d\n",go(1,n));
	}
	
	return 0;
}
