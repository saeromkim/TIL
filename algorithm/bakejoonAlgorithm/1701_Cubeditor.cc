/*
  두번 이상 등장하는 부분 문자열 중 가장 긴 것의 길이를 구하는 문제다
  앞에서 하나씩 없어지면서 kmp를 하여 최댓값을 구하면 된다.
  코드로는 reverse한 다음 +1씩 포함하면서 kmp 하여 vector에 저장한 다음 최댓값을 구했다. (반대로)
  혼자 힘으로 풀려했으나 단순하게 앞의 문자열을 지우고 하면 인덱스가 빈 문자열을 포함해서 구하기 때문에 틀렸던 듯
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> kmp(string p){ //pi값을 저장할 벡터
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
	return pi;
}
int main() {
	string p;
	cin>>p;
	reverse(p.begin(),p.end()); 
	int ans=0;
	string a;
	for(char c:p){
		a=c+a; //앞에서부터 1씩 늘려가며 kmp한다. a->ab->abb->abbc ...
		vector<int> pi=kmp(a); //넣은 걸 차례로 pi에 넣는다.
		for(int i=0; i<pi.size(); i++){
			if(ans<pi[i]) ans=pi[i]; //kmp한 것 중 최댓값 즉, 최대 길이 찾기
		}
	}
	cout<<ans;
	return 0;
}
