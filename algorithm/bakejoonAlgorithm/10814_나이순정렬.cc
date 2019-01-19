#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Person{
	int age;
	string name;
	//int join; //그냥 sort를 사용할 경우 가입 순서를 명시해서 정렬해야하기 때문에, 
				//가입한 순서도 따로 저장해야 한다.
};
bool cmp(const Person &u, const Person &v){ //const와 &필수
	if(u.age < v.age){
		return true;
	}else{
		return false;
	}
}
int main() {
	int n;
	cin >> n;
	vector<Person> a(n);
	for(int i=0; i<n; i++){
		cin >> a[i].age >> a[i].name;
	}
	stable_sort(a.begin(),a.end(),cmp); //기존에 정렬되어있는 것은 그대로 오게
	
	for(int i=0; i<n; i++){
		cout << a[i].age <<" "<< a[i].name << '\n';
	}
	
	return 0;
}
