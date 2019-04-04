/*
	수열을 구하면서 부등호가 성립하면 출력한다.
	(주어진 n은 부등호의 숫자로, 실제 숫자의 길이는 n+1임에 유의한다)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string sign;
int n;
//부등호 기호와 숫자가 올바르게 성립하는지 체크하는 함수
int check(int *a){
	for(int i=0; i<=n; i++){
		if(sign[i] == '<' && a[i] > a[i+1]){
			return false;
		}else if(sign[i] == '>' && a[i] < a[i+1]){
			return false;
		}
	}
	return true;
}

int main() {
	cin>>n;
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		sign += s;
	}
	int max[10];
	int min[10];
	//최대 수 구하기
	//가장 큰 수부터 시작해야하므로 9,8,7,...n개의 숫자를 넣고
	for(int i=0; i<=n; i++){
		max[i] = 9-i;
	}
	//부등호와 성립하면 break하고, 아니면 이전 수열을 구해서 계속 check 
	do{
		if(check(max)){
			break;
		}
	}while(prev_permutation(max,max+n+1)); 
	
	//최소 수 구하기
	//가장 작은 수부터 시작해야하므로 0,1,2...n개의 숫자를 넣고
	for(int i=0; i<=n; i++){
		min[i] = i;
	}
	//부등호가 성립하면 break, 아니면 다음 수열을 구해서 계속 check
	do{
		if(check(min)){
			break;
		}
	}while(next_permutation(min,min+n+1));
	
	//최대,최소 수열 출력
	for(int i=0; i<=n; i++){
		cout<<max[i];
	}
	cout<<"\n";
	for(int i=0; i<=n; i++){
		cout<<min[i];
	}
	
	return 0;
}
