/*
 갓갓님들의 풀이방식 (블로그+백준)
 현재의 계단에 올 수 있는 경우의 수는 2가지(i는 현재 계단)
 1. i-1 계단을 밟은 경우 -> a[i] + a[i-1] + d[i-3]
 2. i-1 계단을 밟지 않은 경우 -> a[i] + d[i-2]
 이 두 경우 중 최댓값을 d[i]에 저장한다
*/
#include <iostream>
using namespace std;
int a[301];
int d[301];

int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	d[1]=a[1];
	d[2]=a[1]+a[2]; //점수가 자연수라 무조건 더하는게 최대임
	for(int i=3; i<=n; i++){
		d[i] = max(d[i-2]+a[i], d[i-3]+a[i]+a[i-1]);
	}
	cout<<d[n];
	return 0;
}


//밑처럼 푸는 방법도 모르는데 한시간넘게 풀어봤자 다음에 풀지도 못하고 시간낭비다 1시간넘기면 바로 풀이보자!
//첫번째로 풀었을때. 틀렸습니다가 나옴.(한시간 반동안 풀었는데 ㅠㅠ)
//문제 조건을 그대로 구현함. 반례 5 3 3 2 1 1 정답:8 내껀 6나옴..
#include <iostream>
using namespace std;
int d[300];
int a[300];

int main() {
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	d[n-1] = a[n-1]; //마지막 계단은 항상 포함
	//마지막 계단부터 아래로
	for(int i=n-1; i>=0; i--){
		if(i==1){
			if(d[i]+a[i-1] > d[i]){
				if(d[i+1]==0){ //윗칸 포함x
					d[i-1] = d[i]+a[i-1];
				}else{
					continue;
				}
			}else{
				continue;
			}
		}
		if(d[i]+a[i-1] > d[i]+a[i-2]){ //한칸 아래가 더 크면
			if(i==n-1) { //마지막 계단이면
				d[i-1] = d[i] + a[i-1];
			}else{//그 외
				if(d[i+1]==0){ //윗칸 포함x
					d[i-1] = d[i]+a[i-1];
				}else{ //3개 연속이라면 2칸 이동
					d[i-2] = d[i] + a[i-2];
					i--;
				}
			}
		}else{ //두 칸 아래가 더 크면
			d[i-2] = d[i] + a[i-2];
			i--; //인덱스 이동
		}
	}
	int cmp=0;
	for(int i=0; i<n; i++){
		if(cmp<d[i]){
			cmp = d[i];
		}
	}
	cout<<cmp;
	return 0;
}
