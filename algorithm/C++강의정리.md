백준 온라인 강의 C++ 강의 정리 https://code.plus/lecture/2
### 1. STL(Standard Template Library)
- C++이 가지는 프로그래밍 언어로서의 특징 중 하나로 일반화 프로그래밍을 들 수 있따.
- 알고리즘에 그 중점을 둔다
#### 2. STL구성 요소
1. 반복자(iterator)
2. 컨테이너(container)
3. 알고리즘(algorithm)
#### 2.1. 컨테이너(container)
- 같은 타입의 여러 객체를 저장하는 일종의 집합
- 클래스 템플릿으로, 컨테이너 변수를 선언할 때 컨테이너에 포함할 요소의 타입을 명시할 수 있다.
#### 2.2. 반복자(iterator)
- STL 컨테이너에 저장데이터를 순회하는 과정을 일반화한 표현
- 반복자로, 포인터와 비슷하며, 컨테이너에 저장되어 있는 원소들을 참조할 때 사용한다.
- end()라는 멤버함수는 컨테이너의 마지막 원소가 아니라 마지막 원소의 바로 다음번 원소이다.

- C에서는 scanf/prinf 사용, C++에선 cin/cout을 사용한다.
```
cin>>x; 
cout<<x;
```
## getline
`getline(cin,s);`
한줄 다 입력 받기
## setprecision
```c
#include <iomanip>
#include <iostrem>
using namespace std;
int main() {
  double f = 3.14159265358979;
  cout << setprecision(5) << f << '\n';
  cout << setprecision(8) << f << '\n';
  cout << setprecision(10) << f << '\n';
  cout << fixed << setpricision(5) << f <<'/n';
  return 0;
}

//3.1416 5자리(소수점 5자리에서 반올림)
//3.1415927
//3.1515926554
//3.14159 fixed 사용시 소수점 아래 5글자를 출력
```
## endl vs '\n'
- 줄 바꿀때, '\n' endl보다 100배 빠르다
- endl은 줄 바꿈을 출력하고, 스트림을 flush시키는 기능도 포함되어 있기 때문
- scanf/print가 cin/cout보다 빠르다
- `ios_base::sync_with_stdio(false);`
- 이렇게 하면 cin/cout을 더 빠르게 사용할 수 있는데, scanf/printf와 섞어쓸 수 없게 된다.

## auto
1. 
- 컴파일러가 타입을 추론해서 결정한다.
- 변수의 타입을 명확하게 알 수 있어야 한다.
- 아래 코드가 컴파일 에러인 이유?
```c
auto a, b;
cin >> a >> b;
cout << a+b << '\n';
```
- 정답 : `auto a=0,b=0;`으로 선언하여 int라는 것을 알려줘야 한다.
- 이 경우 아래에서 a="abc", b=3.14 등 으로 타입을 변경하여 사용하는 경우 컴파일 에러가 발생한다.
2. 
- 이터레이터를 사용할 때 매우 편리하다.
```c
map<pair<int,int>, vector<pair<int,string>>> d;
for (map<pair<int,int>, vector<pair<int,string>>>::iterator 
    it = d.begin(); it != d.end(); ++it) {
}
```
- 이런 코드를
```c
map<pair<int, int>, vector<pair<int, string>>> d;
for ( auto 
      it = d.begin(); it != d.end(); ++it) {
}
```
- 이렇게 줄일 수 있다. 
## Range-based for (for each 문)
- 케이스 1
```c
///vector a에 있는 값을
vector<int> a {1,2,3,4,5};

//원래 이렇게 출력할 수 있지만
for (int i=0; i<a.size(); i++) {
  cout << a[i] << ' ';
}

//auto를 이용하여 더 간단하게 표현 가능
for (int x : a ) {
 cout << x << ' ';
}
cout << '\n';

//결과값 : 1 2 3 4 5 

- 케이스 2
```c
vector<pair<int,int>> a = {{1,2},{3,4},{5,6}};


for (int i=0; i<a.size(); i++) {
  cout << a[i].first + a[i].second << ' ';
}
cout << '\n';

