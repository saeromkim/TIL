/*
  위상정렬(어떤 일을 하는 순서를 찾는 알고리즘)을 이용한 문제다. 
*/
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int ind[10001]; //들어오는 화살 표 수
int work[10001]; //해당 작업에 걸리는 시간
int d[10001]; //i번째 일때 걸리는 시간
vector<int> a[10001]; //선행 관계에 있는 번호를 넣는 배열
int main() {
	int n; 
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&work[i]);
		int cnt;
		scanf("%d",&cnt); //선행관계에 있는 작업들의 개수
		for(int j=1; j<=cnt; j++){ //개수만큼 작업들의 번호를 받아 배열 a에 넣는다.
			int x;
			scanf("%d",&x); 
			a[x].push_back(i); //a배열의 해당 작업의 번호에 1,2,3..차례대로넣는다.
			ind[i] += 1; //하나씩 넣을 때마다 ind가 1씩 추가된다.
		}
	}
	queue<int> q;
	for(int i=0; i<n; i++){
		if(ind[i] == 0){ //indgree가 0, 즉 첫번째 정점이라면
			q.push(i); //큐에 i번째를 넣고
			d[i]=work[i]; //걸리는 시간을 d의 i번째에 저장
		}
	}
	while(!q.empty()){ 
		int x = q.front(); //x는 q의 처음
		q.pop(); //하나씩 지워준다
		for(int i=0; i<a[x].size(); i++){ //선행관계에 있는 작업들의 수만큼 반복한다.
			int y = a[x][i]; //y는 x번째 i번째 선행관계에 있는 작업의 수
			ind[y] -= 1; //ind를 하나 지워줌
			if(d[y] < d[x]+work[y]){ //선행관계에 있는 작업들까지 더한것과 x번째까지의 값을 구한다.
				d[y] = d[x]+work[y];
			}
			if(ind[y]==0){ //x번째 선행관계에 있는 작업의 수가 0 즉 첫번째라면 큐에 넣는다. 
				q.push(y);
			}	
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++){
		if(ans < d[i]){ //구한 작업시간들의 최솟값을 구한다. 
			ans= d[i];
		}
	}
	printf("%d\n",ans);
    return 0;
}
