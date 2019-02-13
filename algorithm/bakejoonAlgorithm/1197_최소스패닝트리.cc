//어렵군. 최소스패닝트리 구하는 문제고 크루스칼로 품. 소스는 참고함
//프림으로 푸는 것 보다 간단하다고 해서 이걸로 공부했는데 로직이 정확하게 와닿지 않는다.
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct Edge //간선 스트럭트 생성
{
	int start, end, cost;
	bool operator < (const Edge &other) const {
		return cost < other.cost;
	}
};
int p[10001];
int Find(int x) { //Find 함수 생성
	if(x == p[x]) { //x값을 p[]에서 찾는다. 계속 깊이 들어가면서
		return x;
	} else {
		return p[x] = Find(p[x]);
	}
}
void Union(int x, int y) { 
	x = Find(x);
	y = Find(y);
	p[x]=y;
}
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++){
		p[i]=i; //정점의 개수만큼 p를 채워줌 1,2,3..
	}
	vector<Edge> a(m);
	for(int i=0; i<m; i++){ //시작점 끝점 가중치 입력받음
		scanf("%d %d %d",&a[i].start, &a[i].end, &a[i].cost);
	}
	sort(a.begin(), a.end()); //정렬한다. (cost기준인듯)
	int ans=0;
	for(int i=0; i<m; i++){
		Edge e = a[i]; //가중치가 작은 것 부터 살펴본다.
		int x = Find(e.start);
		int y = Find(e.end);
		if(x != y) { //시작점 끝점이 다르면 합쳐준다.
			Union(e.start, e.end);
			ans += e.cost;
		}
	}
	printf("%d\n",ans);
	return 0;
}
