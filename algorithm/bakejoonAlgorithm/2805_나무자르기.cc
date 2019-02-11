/*
  랜선자르기와 매우 흡사한 이분탐색 기초 문제다.
  범위가 매우 커 long long 형으로 연산해야하는데, 이 부분이 어려웠다.
  (그냥 모든 변수를 long long으로 바꿔주면 되는거였다.)
  배열로 하면 크기가 너무 커서 벡터를 이용했다.
*/
#include <iostream>
#include <vector>
using namespace std;
int n;
long long m;
bool check(long long mid, vector<long long> &a){
	long long cnt = 0;
	for(int i=0; i<n; i++){
		if(a[i]-mid > 0)
		cnt += a[i]-mid;
	}
	return cnt >= m;
}

int main() {
	scanf("%d",&n);
	scanf("%lld",&m);
	
	int max=0;
	vector<long long> a(n);
	for(int i=0; i<n; i++){
		scanf("%lld",&a[i]);
		if(max < a[i]){
			max = a[i];
		}
	}
	long long l = 1, r = max, ans = 0;
	while(l <= r){
		long long mid = (l+r)/2;
		if(check(mid, a)){
			if(ans < mid){
				ans = mid;
			}
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	printf("%lld",ans);
	return 0;
}
