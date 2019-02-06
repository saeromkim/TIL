/*
  그리디 문제. 증명만 하면 된다.
  각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값을 구하려면 먼저 오름차순으로 정렬하여,
  시간이 가장 적게 걸리는 사람이 앞에 오게 하는게 핵심이다.
  그리 어렵지 않았고 혼자 품. 인덱스를 정확하게 맞추기는 역시 헷갈린다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	int a[n];

	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	
	sort(a,a+n);
	// for(int x:a){
	// 	cout<<x<<" ";
	// }
	int sum=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){ //0부터 i(포함)까지
			sum+=a[j];
		}
	}
	cout<<sum;
	return 0;
}
