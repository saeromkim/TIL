/*
- 123더하기랑 비슷한 문제
- 0을 두번 사용하지 않는다
*/

//나의 풀이
#include <iostream>
using namespace std;
long long d[91][3]; 
int main(){
	int n;
	cin >> n;
  //1. 이친수는 0으로 시작하지 않는다.
	d[1][0]=0; //0으로 시작하면 방법 0개
	d[1][1]=1; //1로 시작하는 방법 1개
	
	for(int i=2; i<=n; i++){
		for(int j=0; j<=1; j++){
			if(j==0){ 
				d[i][j]=d[i-1][0]+d[i-1][1]; //마지막 자리에 0이오면 0,1두가지 방법
			}
			if(j==1){
				d[i][j]=d[i-1][0]; //마지막 자리에 1이 오면 0이 옴
			}
		}
	}
	long long ans=0;
	for(int i=0; i<=1; i++){
		ans+=d[n][i];	//0과 1이 오는 모든 경우를 ans에 저장
	}
	cout << ans; //정답 출력
}


//백준의 정답 : 1차원 배열로 품
/*
  d[i]= 길이가 i인 이친수
  d[0]=d[1]=0
  i) 마지막에 0이 온다면 그 앞의 수는 1밖에 안 옴. d[i-1] 이다.
  ii) 마지막에 1이 온다면 ... | i-2 | 0 | 1 |  인 경우 밖에 없음.
  따라서 점화식은 d[i] = d[i-1] + d[i-2]
*/
#include <iostream>
using namespace std;
long long d[91];
int main() {
    int n;
    cin >> n;
    d[1] = 1; //길이가 1인 경우는 1 한가지
    d[2] = 1; //길이가 2인 경우는 10 한가지
    for (int i=3; i<=n; i++) {
        d[i] = d[i-1] + d[i-2];
    }
    cout << d[n] << '\n';
    return 0;
}
