#include <iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int ans=1;
	for(int i=1; i<=n; i++){
		ans*=i;
	}
	cout<<ans;
	return 0;
}

//재귀를 이용한 백준코드
#include <iostream>
using namespace std;
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}
int main() {
    int n;
    cin >> n;
    cout << factorial(n) << '\n';
    return 0;
}
