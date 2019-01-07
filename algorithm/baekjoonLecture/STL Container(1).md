백준 온라인 강의   
프로그래밍 대회에서 사용하는 C, C++, STL   
챕터 2 STL Container(1) 강의 정리 https://code.plus/lecture/3

## STL
1. 알고리즘
2. 컨테이너(자료저장)
3. 함수
4. 이터레이터
로 이루어져 있다.

## pair
- 두 자료형을 묶을 수 있다. (항상 두 개)
- 첫번째 자료는 fist, 두번째 자료는 second로 접근할 수 있다.
- #include <utility> 이지만, 보통 algorithm, vector와 같은 헤더파일에서 include하기 때문에 따로 하는 경우는 없다.
- make_pair 또는 생성자를 이용해서 만들 수 있다.
```c
pair<int,int> p1;
cout << p1.first << ' ' << p1.second << '\n';
//이 경우 둘 다 0이 들어가 있다.

p1 = make_pair(10,20);
cout << p1.first << ' ' << p1.second << '\n';

p1 = pair<int,int>(30,40);
cout << p1.fist << ' ' << p1.second << '\n';

pair<int, int> p2(50,60);
cout << p2.first << ' ' << p2.second << '\n';
```
## tuple
- tuple은 pair와 같지만 여러 개를 묶을 수 있다.
- get을 이용해 인덱스로 접근해야 한다.
- #include <tuple>에 정의되어 있다.
- get 함수 안에 변수를 넣을 수 없으니 조심
```c
tuple<int,int,int> t1 = make_tuple(1,2,3);

cout << get<0>(t1) << ' '; //1
cout << get<1>(t1) << ' '; //2
cout << get<2>(t1) << '\n'; //3

/*
for(int i=0; i<3; i++){
  cout << get<i>(t1) << '\n';
}
*/
```
## tie
-변수를 묶어주는 형태를 만들어줌
```c
auto t = make_tuple(10,20,30);

//원래 방법, get에 변수 사용 불가이므로 하나씩 넣어줌
int x = get<0>(t);
int y = get<1>(t);
int z = get<2>(t);

cout << x << ' ' << y << ' ' << z << '\n';

//초기화
x = y = z = 0;

//tie를 이용하여 간단하게
tie(x,y,z) = t;

cout << x << ' ' << y << ' ' << z << '\n';
```
- tie는 pair에도 사용 가능
- 변수값을 무시해야하는 경우는 ignore를 사용
```c
tie(x,y,ignore) = t
// 10,20 만 들어감 
```
-swap함수 간단하게 구현 가능  
`tie(a,b)=make_pair(b,a);`

