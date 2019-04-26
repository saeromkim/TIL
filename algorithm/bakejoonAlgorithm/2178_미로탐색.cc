/*
    dfs로 풀면 가짓수가 많아 시간초과가 난다.
    bfs로 푼다.
*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int a[100][100];
bool check[100][100];
int dist[100][100];
int nx[] = {0,0,1,-1};
int ny[] = {1,-1,0,0};

int main() {
	int n,m;
	cin>>n>>m;
    //1. 미로 배열 입력 받기
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d",&a[i][j]);
        }
    }
    //2.(0,0)을 (1,1)로 가정하고 dfs 탐색하기
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    check[0][0] = true;
    dist[0][0] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int dx = x + nx[k];
            int dy = y + ny[k];
            if(dx>=0 && dx<n && dy>=0 && dy<m){
                if(check[dx][dy] == false && a[dx][dy] == 1){
                    q.push(make_pair(dx,dy));
                    check[dx][dy] = true;
                    dist[dx][dy] = dist[x][y] + 1; //탐색가능한 칸에 방문할 때마다 거리 한 칸씩 증가
                }
            }
        }   
    }
    //3.(n-1,m-1)칸의 누적된 거리값 출력
    cout<<dist[n-1][m-1]; 

	return 0;
}
