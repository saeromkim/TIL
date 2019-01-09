//백준 알고리즘 강의 들으면서 푼 문제들 정리


//2558: A+B - 2
#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin >> a >>b;
    cout << a+b <<'\n';
    return 0;
}

//10950: A+B - 3
#include <iostream>
using namespace std;
int main(){
    int n;
    int a,b;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&a,&b);
        printf("%d\n",a+b);
    }
    return 0;
}

/*
괄호 
- 여는 괄호의 번호를 스택에 넣고 닫는 괄호가 있으면 스택을 하나씩 없앤다.
- 스택의 성질을 이용하여 푼다
- 비슷한 문제가 많이 나오므로 중요하다 (계단 오르락 내리락하는 문제)
올바른 문자열이 아닌 예
1. 코드가 끝났는데도 스택이 비어있지 않는 경우 -> 짝이 맞는 닫는 괄호를 찾지 못함
2. 닫는 괄호가 있는데 없앨 스택이 없는 경우 -> 짝이 맞는 여는 괄호를 찾지 못함
*/
```c
#include <iostream>
#include <string>
using namespace std;
string valid(string s){
    int cnt = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '(') {
            cnt += 1;
        } else {
            cnt -= 1;
        }
        if (cnt < 0) {
            return "NO";
        }
    }
    if (cnt == 0) {
        return "YES";
    } else {
        return "NO";
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin >> s;
        cout << valid(s) << '\n';
    }
    return 0;
}
```


