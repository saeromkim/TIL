/*
  스트레스 겁나 받는다 ㅁㅊ.,...,., 1시간동안 디버깅만 했다.
  cin/cout을 쓰면 왜 틀리게 나오는 걸까??????????????????????????
  하.......
  우전 bfs탐색 문제고 pair로 넣는 부분만 유의하면 충분히 풀 수 있는 문제였다.
*/

#include <iostream>
// #include <cstdio>
#include <queue>
using namespace std;
int d[101][101];
int a[101][101];
int n,m;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
 
int main() {
    scanf("%d %d",&m,&n);
    // cin>>m>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d",&a[i][j]);
            // cin>>a[i][j];
            d[i][j]=-1;
        }
    }
    queue<pair<int,int>> q;
    queue<pair<int,int>> next_q;
    q.push(make_pair(0,0));
    d[0][0]=0;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(0<=nx && nx<n && 0<=ny && ny<m){
                if(d[nx][ny]==-1){
                    if(a[nx][ny]==0){
                        d[nx][ny]=d[x][y];
                        q.push(make_pair(nx,ny));
                    }else{
                        d[nx][ny]=d[x][y]+1;
                        next_q.push(make_pair(nx,ny));
                    }
                }
            }
        }
        if(q.empty()){
            q = next_q;
            next_q = queue<pair<int,int>>();
        }
    }
    // cout << d[n-1][m-1] <<'\n';
    printf("%d\n",d[n-1][m-1]);
    return 0;
}
