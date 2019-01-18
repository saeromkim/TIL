/*
  그냥 다 해보는 문제. 쉬운 문제임에도 해멨다.
  먼저 정렬을 하고 j=i+1을 하면서 차례대로 짝짓는게 핵심인듯!
*/
#include <iostream>
#include <algorithm>
using namespace std;
int a[9];
int n = 9;
int main() {
    int sum = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a,a+n);
    for(int i=0; i<n; i++){
    	for(int j=i+1; j<n; j++){
    		if(sum - a[i] - a[j] == 100){
    			for(int k=0; k<n; k++){
    				if(k==j || k==i) continue;
    				cout << a[k] << '\n';
    			}
    			return 0; //답이 하나라도 나오면 그냥 바로 리턴해버림
    		}
    	}
    }
    return 0;
}
