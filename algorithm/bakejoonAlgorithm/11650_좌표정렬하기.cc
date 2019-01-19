//vector의 pair 성질을 이용해서 푸는 문제다.
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d",&n);
	vector<pair<int,int>> a(n);
	for(int i=0; i<n; i++){
		scanf("%d %d", &a[i].first, &a[i].second); //pair로 넣기
	}
	//sort
	sort(a.begin(), a.end());
	
	for(int i=0; i<a.size(); i++){
		printf("%d %d\n", a[i].first, a[i].second); //pair로 
	}
	return 0;
}