//'&'를 붙이면 값복사가 아니라 단순히 참조를 하기 때문에 더 빠름
for ( auto &p : a) {
  cout << p.first + p.second <<' ';
}
cout << '\n';
```
- 케이스 3
- 초기화 리스트를 사용하면 간편한 코드 사용 가능
```c
int sum=0;
//초기화 리스트를 사용하여 1,2,3,4가 x에 순서대로 들어가게 함
for(auto x : {1,2,3,4}) {
  sum += x;
}
cout << "sum = " << sum << '\n';

//배열에도 사용가능
int a[] = {1,2,3,4,5};

sum=0;
for(auto x : a) {
  sum += x;
}
cout << "sum = " << sum << '\n';
//15
```

- 케이스 4
```c
//c언어 스타일의 문자열은 마지막에 null문자가 들어가므로 1이 큰 7번의 for문을 순회한다.
//7 출력
const char cstr[] = "string";
sum = 0;
for(auto x : cstr){
  sum += 1;
}
cout << "sum = " << sum << '\n';

//6번 순회하여 6 출력
string str = "string";
sum=0;
for (auto x : str) {
  sum+=1;
}
cout << "sum = " << sum << '\n';
```
## 초기화 리스트
- vector 선언시 배열처럼 값을 초기화 할 수 있게 되었다.
```c
vector<int> a = {1, 3, 7, 13, 50};
```

```c
struct Person {
  string name;
  int age;
};

//순서가 같으면 name/age에 순서대로 값이 들어간다.
Person p = {"you", 20};
//각각 key/value 값으로 들어간다.
map<int, string> m = { {20,"a"}, {10,"hi"} };
//복잡한 형태도 사용가능
map<int, vector<pair<int,int>>> m2 = {
{10, {{1,2}, {3,4}}},
{20, {{5,6}, {7,8}, {9, 10}}}
};
```
## 람다 함수
- 익명함수라도고 하며, 함수와 같은 형태인데 함수에 이름이 없는 것을 말한다.
- [캡쳐](함수 인자){함수 내용}
```c
int sum(int x, int y) {
  return x + y;
}
cout << sum(1,2) << '\n';

//위의 함수를 람다 함수로 만들면
cout << [](int x, int y){
  return x + y; 
}(1, 2) << '\n';
```
- auto를 사용할 수 있다.
```c
auto sum2 = [](int x, int y){
  return x + y;
}
cout << sum2(1,2) << '\n';
```
### [#2555 생일 출력하기 문제](https://www.acmicpc.net/problem/2555)
```c
#include <iostream>
using namespace std;
int main(){
    auto print = []{
        cout << "10/14" << '\n';
    };
    print();
}
```
### [#10871 x보다 작은 수](https://www.acmicpc.net/problem/10871)
- 밖에 선언되어 있는 x를 사용하려면 캡쳐안에 '&'를 붙여주면 참조형태로 람다 내부에서 접근 가능
```c
#include <iostream>
using namespace std;
int main(){
    int n,x;
    cin >> n >> x;
    auto is_less = [&](int number){
        return number<x;
    };
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        if(is_less(num)){
            cout << num << ' ';
        };
    }
    cout << '\n'; //이걸 안하니까 컴파일 에러뜬다.. 왜지?
}
```
#### &
- 캡쳐에 &를 넣으면 선언하는 시점에 바깥에 있는 변수를 모두 사용할 수 있다.
- &x와 같이 어떤 변수를 사용할지 선언해도 된다.
```c
int x=10;
int y=20;

auto f = [&x,y](){
  x += 10;
  //y += 10; 이 주석을 해제하면 컴파일 에러
};

cout << x << y << '\n'; //10 20
f();
cout << x << y << '\n'; //20 20
f();
cout << x << y << '\n'; //30 20
```
- 지금까지 auto로 변수를 받아왔는데 변수 타입은?
- 함수의 변수 타입은 #include <functional> 에 선언되어 있다.
- function<리턴타입(콤마로 구분한 인자의 타입들)>
```c
//인자가 없기 때문에 아무것도 안적어도 됨
fuction<void()> print=[]{
};

//인자가 int이므로 void(int)
function<void(int)> print2=[](int x){
};

//인자 2개와 리턴티입이 int이므로
function<int(int,int)> sum =[](int x, int y) {
  return x+y;
}








    



