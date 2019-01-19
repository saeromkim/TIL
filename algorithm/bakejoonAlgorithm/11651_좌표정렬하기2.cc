//x좌표 기준으로 먼저 오름차순으로 하는게 아니라,
//y좌표 기준으로 먼저 오름차순하는 문제다.
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d",&n);
	vector<pair<int,int>> a(n);
	for(int i=0; i<n; i++){
		scanf("%d %d", &a[i].second, &a[i].first); //여기서 x와 y좌표를 바꿔서 입력해주고
	}
	//sort
	sort(a.begin(), a.end()); //second 기준으로 정렬한 후 
	
	for(int i=0; i<a.size(); i++){
		printf("%d %d\n", a[i].second, a[i].first); //다시 바꿔서 y좌표를 x좌표인 것처럼 출력하면 된다.
	}
	return 0;
}
