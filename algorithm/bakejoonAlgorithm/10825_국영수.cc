/*
  새로운 struct를 구현하는 경우다. 비교함수 cmp를 새로 만들어준다.
  if else문의 늪에 빠지지 않도록 조심..
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//Person struct 정의
struct Person{
	string name;
	int kor, eng, math;
};
bool cmp(const Person &u, const Person &v){ //const와 &필수
	if(u.kor > v.kor){ //국어점수가 감소하는 순서로
		return true;
	}else if(u.kor == v.kor){ //국어점수가 같으면 
		if(u.eng < v.eng){ //영어점수가 감소하는 순서로
			return true;
		}else if(u.eng == v.eng){ //국어,영어점수가 같으면
			if(u.math > v.math){ //수학점수가 감소하는 순서로
				return true;
			}else if(u.math==v.math){ //모든 점수가 가틍면 
				return u.name < v.name;    //이름이 사전 순으로 증가하는 순서로
			}
		}
	}
	return false; //모두 아니면 false
}
int main() {
	int n;
	cin >> n;
	vector<Person> a(n);
	for(int i=0; i<n; i++){
		cin >> a[i].name >> a[i].kor >> a[i].eng >> a[i].math; //sturct안의 객체에 넣어주기
	}
	sort(a.begin(),a.end(),cmp);
	
	for(int i=0; i<n; i++){
		cout << a[i].name << '\n';
	}
	
	return 0;
}
