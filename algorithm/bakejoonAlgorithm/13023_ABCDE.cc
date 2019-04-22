//백준코드랑 다르게 풀었다. 이해가 갈동말동
/*
	문제 : A - B - C - D - E
	즉, 깊이가 5인 경로가 존재하는지 구하는 문제
	dfs로 탐색하면서 COUNT 해준다.
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> a[2000];
bool check[2000];

//3.dfs 탐색하면서 깊이가 5일때 true 리턴하기
bool dfs(int depth, int now){
	if(depth == 5){
		return true;
	}
	check[now] = true;
	for(int i=0; i<a[now].size(); i++){ //각 정점과 연결되는 모든 정점 방문
		int next = a[now][i];
		if(check[next]) continue;
		if(dfs(depth + 1, next)){ //다음 정점 방문
			return true; //깊이가 5인 정점인 경우
		};
	}
	check[now] = false;
	return false;
}

int main() {
	int n, m;
	cin>>n>>m;
	//1.인접 리스트로 입력받기
	for(int i=0; i<m; i++){
		int u,v;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	//2.모든 정점에서 탐색하기(시작은 깊이 1, 시작 정점 i)
	for(int i=0; i<n; i++){
		if(dfs(1,i)){
			cout<<"1";
			return 0; //정답 찾으면 리턴하고 함수 실행 끝
		}
	}
	cout<<"0";
	return 0;
}

//백준코드. 본적 없음
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool a[2000][2000];
vector<int> g[2000];
vector<pair<int,int>> edges;
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int from, to;
        cin >> from >> to;
        edges.push_back({from, to});
        edges.push_back({to, from});
        a[from][to] = a[to][from] = true;
        g[from].push_back(to);
        g[to].push_back(from);
    }
    m *= 2;
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            // A -> B
            int A = edges[i].first;
            int B = edges[i].second;
            // C -> D
            int C = edges[j].first;
            int D = edges[j].second;
            if (A == B || A == C || A == D || B == C || B == D || C == D) {
                continue;
            }
            // B -> C
            if (!a[B][C]) {
                continue;
            }
            // D -> E
            for (int E : g[D]) {
                if (A == E || B == E || C == E || D == E) {
                    continue;
                }
                cout << 1 << '\n';
                return 0;
            }
        }
    }
    cout << 0 << '\n';
    return 0;
}
