/*
  가장 긴 증가하는 부분 수열 문제에서 감소하는 것으로 바꾸는 문제
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[1001];
int d[1001];
int main(){
	 int n;
	 cin >> n;
	 
	 for(int i=1; i<=n; i++){ //a[1]부터
	 	cin >> a[i]; //a[]에 입력을 모두 넣음
	 }
	 
	 for(int i=n; i>=1; i--){ //전체 수열의 뒤에서 부터 검사
	 	d[i]=1;
	 	for(int j=i+1; j<=n; j++){ //앞에서부터 n까지 검사
	 		if(a[i] > a[j] && d[i] < d[j]+1){ //검사 값[j]가 현재 값[i] 작고 && 검사 값+1 이 현재 길이보다 길 때
	 			d[i]=d[j]+1; // 현재 값에 검사 값 저장
			 }
		 }
	 }
	 
	int ans = d[1]; //d[1]에 1이 들어감

    for (int i=2; i<=n; i++) { //두번째 부터 비교 시작
       if (ans < d[i]) { //for문을 반복하면서, d[i]의 가장 큰 값을 ans에 저장한다.
            ans = d[i];
        }
    }
    cout << ans << '\n';
	return 0;
}
