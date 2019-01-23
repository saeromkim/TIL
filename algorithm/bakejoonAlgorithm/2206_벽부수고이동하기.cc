/*
  bfs로 풀었다..tuple로 인자를 3개로 해서 풀었다.
  z는 벽을 부순 횟수를 말한다.
  조건 식을 세우는게 복잡하고 까다로웠다....
*/
#include <iostream>
#include <queue>
#include <tuple>
#include <cstdio>
using namespace std;
int d[1000][1000][2]; 
int a[1000][1000];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
 
int main() {
	int n,m;
   scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d",&a[i][j]);
        }
    }
    queue<tuple<int,int,int>> q;
    q.push(make_tuple(0,0,0));
    d[0][0][0]=1;
    while(!q.empty()){
        int x,y,z;
        tie(x,y,z) = q.front();
        q.pop();
        for(int k=0; k<4; k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(nx<0 || nx>=n || 0>ny || ny>=m) continue;
                if(a[nx][ny]==0 && d[nx][ny][z]==0){ //현재 0이고, 이동할 곳의 벽을 부순적이 없다면 이동한다  
                        d[nx][ny][z]=d[x][y][z]+1;
                        q.push(make_tuple(nx,ny,z));
                }
                if(z==0 && a[nx][ny]==1 && d[nx][ny][z+1]==0){ //이동할 곳이 1이고, 벽을 부순다음 0이 될때, 벽을 부순적이 없을때때
                    d[nx][ny][z+1]=d[x][y][z]+1;
                    q.push(make_tuple(nx,ny,z+1));
                }
            }
        }
	if(d[n-1][m-1][0]!=0 && d[n-1][m-1][1]!=0){
		cout<<min(d[n-1][m-1][0],d[n-1][m-1][1]);
	}else if(d[n-1][m-1][0]!=0){
		cout<<d[n-1][m-1][0];
	}else if(d[n-1][m-1][1]!=0){
		cout<<d[n-1][m-1][1];
	}else{
		cout << -1;
	}
    cout<<'\n';
    return 0;
}
