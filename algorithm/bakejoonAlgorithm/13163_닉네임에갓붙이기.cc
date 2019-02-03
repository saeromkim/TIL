//공백으로 문자열 구분하기 문제. ignore함수의 사용법도 알 수 있었고, c++문법으로도 간단히 문제를 해결할 수 있다.
#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, s_index;
	cin>>n;
	cin.ignore(); //c의 fflush(stdin)과 비슷하다.
	//cin을 통해 문자를 입력받을 경우 입력버퍼에 먼저 저장된다.
	//입력버퍼의 값을 cin을 통해 정수형 변수에 저장하려고 하는데
	//이 도중 아래 getline을 통해 문자가 입력되면 에러가 뜨기 때문에
	//입력버퍼를 지우는 ignore 함수를 실행해야 한다.
	while(n--)
	{
		string str;
		getline(cin,str);
		for(int i=0; i<str.length(); i++)
		{
			if(str[i]==' ')
			{
				s_index = i;
				break;
			}
		}
		cout << "god";
		
		for(int i=s_index+1; i<str.length(); i++){
			if(str[i]==' ')
				continue;
			cout<<str[i];
		}
		cout<<'\n';
	}
	
	return 0;
}
