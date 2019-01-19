/*
두번째 풀었을때
min_element/max_element 함수를 이용해서 풀었다.
이터레이터를 출력할 때 auto형 변수에 넣은 후, *를 이용해서 출력해야함에 유의한다. (바로 출력 불가하다)
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	auto min = min_element(a.begin(), a.end());
	auto max = max_element(a.begin(), a.end());
	cout << *min << " ";
	cout << *max << "\n";
	
    return 0;
}

/*
첫번째 풀었을때
최소,최대값을 구하는 문젠데 생각보다 조금 헤맸다.
문제에서 주어진 최소최대값을 min,max에 반대로 초기화하는 것이 첫번째 핵심이고,
temp로 스와치 하는게 아니라 입력받은 수를 바로바로 min과 max값과 비교하여 넣으면 되는 비교적 간단한 문제다.
*/
#include <iostream>
#include <algorithm> 
using namespace std;
int main(){
	int n,x;
	int min = 1000000;
	int max = -1000000;
	cin >> n;
	//n만큼 출력받기 
	while(n--){
		cin >> x;
		if(min>x){
			min=x;
		}
		if(max<x){
			max=x;
		}
	}
	cout << min << " " ;
	cout << max;
	
	return 0;
}
