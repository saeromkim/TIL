/*
  괄호문제는 유명하고 중요하다고 한다. 
  카탈란 수라는 것인데 수학공식을 몰라도 이렇게 유도해서 풀면 된다고 한다.
  괄호 다이나믹으로 풀기
  코드는 간단한데 점화식은 d[L] = (시그마)d[i-2]*[L-i] 인데
  코드는 왜 저렇게 되는지 이해가 안간다.
  코드는 백준코드 참고했다.
  다시 풀어봐야 겠다.
*/
#include <iostream>
using namespace std;
long long d[2501];
long long mod=1000000007ll;
int main() {
	d[0]=1;
	for(int i=1; i<=2500; i++){
		d[i]=0;
		for(int j=0; j<i; j++){
			d[i] += d[j] * d[i-j-1];
			d[i]%=mod;
		}
		d[i]%=mod;
	}
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<< (n%2==0 ? d[n/2] : 0) <<'\n';
	}
	
	return 0;
}

/*
	2차원 다이나믹으로 풀기
	d[i][j] = 길이가 i이고, 짝이 맞지 않는 괄호의 개수가 j
	
*/
#include <iostream>
using namespace std;
long long d[5001][5001];
long long m=1000000007ll;

int main() {
	d[0][0]=1; //길이가 0이고, 짝이 맞지 않는 괄호의 개수가 0인 경우 1??
	//테스트케이스에 0을 넣으면 1이 출력
	for(int i=1; i<=5000; i++){
		for(int j=0; j<=i; j++){
			d[i][j]=0;
			if(j+1<=i){ //마지막 괄호가 ')' 인 경우
				d[i][j] += d[i-1][j+1];	//')'을 제외하면 짝이 맞지 않는 괄호의 갯수는 +1
			}
			if(j-1>=0){ //마지막 괄호가 '('인 경우 /짝이 맞지 않는 괄호의 개수가 음수면 만들수 없다.
				d[i][j] += d[i-1][j-1]; //'('을 포함해서 j이므로 j-1
			}
			d[i][j]%=m;
		}
	}
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<d[n][0]<<'\n'; //짝이 맞지 않는 괄호의 개수가 없는 경우가 답
	}
	return 0;
}
