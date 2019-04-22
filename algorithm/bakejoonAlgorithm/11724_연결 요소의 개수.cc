/*
	단순하다
	모든 정점을 탐색하고 탐색이 끝날 때 마다 (cnt += 1) 한다.
	한 연결요소에서 탐색을 했다면 다시 탐색할 수 없으므로
	연결 요소의 개수를 구할 수 있다.
	난 dfs + 인접리스트로 풀거다
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> a[1001];
bool check[1001];

//모든 노드 탐색하면서 방문표시 하기
void dfs(int node){
	check[node] = true;
	for(int i=0; i<a[node].size(); i++){
		int next = a[node][i];
		if(check[next]) continue;
		dfs(next);
	}
}

int main() {
	int n,m;
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int u,v;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	int cnt = 0;
	
	//방문안한 모든 정점에서 탐색 시작하기
	//문제에서 간선의 양 끝점 u,v는 1부터 시작이라는 조건이 있음에 유의
	for(int i=1; i<=n; i++){
		if(check[i] == false){ 
			dfs(i);
			cnt += 1;
		}
	}
	cout<<cnt;
	return 0;
}
