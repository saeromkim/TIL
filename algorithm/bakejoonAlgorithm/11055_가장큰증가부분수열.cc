//LIS 알고리즘을 실행하면서 이전 숫자들 중 현재값보다 작은 수 중에(a[i]>a[j])
//배열의 수를 더했더니 현재값보다 크면(d[i] < d[j]+a[i])
//현재 인덱스에 그 값을 저장한다. 
//그럼 배열은 1 101 3 53 113 6 11 17 24 32 처럼 저장이된다.(직접 표 그려보기)
#include <iostream>
using namespace std;
int d[1001];
int a[1001];

int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++){
		d[i] = a[i]; //d[i] 값을 a[i]값으로 초기화 해야한다!
		for(int j=1; j<i; j++){
			if(a[i]>a[j] && d[i] < d[j] + a[i]){
				d[i] = d[j] + a[i];
			}
		}
		
	}
	int max=0;
	for(int i=1; i<=n; i++){
		if(max<d[i]){
			max = d[i];
		}
	}
	cout<<max;
	return 0;
}
