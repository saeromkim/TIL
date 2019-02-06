/*
  시간 초과 뜨면 cin/cout 문제일 것이라고 의심해보자.
  이 문제는 최대,최소 힙을 이용해서 푸는 문제다.
  최대(왼쪽) 최소(오른쪽)으로 나눠서 왼쪽.top이 가운데 값이 된다.
  힙을 이용하는 간단하고도 로지컬한 문제이므로 연습에 도움이 될 듯
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<int> l; //최대힙. 내림차순
	priority_queue<int, vector<int>, greater<int>> r; //최소힙. 오름차순
	
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		if(l.empty() || r.empty()){
			l.push(x);
		}else{
			if(x <= l.top()){
				l.push(x);
			}else if(x >= r.top()){
				r.push(x);
			}else{
				l.push(x);
			}
		}
		while(!(l.size() == r.size() || l.size() == r.size()+1)){
			if(l.size() > r.size()){
				r.push(l.top());
				l.pop();
			}else{
				l.push(r.top());
				r.pop();
			}
		}
		cout<<l.top()<<'\n';
	}
	
	return 0;
}
