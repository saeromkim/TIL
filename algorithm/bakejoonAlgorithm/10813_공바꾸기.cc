#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n,m;
	cin >> n >> m; 

	vector<int> a(n);
	for(int i=0; i<n; i++){
		a[i]+=i+1;
	}
	
	int i,j;
	while(m--){
		cin >> i >> j ;
		swap(a[i-1], a[j-1]); //
	}
	for(int x : a){
		cout << x << ' ';
	}
	cout << '\n';
	return 0;
}
