/*
  스택을 이용하는 유명하고 중요한 문제다.
  스택에 오름순으로 막대의 높이를 넣다가, 
  i번째 막대의 높이가 현재 스택(오름차순이므로 가장 높은 막대)보다 작으면
  하나씩 지우면서 높이를 구한다. 
  반복하면 스택에는 막대 높이가 오름차순으로만 남게 된다.
  막대의 끝까지 반복한 후에는 스택을 하나씩 비우면서 같은 방법으로 높이를 구한다.
  그림을 그리면서 이해하면 쉽다.
*/
#include <iostream>
#include <stack>
using namespace std;
long long a[100001]; //높이의 범위가 1,000,000,000 이므로 long long
int main() {
	while(true){
		int t;
		scanf("%d",&t);
			if(t==0) break;
		for(int i=0; i<t; i++){
			scanf("%lld",&a[i]);
		}
	
		stack<long long> s;
		long long ans=0; //초기화 반드시 해줄 것
		for(int i=0; i<t; i++){
			int left = i;
			while(!s.empty() && a[s.top()] > a[i]){  //현재 막대가 가장 긴 막대보다 작으면
				long long height = a[s.top()]; //가장 긴 막대의 높이의 너비를 구하기 위해
				s.pop(); //가장 긴 막대의 위치가 지워지고, s.top()은 이전 위치를 가리킨다. 즉, left는 현재 막대-1
				long long width = i;
				if(!s.empty()){
					width = (i - s.top()-1); //너비는 현재막대-1의 오른쪽 끝에서 부터, i번째 막대의 왼쪽 끝 까지이다.  
				}
				if(ans <  width*height){
					ans = width*height; //너비의 최댓값
				}
			}
			s.push(i); //현재 막대가 가장 긴 막대보다 크면 스택에 넣는다
		}
		while(!s.empty()){ //스택을 하나씩 비우면서 같은 방법으로 구하면 높이가 가장 낮은 것까지 구할 수 있다. 
			long long height = a[s.top()];
			s.pop();
			long long width = t;
			if(!s.empty()){
				width = t - s.top()-1;
			}
			if(ans <  width*height){
				ans = width*height;
			}
		}
	printf("%lld\n",ans);
	}
	return 0;
}
