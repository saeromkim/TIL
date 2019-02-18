/*
  LCA : Lowest Common Ancestor를 구하는 문제
  O(n)만에 구할 수 있는데, 제한이 커지만 시간이 오래걸린다.
  (다이나믹을 이용해서 O(log)만에 풀 수 있는데, 이건 LCA2문제 코드를 참고)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 100111;
vector<int> a[MAX];
int parent[MAX];
bool check[MAX];
int depth[MAX];
int lca(int u, int v){
	//코드를 간단하게 하기 위해 깊이가 더 작은 것을 u로 둔다.
	if(depth[u] < depth[v]){
		swap(u,v);
	}
	//깊이가 다르면 u를 위로 한 칸씩 이동
	while(depth[u] != depth[v]){
		u = parent[u];
	}
	//깊이가 같고, 두 정점이 다르면 각각의 parent가 정점이므로 저장
	while(u != v){
		u = parent[u];
		v = parent[v];
	}
	return u; //둘 중 하나를 리턴
}

int main(){
	int n;
	scanf("%d",&n);
	//인접리스트 만드는 식으로 입력 받는다.
	for(int i=0; i<n-1; i++){
		int u,v;
		scanf("%d %d",&u,&v);
		a[u].push_back(v);
		a[v].push_back(u);
	} 
	//깊이 0, check true, q에 넣음으로써 시작점, 루트 점을 지정한다.
	depth[1] = 0;
	check[1] = true;
	queue<int> q;
	q.push(1);
	parent[1] = 0; //루트이므로 parent는 0이당. (정점은 1~n)
	while(!q.empty()){
		int x = q.front(); 
		q.pop();
		for(int y : a[x]){
			if(!check[y]){
				depth[y] = depth[x] + 1;
				check[y] = true;
				parent[y] = x;
				q.push(y);
			}
		}
	}
	int m;
	scanf("%d", &m);
	while(m--){
		int u, v;
		scanf("%d %d",&u,&v);
		printf("%d\n",lca(u,v));
	}
	return 0;
}
