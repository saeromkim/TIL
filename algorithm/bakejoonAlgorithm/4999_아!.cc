//재밌고 간단한 문제..
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
	char s[1000];
	char c[1000];
	scanf("%s",s);
	scanf("%s",c);
	if(strlen(s) >= strlen(c)){  //char 문자열 길이는 strlen으로..
		printf("go");
	}else{
		printf("no");
	}
	return 0;
}
