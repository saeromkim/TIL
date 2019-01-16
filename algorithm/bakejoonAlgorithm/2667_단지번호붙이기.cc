
//7ㅣ00pm 직접 문제 풀어보기
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int a[30][30]; //지도 즉, 간선을 뜻한다
int group[30][30]; //check배열과 같다
int dx[] = {0,0,1,-1}; //x 좌표 저장
int dy[] = {1,-1,0,0}; //y 좌표 저장 , 위 아래로 (0,1),(0,-1)...
int n; //단지 크기를 결정하는 n
int ans[25*25]; //정답을 넣을 배열

void bfs(int x, int y, int cnt) {
    queue<pair<int,int>> q; //pair로 큐를 만든다
    q.push(make_pair(x,y)); // x,y를 짝 지어 넣는다 예를 들어 (0,0),(0,1)...
    group[x][y] = cnt; //현재 x,y 그룹에 cnt를 넣는다. cnt는 처음에 0이고, main의 for문을 돌면서 1씩 증가할 것이다
    while (!q.empty()) { //q에 x,y가 들어있을 테니
        x = q.front().first; //q의 첫번째 값을 x에 넣는다
        y = q.front().second; //두번째 값을 y에 넣는다
        q.pop(); //맨앞의 값 삭제
        for (int k=0; k<4; k++) { 
            //현재 위치의 상하좌우 값을 k++하며 검사한다.
            int nx = x+dx[k]; 
            int ny = y+dy[k]; 
            
            //만약 nx와 ny가 모두 양수이면,
            if (0 <= nx && nx < n && 0 <= ny && ny < n) { 
              //그래서 a[nx][ny]가 1이고(간선이 있는데), group[nx][ny]가 0이면(방문한 적이 없으면)
                if (a[nx][ny] == 1 && group[nx][ny] == 0) { 
                    q.push(make_pair(nx,ny)); //현재 좌표를 큐에 넣는다.
                    group[nx][ny] = cnt; //그리고 넣은 좌표에 cnt값을 넣는다.
                }
            }
        }
    }
}
int main() {
    scanf("%d",&n); 
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%1d",&a[i][j]); //정수 한자리씩 2차원배열 a[][]에 넣는다. (지도)
        }
    }
    int cnt = 0; //cnt 0으로 초기화
    for (int i=0; i<n; i++) { 
      for (int j=0; j<n; j++) {
      //만약 a[][]가 1이고 (간선이 있는데)group[][]이 0이면(방문한 적이 없으면)
            if (a[i][j] == 1 && group[i][j] == 0) { 
                bfs(i, j, ++cnt); //현재 자리와 ++cnt한 값을 bfs에 넣고 돌린당.
            }
        }
    }
    printf("%d\n",cnt); //cnt를 출력한다. 단지의 수 
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            ans[group[i][j]]+=1; //정답 배열에 지도에 group(check)배열 값을 넣고 +1 한다.
        }
    }
    sort(ans+1, ans+cnt+1); //ans+1와 ans+cnt+1두개를 정렬한다 
    for (int i=1; i<=cnt; i++) { //cnt만큼
        printf("%d\n",ans[i]); //ans배열을 출력한다.
    }
    return 0;
}
