/*
	3*2인 경우 3가지
	3*4인 경우 2가지
	3*6이 경우 2가지
	세가지 경우를 모두 더한다..
*/
#include <iostream>
using namespace std;
long long d[31];

int main() {
	int n;
	cin>>n;
	d[0] = 1;
	d[2] = 3;
	if(n%2==0){
		for(int i=4; i<=n; i+=2){
			for(int j=2; j<=i; j+=2){
				if(j == 2){ //i-2면 *3
					d[i] += d[i-j]*3; 
				}else{ //i-4, i-6 이면 *2 해서 더하기
					d[i] += d[i-j]*2;
				}
			}
		}	
	}
	cout<<d[n];
	return 0;
}

//백준 코드
//d[i] = 3*d[i-2] + 2*d[i-4] + 2*d[i-6] + ...
#include <iostream>
using namespace std;
long long d[31];
int main(){
    int n;
    cin >> n;
    d[0] = 1;
    for (int i=2; i<=n; i+=2) {
        d[i] = d[i-2]*3;
        for (int j=i-4; j>=0; j-=2) {
            d[i] += d[j]*2;
        }
    }
    cout << d[n] << '\n';
    return 0;
}
