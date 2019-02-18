/*
  LCA를 다이나믹을 이용해서 O(logN)만에 푸는 문제
  으
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
int p[MAX][18];
int lca(int u, int v){
	//코드를 간단하게 하기 위해 깊이가 더 작은 것을 u로 둔다.
	if(depth[u] < depth[v]){
		swap(u,v);
	}
	int log = 1;
	for(log=1; (1<<log) <= depth[u]; log++); //트리 n에 log값을 구하기
	log-=1;
	for(int i=log; i>=0; i--){ //큰 log값부터 시작해서 한칸씩 위로 올라가면서 같아질때까지 올라간다
		if(depth[u] - (1<<i) >= depth[v]){
			u = p[u][i];
		}
	}
	if(u==v){
		return u;
	}else{
		for(int i=log; i>=0; i--){
			if(p[u][i] != 0 && p[u][i] != p[v][i]){
				u = p[u][i];
				v = p[v][i];
			}
		}
	}
	return parent[u];
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
	for(int i=1; i<=n; i++){
		p[i][0] = parent[i]; //모든 i의 parent를 p[i][0]에 저장한다.
	}
	for(int j=1; (1<<j)<n; j++){ //j < log 까지
		for(int i=1; i<=n; i++){
			if(p[i][j-1] != 0){ //i의 parent가 0이 아닐때(루트가 아닐때)
				p[i][j] = p[p[i][j-1]][j-1]; //부모의 2^j을 계속 구해준다.
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
