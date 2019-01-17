/*
  숨바꼭질 문제에서 from을 추가한다. 
  그리고 스택에 넣어서 위에서부터 하나씩 출력하면 반대로 출력할 수 잇으므로
  처음부터 끝까지의 경로를 출력할 수 
*/
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;
const int MAX=200000;//n과 k가 모두 최대일때의 수
long long check[MAX+1];
long long dist[MAX+1];
long long from[MAX+1];
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
			from[now-1]=now;
			}
		}
		if(now+1<MAX){
			if(check[now+1]==false){
				q.push(now+1);
				check[now+1]=true;
				dist[now+1]=dist[now]+1;
				from[now+1]=now;
			}
		}
		if(now*2<MAX){
			if(check[now*2]==false){
				q.push(now*2);
				check[now*2]=true;
				dist[now*2]=dist[now]+1;
				from[now*2]=now;
			}
		}
	}
	printf("%d\n",dist[k]);
	
	stack<int> ans;
	for(int i=k; i!=n; i=from[i]){
		ans.push(i);
	}
	ans.push(n);
	while(!ans.empty()){
		printf("%d ",ans.top());
		ans.pop();
	}

	return 0;
}
