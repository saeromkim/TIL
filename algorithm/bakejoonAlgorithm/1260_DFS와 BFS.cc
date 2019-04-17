//인접리스트를 이용한 dfs와 bfs구현하기 문제
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

vector<int> a[1001];
bool check[1001];

void dfs(int x){
	check[x] = true;
	cout<<x<<" ";
	for(int i=0; i<a[x].size(); i++){
		int y = a[x][i];
		if(check[y] == false){
			dfs(y);
		}
	}
}

void bfs(int start) {
	//큐 초기화하기
	queue<int> q;
	memset(check, false, sizeof(check));
	check[start] = true;
	q.push(start);
	while(!q.empty()){
		//방문 순서대로 출력하기
		int x = q.front();
		q.pop();
		cout<<x<<" ";
		//각 정점마다 방문안한 곳 방문하기
		for(int i=0; i<a[x].size(); i++){
			int y =  a[x][i];
			if(check[y] == false){
				check[y] = true;
				q.push(y);
			}
		}
	}
}

int main() {
	//정점의 개수 n, 간선의 개수 m, 시작 정점 번호 start
	int n, m, start;
	cin>>n>>m>>start;
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i=1; i<=n; i++){
		sort(a[i].begin(), a[i].end());
	}
	dfs(start);
	cout<<"\n";
	bfs(start);
	cout<<"\n";
	
	return 0;
}
