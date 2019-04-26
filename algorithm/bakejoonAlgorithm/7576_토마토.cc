/*
  혼자 80% 정도 푼 것 같은데 반례가 하나 있었다.
	1인 칸이 동시에 bfs 탐색을 해야하므로
	1을 찾을때마다 bfs를 하는 것이 아니라
	1인 곳을 먼저 모두 찾아서 큐에 넣고, 그 값들에서부터 순서대로 탐색한다.
*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int m,n;
int a[1000][1000];
bool check[1000][1000];
int dist[1000][1000];
int nx[] = {0,0,1,-1};
int ny[] = {1,-1,0,0};

int main() {
    cin>>m>>n;
    queue<pair<int,int>> q;
    //1.배열 입력 받기 & 익은 토마토 위치 큐에 넣고 방문처리하기
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
            if(a[i][j] == 1){
            	q.push(make_pair(i,j));
            	check[i][j] == true;
            }
        }
    }
    //2.익은 토마토 위치들 부터 bfs 탐색하기
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int dx = x + nx[k];
            int dy = y + ny[k];
            if(dx>=0 && dx<n && dy>=0 && dy<m){
                if(check[dx][dy] == false && a[dx][dy] == 0){ 
                    a[dx][dy] = 1;
                    check[dx][dy] = true;
                    dist[dx][dy] = dist[x][y] + 1; 
                    q.push(make_pair(dx,dy));
                }
            }
        }
    }
    //**테스트용 코드
    // cout<<"배열 a\n";
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //     	cout<<a[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n";
    // cout<<"dist\n";
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //     	cout<<dist[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n";
    // cout<<"check\n";
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //     	cout<<check[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    //3. 조건에 따라 정답 출력하기
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 0){ //방문하지 못한 곳이 있으면 -1 출력
                cout<<"-1";
                return 0;
            }
            if(ans < dist[i][j]){ //가장 긴 거리 출력
                ans = dist[i][j];
            }
        }
    }
    cout<<ans;

	return 0;
}
