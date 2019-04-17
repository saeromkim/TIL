//백준코드랑 다르게 풀었다. 이해가 갈동말동
//dfs로 탐색하면서 깊이가 5일때 1을 출력한다.
#include <iostream>
#include <vector>
using namespace std;
vector<int> a[2001];
bool check[2001];

bool dfs(int depth, int n){ //깊이, 정점
	if(depth == 5){ //깊이가 5일 때 출력
		return true;
	}
	check[n] = true;
	for(int i=0; i<a[n].size(); i++){
		int next = a[n][i]; //다음 정점
		if(check[next]) continue; //방문했으면 건너뛰기
		if(dfs(depth + 1, next)){ //dfs 재귀
			return true;
		}
	}
	check[n] = false;
	return false;
	
}

int main(void) {
	int n,m; 
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int u,v;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i=0; i<n; i++){ //모든 정점에서 탐색을 시작해본다
		if(dfs(1,i)){
			cout<<"1";
			return 0; //있으면 출력하고 리턴
		}
	}
	cout<<"0";
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
