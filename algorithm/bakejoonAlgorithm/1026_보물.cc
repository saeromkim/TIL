/*
  각각 오름차순 내림차순으로 곱하면 최솟값이 나오는 문제..
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> b(n); //벡터 사용할 땐 받아온 크기만큼만 
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		cin>>b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int sum=0;
	for(int i=0; i<n; i++){
		sum+=a[i]*b[n-1-i]; //이 부분이 핵심!
	}
	cout<<sum<<'\n';
	return 0;
}
