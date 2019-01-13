//수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
//배열로 하니 max값을 구하기 까다로워서 vector를 사용함

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	 int n;
	 cin >> n;
	 
	 vector<int> a(n); //입력
	 for(int i=0; i<n; i++){
	 	cin >> a[i]; //a[]에 입력을 모두 넣음
	 }
	 vector<int> d(n); //답
	 for(int i=0; i<n; i++){
	 	d[i]=1; //각각의 수만 있을 때 1이므로 먼저 값을 넣어 놓는다.
	 	for(int j=0; j<i; j++){ //현재값 이전 값까지만 반복
	 		if(a[j]<a[i] && d[i]<d[j]+1){ //증가이면서 && 현재 값보다 더 크면
	 			d[i]=d[j]+1; //현재값에 저장
			 }
		 }
	 }
	 
	cout << *max_element(d.begin(),d.end()) << '\n';
	return 0;
}
