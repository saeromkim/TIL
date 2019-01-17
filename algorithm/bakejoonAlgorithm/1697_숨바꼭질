/*
  bfs에서 간단한 문제다.
  bfs의 연산 순서를 단순하게 알 수 있었다.
*/
#include <cstdio>
#include <queue>
using namespace std;
const int MAX=200000;//n과 k가 모두 최대일때의 수
long long check[MAX+1];
long long dist[MAX+1];
int main() {
	int n,k;
	scanf("%d %d",&n,&k);
	
	check[n]=true;
	dist[n]=0;
	queue<int> q;
	q.push(n);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(now-1>=0){
			if(check[now-1]==false){
			q.push(now-1);
			check[now-1]=true;
			dist[now-1]=dist[now]+1;
			}
		}
		if(now+1<MAX){
			if(check[now+1]==false){
				q.push(now+1);
				check[now+1]=true;
				dist[now+1]=dist[now]+1;
			}
		}
		if(now*2<MAX){
			if(check[now*2]==false){
				q.push(now*2);
				check[now*2]=true;
				dist[now*2]=dist[now]+1;
			}
		}
	}
	printf("%d",dist[k]); //여기서 왜 dist[k]값을 출력해야 하는지 이해해야한다. 
	

	return 0;
}
