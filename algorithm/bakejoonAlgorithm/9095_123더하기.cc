/*
다이나믹 특징은 점화식을 세울줄만 알면 문제가 다 비슷해보이는 특징이 있다.
이 문제는 정수 n을 1,2,3의 합으로 나타내는 방법의 수를 구하는 문제다.
마지막에 더하는 숫자로 1을 사용하는 방법, 2를 사용하는 방법, 3을 사용하는 방법을 모두 더해주어야 한다.
따라서 점화식은 d[n] = d[n-1] + d[n-2] + d[n-3]
if(i-1 > =0)와 같이 i가 1인경우에 d[i]에 d[i-1]를 더해준다.
*/
#include <cstdio>
using namespace std;
int d[11];
int main(){
	d[0]=1;
	for(int i=1; i<=10; i++){
		if(i-1 >= 0){
			d[i] += d[i-1];
		}
		if(i-2 >= 0){
			d[i] += d[i-2];
		}
		if(i-3 >= 0){
			d[i] += d[i-3];
		}
	}
	
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		printf("%d\n",d[n]);
	}
	return 0;
  
}


//블로그에서 찾은 점화식을 직접적으로 이용하는 방법
#include <iostream>
using namespace std;
int d[11];
int main(){
	int n, t;
	cin >> t;
	
	for(int i=0; i<t; t++){
		cin>>n;
		
		d[1]=1, d[2]=2, d[3]=4; //이렇게 테스트 케이스를 미리 입력해두면 그 뒤부터는 알아서 계산하는 건가?
		
		for(int i=4; i<=n; i++)
			d[i]=d[i-3]+d[i-2]+d[i-1];
			
		cout<<d[n]<<'\n';
	}
	return 0;
}

//재귀함수를 이용해서 푸는 방법 - 이것도 중요함!
#include <iostream>
using namespace std;
int go(int sum, int goal){
	if(sum>goal) return 0;
	if(sum==goal) return 1;
	int now;
	if(sum<goal){
		for(int i=1; i<=3; i++){
			now+=go(sum +i, goal); //1,2,3 을 사용하는 방법에 따라..
		}
	}
	return now;
}
int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << go(0,n) <<'\n'; 
	}
	return 0;
}


