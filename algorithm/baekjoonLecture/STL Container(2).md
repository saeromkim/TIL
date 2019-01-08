백준 온라인 강의
프로그래밍 대회에서 사용하는 C, C++, STL
챕터 2 STL Container(2) 강의 정리 https://code.plus/lecture/4

# 연관 컨테이너
- 순서가 없다
- BST/Red Black Tree 로 구현되어 있다.
## set
- 중복값을 허용하지 않는다.
```c
set<int> s1;
set<int> s2 = {1,2,3,4,5};
set<int> s3 = {1,1,1,1,2,2,2,2,2,3,3,3};

cout<<s1.size()<<'\n'; //0
cout<<s2.size()<<'\n'; //5
cout<<s3.size()<<'\n'; //3 중복값을 허용하지 않기 때문
```
- set의 내부에서 정렬된 상태로 있는다. (오름차순)
- 내림차순으로 만들고 싶은 경우
```c
set<int, greater<int>> s4;
```
#### set에 insert하기
```c
set<int> s;
s.insert(1); s.insert(3); s.insert(2); //1 2 3 

cout << s.size() << '\n'; //3

pair<set<int>::iterator, bool> result = s.insert(4);
cout << "result iterator = " << *result.first << '\n'; //4
cout << "result bool = " << result.second << '\n'; //1 
//insert의 첫번째 반환값 : insert한 값이 어디에 있는지 / 두번째 반환값 : 성공여부의 bool값

auto result2 = s.insert(3); //이미 3이 있으므로 중복 불가
cout << "result iterator = " << *result2.first << '\n'; //3 이미 들어가 있음
cout << "result2 bool = " << result2.second << '\n'; //0 실패
```
#### set 삭제하기 [시간 O(logN)]
```c
set<int> s ={2,3,4,5};

auto it = s.begin(); //'2' 3 4 5
++it; //2 '3' 4 5 
cout << "*it = " << *it << '\n'; //3
it = s.erase(it); //2 '4' 5 (3을 지우면서 it가 두번째 작은 값인 4를 가리키게 됨)
cout << "*it = " << *it << '\n'; //4
cout << "s.size() = " << s.size() << '\n'; //3 
```
#### set 순회하기
```c
set<int> s = {5,2,4,1,3,7,6};

//set(바이너리 트리구조)이므로 시간 복잡도는 원래 O(logN)이나, '++it'를 하면서 O(NlogN)이 된다.
for(auto it = s.begin(); it!=s.end(); ++it) {
  cout << *it << ' ';
}
cout << '\n';

for (auto x : s} {
  cout << x << ' ';
}
cout << '\n';
```
#### [#10876 중복 빼고 정렬하기](https://www.acmicpc.net/problem/10867)
- set의 중복을 제외하고 오름차순인 특징을 이용해서 풀기
- 입력받은 수를 모두 set에 넣은 다음 출력하면 된다.
```c
#include <iostream>
#include <set>
using namespace std;
int main() {
    int n;
    cin >> n;
    set<int> s;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    for(auto x : s){
        cout << x << ' ';
    }
    cout << '\n';
    
    return 0;
}
```
#### set에 들어가 있는 값 확인하기 (find)
- set은 트리 형태이기 때문에 찾는 시간은 O(logN)
- print()는 it값이 end면 end를 리턴하고, 아니면 해당 값을 출력한다. 
```c
set<int> s = {7,5,3,1};

auto it = s.find(1);
print(s,it); //1

it = s.find(2);
print(s,it); //end
```
#### 어떤 값이 들어가있는지 확인할때는 count를 사용한다
```c
set<int> s ={7,1,5,3};

for(int i=1; i<=9; i++){
  cout << "s.count(" << i << ") = " << s.count(i) << '\n';
} //1일때는 1, 2일때는 0, 3일때도 0, ... 5일때 1 ...
```
#### [#10815 숫자카드](https://www.acmicpc.net/problem/10815)
- set에 숫자카드를 모두 넣어주고 count값을 출력해주면 된다.
- 총 시간 복잡도는 NlogN(N개삽입) + MlogN(M번검사)
```c
#include <iostream>
#include <set>
using namespace std;
int main() {
    int n;
    scanf("%d",&n);

    set<int> s;
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d",&x);
        s.insert(x);
    }

    int m;
    scanf("%d",&m);

    for (int i=0; i<m; i++) {
        int x;
        scanf("%d",&x);
        printf("%d ",s.count(x));
    }

    printf("\n");

    return 0;
}
```
#### [숫자카드2]()
- 숫자카드에 중복이 있을 수 있다.
- multi set은 같은 수를 여러개 저장할 수 있으므로 이를 이용한다
```c
#include <iostream>
#include <set>
using namespace std;
int main() {
    int n;
    scanf("%d",&n);

    multiset<int> s;
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d",&x);
        s.insert(x);
    }

    int m;
    scanf("%d",&m);

    for (int i=0; i<m; i++) {
        int x;
        scanf("%d",&x);
        printf("%d ",s.count(x));
    }

    printf("\n");

    return 0;
}
```
- 그러나 위 방법은 시간초과 오류가 발생한다.
## map
- key/val로 이루어진 자료구조
- 배열처럼 이루어져 있는데 배열 안의 값이 꼭 정수가 아니어도 된다는 것이 장점이다.
```c
map<int,int> d1; 
map<int,int> d2 = {{1,2}, {3,4}, {5,6}};
//d2[1]=2, d2[3]=4, d2[5]=6

cout << d1.size() <<'\n'; //0
cout << d2.size() <<'\n'; //3

d1[10]=20; //10이라는 key값이 없을 경우 새로 추가한다
cout << d2[1] <<'\n'; //2
cout << d2[2] <<'\n'; //0 없음
cout << d2[3] <<'\n'; //4
cout << d2[4] <<'\n'; //0
cout << d2[5] <<'\n'; //6
```
- 하나를 접근하는데 걸리는 시간이 key를 트리에서 찾아야하기 때문에 O(logN)이 걸린다.
#### map에서 값을 탐색할 경우 크기가 달라지지 않게 주의해야 한다
```c
for(int i=1; i<=10; i++){
  if(d1[i] {
    cout <<i << ' ';
  }
}
cout <<'\n';
//이 경우 d1.size는 10이 된다.(자동으로 사이즈가 커짐)

for(int i=1; i<=10; i++){
  if(d2.cont(i)){
    cout << i << ' ';
  }
}
cout <<'\n';
//이 경우 d2.size는 원래 크기인 5이다.
```
- 시간 복잡도는 O(logN)이므로 주의
#### map을 iterator형태로 접근하기
```c
map<int,int> d = {{1,2},{3,4},{5,6}};

for(auto it=d.begin(); it!=d.end(); ++it){
  cout << (it->first) << ' ' << (it->second) << '\n';
}

for(auto p : d) {
  cout << p.first << ' '<< p.second << '\n';
}
```
- pair처럼 접근하며, 실제로도 pair이다 
#### [1076 저항](https://www.acmicpc.net/problem/1076)
- string을 int로 바꿔야함
```c
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    map<string, int> d ={
        {"black",0},{"brown",1},{"red",2},
        {"orange",3},{"yellow",4},{"green",5},
        {"blue",6},{"violet",7},{"grey",8},{"white",9}
    };
    
    string a,b,c;
    cin >>a>>b>>c;
    long long ans = (long long)(d[a]*10 + d[b]);
    for(int k=0; k<d[c]; k++){
        ans *=10LL;
    }
    
    cout <<ans<<'\n';
    return 0;
    
}
```
#### [1764 듣보잡](https://www.acmicpc.net/problem/1764)
## stack
- 컨테이너 어댑터 , 앞의 벡터나 덱 리스트를 이용해서 만든 어댑터 형태
```c
stack<int> s1;
//그냥 만들면 덱구조가 됨

stack<int, list<int>> s2;
//list구조로 만들고 싶을 땐 명시

deque<int> d ={1,2,3,4,5};
stack<int> s3(d);
//값을 초기화 할때 덱을 먼저 만들고, 그 덱틀 이용해서 스택을 만든다.
```
#### stack의 push,pop,top,size,empty
- stack은 front/back개념이 없고 push/pop만 있다
```c
stack<int> s;

for (int i=1; i<=5; i++){
  s.push(i); //1 2 3 4 5 순서대로 들어감
}

for (int i=0; i<2; i++){
  cout << s.top() << '\n';
  s.pop();
}
/*
첫번째 루프 : 1 2 3 4 '5'
             1 2 3 4 
두번째 루프 : 1 2 3 '4'
             1 2 3
*/
cout << s.size() <<'\n'; //3
cout << s.empty() <<'\n'; //0
```
#### stack에서 pair를 넣을때
```c
stack<pair<int,int>> s;
s.push(make_pair(1,2));
s.push({3,4});
s.emplace(5,6);
```
## queue(줄서기 개념)
- 선언하는 방법도 stack과 비슷하다.
- 제일 앞, 제일 뒤 두가지에 접근할 수 있으므로 front/back으로 접근 가능
#### queue의 push, pop, front, back, empty
```c
queue<int> q;

for(int i=1; i<=5; i++){
  q.push(i);
}//1 2 3 4 5 

for(int i=0; i<2; i++){
  cout<<q.front() << ' ' <<q.back() << '\n';
  q.pop();
}
/*
첫번째 루프 : 1 5
             2 3 4 5 (앞에서 부터 없어짐)
두번째 루프 : 2 5
             3 4 5
*/
```
- stack과 pair로 넣는 방법이 동일하다.
## priority_queue
- 기존과 달리 우선순위가 가장 높은 것이 먼저 나오는 것(정수의 경우 수가 가장 큰 것)
- 최대 힙
```c
vector<int> a = {5,2,4,1,3};

priority_queue<int> q1;

for(int x : a){
  q1.push(x);
}
//q1에 벡터 a 값을 모두 넣는다.

while(!q1.empty()){
  cout << q1.top() << ' ';
  q1.pop();
} //5 4 3 2 1 큰 수 부터 top으로 출력됨
cout<<'\n';
```
#### 최소 힙으로 바꾸고 싶을때
- 위와 같은 코드에서 모든 값에 (-)를 붙인다
```c
vector<int> a = {5,2,4,1,3};

priority_queue<int> q1;

for(int x : a){
  q1.push(-x); //(-)를 붙인다 -> -5 -2 -4 -1 -3
}

while(!q1.empty()){
  cout << -q1.top() << ' '; //(-)를 붙여 양수로 만든다
  q1.pop();
} //1 2 3 4 5 작은 수 부터 top으로 출력됨
cout<<'\n';
```
- -2^31일 경우 음수를 붙였을 때 자기 자신이 나오므로 수의 범위를 반드시 확인한다.
- 따라서 올바른 최소힙은
```c 
vector<int> a = {5,2,4,1,3};

priority_queue<int, vector<int>, greater<int>> q3;
for(int x : a){
  q3.push(x);
}
while(!q3.empty()){
  cout << q3.top() << ' ';
  q3.pop();
}
cout << '\n';
```
## bitset
- vector <bool>과 같은 형태다.
- bool처럼 1Byte만 필요하다. bitset은 and/or/not과 같은 비트연산이 가능하다.
```c
bitset<8> b1; //0,0,0,0,0,0,0,0 8자리
bitset<10> b2(88); //0,0,0,1,0,1,1,0,0,0 10자리
//88을 2진수로 표현하면 1011000인데 10자리를 맞추기 위해 앞에 000을 붙임bitㅑ
bitset<8> b3("10110"); //0,0,0,1,0,1,1,0 8자리
```
#### bitset값 출력하기
```c
bitset<10> b(88);

for(int i=0; i<b.size(); i++){
  cout<< b[i] <<'\n';
} //b[i]로 특정위치값 출력가능

cout << b << '\n'; //0001011000 모두출력
```
#### 각종 메소드
```c
bitset<10> b(88); //0001011000

cout << b.test(4) <<'\n'; //b[4]와 같다 1 (뒤에서부터다)

b.set(0); //0번째 자릿값을 1로 바꾼다. 0001011001

b.reset(3); //3번째 자릿값을 0으로 바꾼다. 0001010001

b.filp(2); //0은 1로, 1은 0으로 바꾼다. 2번째 값을 filp한다. //0001010101

//인자를 넣지 않으면 모든 값을 바꾼다
b.flip(); //전체가 바뀐다. 
b.set(); //111111111
b.reset(); //00000000
```
#### bitset의 세가지 연산
- all() 모든 bit가 1인지
- any() bit가 1인 것이 1개 이상인지
- none() 모든 bit가 0인지
- count() 1인 비트의 수
#### bitset의 비트연산
```c
bitset<10> b1(88); // 0,0,0,1,0,1,1,0,0,0
bitset<10> b2(47); // 0,0,0,0,1,0,1,1,1,1

cout << (b1 & b2) << '\n'; //0000001000 and 연산
cout << (b1 | b2) << '\n'; //0001111111 or 연산
cout << (b1 ^ b2) << '\n'; //0001110111 xor 연산
cout << ~(b1) << '\n'; //1110100111 not 연산

cout << (b1 << 2) << '\n'; //0101100000  shift연산
cout << (b2 >> 2) << '\n'; //0000001011
```
#### [12813 이진수 연산](https://www.acmicpc.net/problem/12813)
- 10만짜리 비트셋을 만들어서 각각의 연산을 출력
- bitset<변수>가 불가능하다는 점 주의 
```c
#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    bitset<100000> a(s1),b(s2);
    cout<<(a&b)<<'\n';
    cout<<(a|b)<<'\n';
    cout<<(a^b)<<'\n';
    cout<<(~a)<<'\n';
    cout<<(~b)<<'\n';
    return 0;
}
```
