/*
  가중치가 0인건 그냥 무시해도 되는 값이 되므로 가중치가 1인 경우만 따로 큐에 저장하거나,
  덱을 써서 시작하는 지점을 기준으로 가중치 0인건 앞에 넣고, 가중치가 1인건 뒤에 넣는다.
  사실 가중치가 0인 경우는 많지 않다..! 이 문제는 덱을 이해하기 위한 문제로 삼자.
*/
#include <iostream>
#include <deque>
using namespace std;
bool c[1000000];
int d[1000000];
int MAX=1000000; //max라는 변수이름이 이미 존재하기때문에 
int main() {
	int n,m;
	cin>>n>>m;
	deque<int> q;
	q.push_back(n);
	d[n]=0;
	c[n]=true;
	while(!q.empty()){
		int now=q.front();
		q.pop_front();
		if(now*2<MAX){
			if(c[now*2]==false){
				c[now*2]=true;
				d[now*2]=d[now];
				q.push_front(now*2);
			}
		}
		if(now+1<MAX){
			if(c[now+1]==false){
				c[now+1]=true;
				d[now+1]=d[now]+1;
				q.push_back(now+1);
			}
		}
		if(now-1>=0){
			if(c[now-1]==false){
				c[now-1]=true;
				d[now-1]=d[now]+1; //d[]는 가중치라는 것에 유의! 문제에서 가중치는 거리!
				q.push_back(now-1);
			}
		}
	}
	cout<<d[m]<<'\n';
	
	return 0;
}
