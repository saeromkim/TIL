/*
입력 : 첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)
출력 : 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.
- 다이나믹 프로그래밍은 점화식을 도출하는 과정이 전부라고 봐도 무방하다.
- D[i] = 2*i 직사각형을 채우는 방법의 수
- 마지막 줄에 2x1(세로) 타일 1개 놓는 방법, 1x2(가로) 타일 2개 놓는 방법 두 가지로 나눈다.
- 세로타일을 1개 놓으면 2*n의 n(가로)의 길이에서 -1을 한 것과 같다.
- 가로타일을 2개 놓으면 n의 길이에서 -2를 한 것과 같다. 
- D[n] = D[n-1] + D[n-2]
- D[0]은 아무것도 놓지 않는 방법이 1개 있으므로 0이 아니라 1이다.
*/
//top-down으로 혼자 푼 코드
#include <iostream>
using namespace std;
int d[1001];
int mod = 10007;
int dp(int n){
	if(n==1) return 1;
	if(n==2) return 2; 
	if(d[n]>0) return d[n];
	if(n>2){
		d[n] = dp(n-2) + dp(n-1);
	}
	return d[n]%mod;
}

int main() {
	int n;
	cin>>n;
	d[0] = 1;
	cout<<dp(n);
	return 0;
}



//백준코드
#include <cstdio>
using namespace std;
int d[1001];
int main(){
  int n;
  scanf("%d",&n);
  d[0]=1;
  d[1]=1;
  for(int i=2; i<=n; i++){
  	d[i]=d[i-1]+d[i-2];
  	d[i]%=10007;
  }
  printf("%d\n",d[n]);
  
  return 0;
}


/*
2*n타일링2는 기존 문제에 2*2타일이 추가된 것이다. 따라서 d[n-2]인 상황이 두배가 일어나는 것이다. 
*/
#include <cstdio>
using namespace std;
int d[1001];
int main(){
  int n;
  scanf("%d",&n);
  d[0]=1;
  d[1]=1;
  for(int i=2; i<=n; i++){
  	d[i]=d[i-1]+2*d[i-2]; //2를 
  	d[i]%=10007;
  }
  printf("%d\n",d[n]);
  
  return 0;
}
