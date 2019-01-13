/*
  가장 긴 증가하는 부분 수열 문제에서 길이와 실제 정답 수열까지 출력하는 문제
  벡터를 사용하지않고 배열을 사용했다. 
  어려우니까 다시 풀어보고 싶은 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int v[1000];
int a[1000];
int d[1000];
void go(int p){
	if(p==-1){ //v[p]가 -1 이면 무시, 즉 main함수에서 값을 바꾸지 않은 부분 무시
		return ;
	}
	go(v[p]); 재귀 함수 
	cout << a[p] <<' '; 
}
int main(){
	 int n;
	 cin >> n;
	 
	 for(int i=0; i<n; i++){
	 	cin >> a[i]; //a[]에 입력을 모두 넣음
	 }
	 
	 for(int i=0; i<n; i++){
	 	d[i]=1;
	 	v[i]=-1; //v[i]를 모두 -1로 채움
	 	for(int j=0; j<i; j++){
	 		if(a[j]<a[i] && d[i]<d[j]+1){
	 			d[i]=d[j]+1;
	 			v[i]=j; //값을 바꾼 순서를 저장
			 }
		 }
	 }
	 
	int ans = d[0];
    int p = 0;
    for (int i=0; i<n; i++) {
        if (ans < d[i]) {
            ans = d[i];
            p = i;
        }
    }
    cout << ans << '\n';
	go(p);
	cout << '\n';
	return 0;
}
