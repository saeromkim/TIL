//순열 이용 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int w[11][11]; 
int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>w[i][j];
		}
	}
	vector<int> d(n);
	for(int i=0; i<n; i++){
		d[i]=i;
	}
	int ans=2147483647;
	
	do{
		bool ok=true;
		int sum=0;
		for(int i=0; i<n-1; i++){ //n=4, 0 1 2 만큼. 세번 돔
			//거리비용이 있는지 먼저 확인
			if(w[d[i]][d[i+1]]==0)  ok=false; //01, 12, 23 비교 실제로는(12 23 34일 것)
			else {
				sum+=w[d[i]][d[i+1]]; //있으면 sum에 더함
			}	
		}
		//마지막 돌아오는 것
		if (ok==true && w[d[n-1]][d[0]]!=0){ // d[3][0]
				sum+=w[d[n-1]][d[0]];
				//sum의 최소값 ans에다 넣기 if문 안에 넣어야한다. 
				if(ans>sum) ans=sum;
		} 

	}while(next_permutation(d.begin(),d.end()));
	//while(next_permutation(d.begin()+1,d.end())); 원래 도시로 돌아오는 경우의 수 1을 뺄 수 있다.
	
	cout << ans <<'\n';
	return 0;
}
