백준 온라인 강의 프로그래밍 대회에서 사용하는 C, C++, STL  
챕터 4 강의 정리 https://code.plus/lecture/5

##string
### 문자열 생성방법
```c
string s1;

char c[] = "c string";
string s2(c);
string s3 = c;

c[1]='\0';

string s4(c);
string s5 = c;

string s6(10, '!');
string s7 = "abcdefg";