# 컨테이너들에 대해 알아보자
## vector
- 길이를 변경할 수 있는 배열이다
- #include <vector>
#### vector의 선언방법은 다음과 같다
```c
#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> v1; //길이가 0
  vector<int> v2(10); //길이가 10
  vector<int> v3(15,1); //길이가 15, 초깃값, 즉 모든 값이 1
  vector<int> v4 = {1,2,3,4,5}; //초기화 리스트를 이용
  
  return 0;
}
```
- 다양한 형태도 가능
```c
vector<pair<int,int>> v5;
vector<pair<int,int>> v6 = {{1,2},{3,4}};

//1차원 배열안에 1차원배열이 들어간 2차원배열
vector<vector<int>> v7; 

//int v8[n][m]과 같은 2차원 배열을 만듬
int n=10, m=20;
vector<vector<int>> v8(n, vector<int>(m));
```
#### 벡터의 값 추가, 삭제 사이즈 바꾸기 
```c
vector<int> a = {1, 2, 3, 4, 5};

a.push_back(6); // [1, 2, 3, 4, 5, 6]
a.push_back(7); // [1, 2, 3, 4, 5, 6, 7]

a.pop_back(); // [1, 2, 3, 4, 5, 6]
a.pop_back(); // [1, 2, 3, 4, 5]
a.pop_back(); // [1, 2, 3, 4]

a.clear(); // []

a.resize(5); // [0, 0, 0, 0, 0]

a.clear(); // []

a.push_back(1); // [1]
a.push_back(2); // [1, 2]

a.resize(5); // [1, 2, 0, 0, 0]
a.resize(3); // [1, 2, 0]

a.clear(); // []
```
#### 벡터의 길이, 비어있는지 확인
```c
vector<int> a = {1, 2, 3, 4};
cout << "size = " << a.size() << '\n'; //4

a.push_back(5);

cout << "size = " << a.size() << '\n'; //5
cout << "empty = " << a.empty() << '\n'; //false->0

a.clear();

cout << "size = " << a.size() << '\n'; //0
cout << "empty = " << a.empty() << '\n'; //true->1
```
#### 벡터에서 값 출력하기
```c
vector<int> a = {1,2,3};

cout << "front = " << a.front() << ‘\n’; //1
cout << "a[1] = " << a[1] << ‘\n’; //2
cout << "back = " << a.back() << ‘\n’; //3

a.push_back(4);

for(int i=0; i<a.size(); i++) {
  cout << a[i] << ' '; //1 2 3 4 
}
cout <<'\n';
```
- 위의 코드를 Range based-code 사용시 간단하게 표현 가능
```c
vector<int> a = {1,2,3,4,5};

for(int &x : a){
  cout << x << ' ';
}
cout << '\n';
```
#### iterator 사용
```c
vector<int> a = {1,2,3,4,5};

//end값은 마지막의 다음번째 값이다. it값이 증가하여 해당값에 도달하면 for문을 벗어난다.
for (vector<int>::iterator it =a.begin(); it != a.end(); ++it) {
  cout << *it << ' '; //포인터처럼 *를 붙여줘서 출력
}
cout << '\n';
//출력값 : 1 2 3 4 5

//begin값에서 빼주면 해당 인덱스를 알 수 있다. 
for(auto it=a.begin(); it != a.end(); ++it) {
  cout << "a[" << (it - a.begin()) << "] = " << *it << '\n';
}
```
```c
vector<pair<int,int>> a;
a.emplace_back(1,2);
a.push_back({3,4});
a.push_back(make_pair(5,6));
//a={1,2},{3,4},{5,6} 이렇게 들어감

//두 for문 모두 같은 결과가 출력된다.
for (auto &x : a) {
  cout << x.first << ' ' << x.second << '\n';
}

for (auto it =a.begin(); it != a.end(); ++it) {
  cout << it->first << ' ' << it->second << '\n'; //(*it).first와 같다.
}
```
#### 벡터 중간에 값 넣기
```c
//배열안의 값을 모두 출력하는 print 함수 생성
void print(vector<int> &a) {
  for(int x : a) {
  cout << x << ' ';
  }
  cout <<'\n';
}

vector<int> a = {1, 2, 3};
print(a); //1 2 3

auto it = a.begin(); //1을 가리킴
a.insert(it, 4); print(a); //4 1 2 3

it = a.begin() + 1; //1을 가리킴
a.insert(it, 5, 0); print(a); //4 0 0 0 0 0 1 2 3 , it에 0을 다섯개 추가

it = a.begin() + 2; //4 0 '0' 0 0 0 1 2 3 을 가리킴
vector<int> b = {10, 20};
a.insert(it, b.begin(), b.end()); print(a); //4 0 10 20 0 0 0 0 1 2 3
```
- 벡터에 값을 넣을때 걸리는 시간은 벡터의 크기만큼 O(n)이다.
#### 벡터 중간에 있는 값 삭제하기
```c
vector<int> a = {1, 2, 3, 4, 5};
print(a); //1 2 3 4 5

a.erase(a.begin()+2);
print(a); //1 2 4 5

a.erase(a.begin()+1, a.begin()+3); //erase(begin, end)인데 end값은 포함하지 않는다. 즉 end전의 값까지 지움
print(a); //1 5 
```
- 역시 시간은 O(n)이다
## deque(Double Ended Queue) 자료구조
- 큐가 두개 붙어있는 구조.
- 큐는 앞에서 pop 뒤에서 push인데, deque은 양쪽에서 push/pop이 일어남
- 따라서 push_front/back , pop_front/back 네가지가 가능
```c
deque<int> d;
d.push_back(1); 
print(d); //1

d.push_front(2); 
print(d); //2 1

d.push_back(3); 
print(d); //2 1 3

d.pop_back(); print(d); //2 1 
d.pop_front(); print(d); //1
```
## list 자료구조 
- 이중 연결 리스트 
- 프로그래밍 대회에서는 거의 사용하지 않음
- 벡터나 덱과 같은 함수 사용가능 (sort, reverse를 제외)
- insert, erase O(1)을 사용하기 때문에 중간에 있는 값을 삽입/삭제할때 가장 효율적임
```c
list<int> l = {2, 1, -5, 4, -3, 6, -7}; 
print(l);

l.sort(); print(l); //순서대로 정렬

l.sort(greater<int>()); print(l); //내림차순 정렬

l.sort([](int &u, int &v) {
  return abs(u) < abs(v);
});
print(l); //절댓값으로 정렬

l.reverse(); print(l); //역순으로 정렬
```
- vector, list, deque은 순서가 있으므로 순차자료구조라고 한다.
### [#2346 풍선터뜨리기](https://www.acmicpc.net/problem/2346)
### [#1406 에디터](https://www.acmicpc.net/problem/1406)




  




