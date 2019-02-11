/*
  이분탐색 기초문제 중 하나.
  랜선을 잘라 랜선 개수 n개를 만들 수 있는 최대 길이를 구하는 문제다.
  랜선을 크게 자를 수록 랜선 개수는 줄어드는 점을 이용한다.
  예를 들어, 길이가 100, 200인 랜선이 2개 있을때, 랜선 3개를 만들어야한다고 생각해보자.
  이분 탐색으로 50씩 자르면 랜선의 개수는 6개가 만들어 진다.
  랜선의 개수를 더 줄여야 하므로, 자를 길이를 더 늘린다. 즉, mid 값을 더 크게 한다.
  100씩 자르면 랜선의 개수는 3개가 만들어 진다.
*/

#include <iostream>
using namespace std;
int a[10000];
int n,k;
bool check(int mid){
	int cnt = 0;
	for(int i=0; i<k; i++){
		cnt += a[i]/mid;
	}
	return cnt >= n; //mid값으로 나누었더니 랜선 갯수가 구하고자 하는 갯수보다 크다면 true를 반환
}

int main() {
	scanf("%d",&k);
	scanf("%d",&n);
	
	int max=0;
	for(int i=0; i<k; i++){
		scanf("%lld",&a[i]);
		if(max < a[i]){
			max = a[i]; //랜선의 가장 큰 값을 구해 r로 정한다. 
		}
	}
	long long l = 1, r = max, ans = 0; 
	while(l <= r){
		long long mid = (l+r)/2;
		if(check(mid)){ 
			if(ans < mid){ //mid의 최댓값
				ans = mid;
			}
			l = mid + 1; //mid로 자르는 것이 가능하므로 더 크게 자른다
		}else{
			r = mid - 1; //mid로 자르는 것이 불가하면 더 작게 잘라본다.
		}
	}
	printf("%lld",ans);
	return 0;
}
