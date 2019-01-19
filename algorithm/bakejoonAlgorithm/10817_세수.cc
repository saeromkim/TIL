/*
  두 번째로 큰 정수를 출력하는 문제
  정렬 후 중간 값 출력. 내가 품
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> a(3);
    for(int i=0; i<3; i++){
    	cin>>a[i];
    }
    sort(a.begin(), a.end());
    cout << a[1]<<'\n';
    return 0;
}
/*
  min, max를 이용해서도 푼다
*/
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    auto p = minmax({a,b,c}); //pair 값이 반환되므로 auto에 넣는다
    cout << (a+b+c) - p.first - p.second <<'\n'; //min,max동시에 구해서 없애기
    //cout << (a+b+c) - min({a, b, c}) - max({a, b, c}) << '\n'; 
    return 0;
}

