/*
  dag에서 가장 긴 경로를 구하는 문제.
  그리고 그 때, 가장 긴 경로에 포함된 간선의 개수를 구하는 문제
  코드가 길고 복잡해 보이지만 하나하나 읽으며 이해하면 이해할 수 있는 문제다.
  하나하나 그림을 그리면서 이해하면 쉽다.
  그래프 2.5 ppt에 그림이 있다.
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,int>> a[10001];
vector<pair<int,int>> b[10001];
int ind[10001];
int ind2[10001];
int d[10001];
bool c[10001];

int main() {
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0; i<m; i++){
		int t1,t2,t3;
		scanf("%d %d %d",&t1,&t2,&t3);
		a[t1].push_back(make_pair(t2,t3));
		b[t2].push_back(make_pair(t1,t3));
		ind[t2] += 1;
		ind2[t1] += 1;
	}
	int st,ed;
	scanf("%d %d",&st,&ed);
	queue<int> q;
	for(int i=1; i<=n; i++){
		if(ind[i] == 0){
			q.push(i);
		}
	}
	//가중치 최대 경로.
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int k=0; k<a[x].size(); k++){
			int y = a[x][k].first;
			d[y] = max(d[y], d[x]+a[x][k].second);
			ind[y] -= 1;
			if(ind[y] == 0){
				q.push(y);
			}
		}
	}
	printf("%d\n",d[ed]);
	//거쳐가는 간선의 수. 도시의 개수로. 그래프를 거꾸로 읽으면서 구한다.
	for(int i=1; i<=n; i++){
		ind[i] = ind2[i]; //ind2 안쓰고 ind쓰려고 복사해줌
	}
	c[ed] = true;
	for(int i=1; i<=n; i++){
		if(ind[i] == 0){
			q.push(i);
		}
	}
	int ans = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int k=0; k<b[x].size(); k++){
			int y = b[x][k].first;
			if(c[x] && d[x]-d[y] == b[x][k].second){
				c[y] = true;
				ans += 1;
			}
			ind[y] -=1;
			if(ind[y] == 0){
				q.push(y);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
