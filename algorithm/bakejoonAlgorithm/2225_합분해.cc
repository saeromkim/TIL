//다른사람 풀이 참고함
/*
	n = 10, k = 2 라면,
	
	1개 더해서 10 + 1개 더해서 0 = 10(10+0)
	1개 더해서 9 + 1개 더해서 1 = 10(9+1)
	...
	1개 더해서 0 + 1개 더해서 10 = 10(0+10)
	10+0 , 9+1, 8+2, ..., 5+5, ..., 2+8, 1+9, 0+10 
	
	따라서 DP[K][N] = DP[K-1][0] + DP[K-1][1] + .... + DP[K-1][N]
	(K번 더해서 N이 나오는 경우의 수)
	위 점화식을 그대로 구현하면 된다.
*/
#include <iostream>
using namespace std;
long long d[201][201];
long long mod = 1000000000;

int main() {
	int N,K;
	cin>>N>>K;
	for(int n=0;n<=N;n++){
        d[1][n]=1; //0,1,2,3,...N
    }
    
    for(int k=2;k<=K;k++){
        for(int n=0;n<=N;n++){
            for(int l=0;l<=n;l++){
                d[k][n]+=d[k-1][l];
            }
            d[k][n]%=mod;
        }
    }
	cout<<d[K][N];
	return 0;
}

//0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하는 프로그램을 작성하시오.
//dp에서 난이도 중 문제.(어렵다. 혼자 못풀었음)

#include <iostream>
#include <algorithm>
using namespace std;
long long d[201][201];
int mod=1000000000;
int main(){
	 int n,k;
	 cin >> n >> k;
	 d[0][0] = 1LL;
	 for(int i=1; i<=k; i++){
	 	for(int j=0; j<=n; j++){
	 		for(int l=0; l<=j; l++){
	 			d[i][j]+= d[i-1][j-l];
	 			d[i][j]%=mod;
			 }
		 }
	 }

	
	
    cout << d[k][n] << '\n';
	return 0;
}
