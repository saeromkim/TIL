/*
  그냥 다해보기 문제~
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int check(vector<string> &a){ //벡터를 사용한다. 문자를 받는다.
	int n = a.size();
	int ans=1;
	for(int i=0; i<n; i++){
		int cnt=1;
		for(int j=1; j<n; j++){
			if(a[i][j]==a[i][j-1]){ //2차원 배열이라 생각하고 가로 새로 하나씩 비교한다
				cnt+=1; //맞으면 cnt++
			}else{
				cnt =1; //아니면 cnt는 다시 1이 되고 그 전 수는 else문을 만나기 전에 ans에 대입된다
			}
			if(ans<cnt) ans=cnt; //현재 정답보다 cnt 수 즉, 연속되는 수의 길이의 최대값을 ans에 넣는다
		}
		cnt=1; //cnt를 다시 초기화
    //같은 방식으로 세로도 비교한다
		for( int j=1; j<n; j++){
			if(a[j][i]==a[j-1][i]){
				cnt+=1;
			}else{
				cnt=1;
			}
			if(ans<cnt) ans=cnt;
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<string> a(n); //n크기만큼 벡터를 만든다
	for(int i=0; i<n; i++){
			cin >> a[i]; //문자열을 받아 벡터에 모두 넣는당
	}
	int ans=0; 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(j+1 <n){ //가로 줄 모두 순회
				swap(a[i][j],a[i][j+1]); //가로 두개를 바꾼다
				int temp=check(a); //바꾸고 난 후 check하고, check함수에서 찾은 가장 긴 수 ans를 temp에 저장
				if(ans<temp)ans=temp; //temp의 최댓값을 ans에 저장
				swap(a[i][j],a[i][j+1]); //다음 비교를 위해 다시 원래대로
			}
			if(i+1 <n){ //세로 줄 모두 순회
				swap(a[i][j], a[i+1][j]);
				int temp=check(a);
				if(ans<temp)ans=temp;
				swap(a[i][j], a[i+1][j]);
				
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
