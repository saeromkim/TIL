/*
  bfs 기초문제 중 하나이다.
  어려웠다...ㅠㅠ 
  memset으로 메모리 저장하는 부분이랑,
  char유형을 출력할 때 %c로 출력해야하는 부분 때문에 헤맸다.
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <stack>
using namespace std;
bool check[10001];
int dist[10001];
char how[10001];
int from[10001];
void print(int n, int m) {
    if (n == m) return;
    print(n, from[m]);
    printf("%c",how[m]); //char유형이므로 %c로 출력해야함에 유의한다
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b;
		scanf("%d %d",&a,&b);
		memset(check,false,sizeof(check));
		memset(dist,0,sizeof(dist));
		memset(how,0,sizeof(how));
		memset(from,0,sizeof(from));

		check[a]=true;
		dist[a]=0;
		from[a]=-1;
		queue<int> q;
		q.push(a);
		while(!q.empty()){
			int now=q.front();
			q.pop();
			int next=now*2 % 10000;
			if(check[next]==false){
				check[next]=true;
				q.push(next);
				dist[next]=dist[now]+1;
				from[next]=now;
				how[next]='D';
			}
			next = now-1;
			if(next==-1) next=9999;
			if(check[next]==false){
				check[next]=true;
				q.push(next);
				dist[next]=dist[now]+1;
				from[next]=now;
				how[next]='S';
			}
			//L
			next = (now%1000)*10 + (now/1000);  //1234를 2340 + 1 =2341
			if(check[next]==false){
				check[next]=true;
				q.push(next);
				dist[next]=dist[now]+1;
				from[next]=now;
				how[next]='L';
			}
			//R
			next = (now/10) + (now%10)*1000; //1234를 123 + 4000 =4123
			if(check[next]==false){
				check[next]=true;
				q.push(next);
				dist[next]=dist[now]+1;
				from[next]=now;
				how[next]='R';
			}
			
		}
		 print(a, b);
		 printf("\n");
		// stack<int> ans;
		// for(int i=a; i!=b; i=from[i]){
		// 	ans.push(i);
		// }
		// ans.push(a);
		// while(!ans.empty()){
		// 	printf("%d",ans.top());
		// 	ans.pop();
		// }
		
		// string ans = "";
  //      while (b != a) {
  //          ans += how[b];
  //          b = from[b];
  //      }
  //      reverse(ans.begin(), ans.end());
  //      printf("%d\n",ans);
         
	}
	return 0;
}
