/*
  많이 까다로운 문제는 아닌 것 같은데 역시 n의 범위를 정하는게 넘나 어려운것ㅋ
  d[i][j] = i까지 수를 사용해서 j를 만드는 방법의 수
  1. 마지막 수를 더한 경우
   d[i-1][j-a[i]] + a[i] = j
  2. 마지막 수를 뺀 경우
   d[i-1][j+a[i]] - a[i] = j
*/
#include <iostream>
using namespace std;
long long d[101][21]; 
int a[101]; //주어지는 숫자 배열
int main() {
	int n;
	cin>>n;
	n-=1; //등식의 갯수는 n-1과 같다. 
	for(int i=0; i<n; i++){
		cin>>a[i]; //맨 마지막 숫자를 제외하고 입력받는다.
	}
	int goal;
	cin>>goal; //맨 마지막 숫자를 입력 받아 goal로 저장
	d[0][a[0]]=1; //0번째까지 수를 사용해서 첫번째 수인 8을 만드는 방법의 수는 1개다.
	for(int i=1; i<n; i++){
		for(int j=0; j<=20; j++){
			if(j-a[i]>=0){ 
				d[i][j] += d[i-1][j-a[i]]; //맨 마지막 숫자를 더했을 때의 방법의 수를 더함
			}
			if(j+a[i]<=20){
				d[i][j] += d[i-1][j+a[i]]; //맨 마지막 숫자를 뺐을 때의 방법의 수를 더함
			}
		}
	}
	cout<<d[n-1][goal]<<'\n'; //맨마지막 숫자까지 더한 후의 경우의 수를 구한다. 
	return 0;
}
