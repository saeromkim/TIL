/*
	조세퍼스 문제.
	front+3 값을 계속 출력하면 되는 듯 하다.
  실제로 큐를 사용할때는 bfs에서만 쓰고. 이 문제는 큐 사용법을 익히기 위해 만든 문제라 생각하면 된다.
  아마 다시 풀 일 없을 듯 ㅎ..
*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;
	queue<int> q;
	for(int i=1; i<=n; i++){
		q.push(i);
	}	
	cout<<"<";
	for(int i=0; i<n-1; i++){
		for(int j=0; j<m-1; j++){
			q.push(q.front()); //앞에서 부터 두개씩 큐의 뒤에 추가해주고 지운다
			q.pop();
		}
		cout<<q.front()<<", "; //앞의 두개가 지워졌으니 3번째 숫자가 
		q.pop();
	}
	cout<<q.front()<<">";
	return 0;
}
