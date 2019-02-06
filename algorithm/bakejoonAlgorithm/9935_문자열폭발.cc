/*
  어렵고 약간 복잡하다. ㅠㅠ 스택으로 푸는 문제다.
  스택에 현재 문자가 폭발 문자열의 첫번째 문자와 같으면 (문자열의 인덱스, 폭발 문자열에서 인덱스) 를 넣으며 푼다.
  
*/

#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
char a[1000001];
char b[37];
bool erased[1000001];

int main() {
	scanf("%s",a);
	scanf("%s",b);
	int n = strlen(a);
	int m = strlen(b);
	if(m == 1){ //폭발문자열의 길이가 1이면
		for(int i=0; i<n; i++){
			if(a[i] == b[0]){ //그냥 모두 비교해서
				erased[i] = true; //지우면 됨. (실제로 지우는게 아니라 이렇게 bool값으로 해도됨
			}
		}
	}else{ //폭발 문자열이 1보다 크면
		stack<pair<int,int>> s;
		for(int i=0; i<n; i++){
			if(a[i] == b[0]){ //현재 문자열과 폭발문자열의 첫번째 문자가 같으면
				s.push(make_pair(i,0)); //스택에 넣는다.
			}else{ //다르면
				if(!s.empty()){ //스택이 비어있지 않은 경우,
					auto st = s.top(); //스택의 가장 위의 폭발 문자열의 인덱스를 가져온다. st
					if(a[i] == b[st.second+1]){  //현재 문자가 폭발 문자열의 st+1 문자와 같으면 스택에 넣는다.
						s.push(make_pair(i,st.second+1));
						if(st.second+1 == m-1){ //만약 st+1 문자가 폭발문자열의 마지막 문자면, 폭발 문자열을 찾은 것이다.
							for(int k=0; k<m; k++){ //스택에서 폭발 문자열을 지운다. 
								st = s.top();
								erased[st.first] = true; //현재 문자열을 지운다.
								s.pop();
							}	
						}
					}else{ //만약 st+1문자가 현재 문자와 다르면 스택을 모두 비워버린다. 
						while(!s.empty()){
							s.pop();
						}
					}
				}
			}
		}
	}	
	bool printed = false;
	for(int i=0; i<n; i++){
		if(!erased[i]){ //남아있는 문자가 있는 경우
			printf("%c",a[i]);
			printed = true; //true로
		}
	}
	if(!printed){ //남아있는 문자가 없는 경우
		printf("FLURA\n");
	}
	return 0;
}
