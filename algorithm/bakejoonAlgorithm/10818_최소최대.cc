/*
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
