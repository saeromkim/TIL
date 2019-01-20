/*
  next_permutation을 사용하는 문제다 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cal(vector<int> &a){
	int sum=0;
	for(int i=1; i<a.size(); i++){
		sum+=abs(a[i]-a[i-1]); // [1]-[0], [2]-[1] ... i의 인덱스 범위때문에 1부터 빼주는 것이 정확하다
	}
	return sum;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end()); //정렬을 해줘야 한다.  1 4 8 10 15
	int ans=0;
	//차례대로 오름차수 순열을 만들어 계산한다
	do{
		int temp = cal(a);
		ans=max(temp,ans);
	}while(next_permutation(a.begin(), a.end()));
	
	cout << ans << '\n';
	
	return 0;
}
