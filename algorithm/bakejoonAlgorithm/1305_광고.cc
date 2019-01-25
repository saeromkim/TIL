/*
  kmp알고리즘을 이요한 문제다. kmp짤 줄 알면 풀 수 있음
  인덱스 범위에 주의한다.
  정답은 N-pi[N] 이라는 것이 
*/
#include <iostream>
#include <vector>
using namespace std;
int kmp(string p){
	int m=p.size();
	vector<int> pi(m);
	pi[0]=0;
	int j=0;
	for(int i=1; i<m; i++){
		while(j>0 && p[i]!=p[j]){
			j=pi[j-1];
		}
		if(p[i]==p[j]){
			pi[i]=j+1;
			j+=1;
		}else{
			pi[i]=0;
		}
	}
	return pi[m-1]; //1을 빼줘야함
}
int main() {
	int n; 
	string p;
	cin>>n>>p;
	cout<< n-kmp(p)<<'\n'; //가능한 광고 길이중 가장 짧은 것은 전체 길이에서 같은 문자열만큼 삭제한 것과 같다.
	return 0;
}
