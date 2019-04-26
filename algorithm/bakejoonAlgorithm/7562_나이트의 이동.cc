/*
	* 테스트케이스가 여러개 있을 때는 배열 초기화 처리에 유의한다.
  bfs로 푼다. 알고나면 비교적 쉬운(?) 문제였다. 
  혼자 70프로 정도 풀었는데 배열로 방문 처리를 하려고 하다가 실패했다..
*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int nx[] = {-2,-2,-1,-1,1,1,2,2};
int ny[] = {-1,1,-2,2,-2,2,-1,1};
int dist[300][300];

int main() {
    int t;
    cin>>t;
    while(t--){
        //1.체스판 크기와 현재 칸, 이동하려는 칸 입력받기
        int num;
        cin>>num;
        int i,j; //현재 칸
        cin>>i>>j;
        int n,m; //이동하려는 칸
        cin>>n>>m;
        memset(dist,-1,sizeof(dist)); //모든 칸에대해 방문하지 않음으로 초기화
        
        //2.현재 칸 방문처리하기
        queue<pair<int,int>> q;
        q.push(make_pair(i,j));
        dist[i][j] = 0;
        
        //3.현재 칸에서부터 bfs 탐색 시작하기
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            if(i == n && j == m){ //현재칸과 도착칸이 같으면 break
            	break;
            }
            q.pop();
            for(int k=0; k<8; k++){
                int dx = x + nx[k];
                int dy = y + ny[k];
                if(dx>=0 && dx<num && dy>=0 && dy<num){
                    if(dist[dx][dy] == -1){
                        dist[dx][dy] = dist[x][y] + 1;
                        q.push(make_pair(dx,dy));
                    }
                }
            }
        }
        //4.이동하려는 칸까지의 거리 출력하기
        cout<<dist[n][m]<<"\n";
    }

    
	return 0;
}
