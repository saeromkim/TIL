//dfs로 풀었다 혼자 못풀고 몇달 전 푼 그대로 풀었다.
#include <iostream>
using namespace std;
int a[500][500]; //입력배열
bool check[500][500]; //방문했는지 여부를 체크하기 위한 배열
int x[] = {0,0,1,-1};
int y[] = {1,-1,0,0};
int n,m;
int ans = 0;

void go(int i, int j, int sum, int cnt){
	//4가지에 대해 순회
	if(cnt == 4){
		if(ans<sum) ans = sum; 
		return;
	}
	if(i<0 || i>=n || j<0 || j>=m) return;
	if(check[i][j]) return;
	
	check[i][j] = true; //순회함으로 체크
	//상하좌우 모든 칸에 대해 방문하는 재귀
	for(int k=0; k<4; k++){
		go(i+x[k], j+y[k], sum + a[i][j], cnt+1);
	}
	check[i][j] = false; //다시 순회하기 위해 원래대로
}

int main() {
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
		}
	}
	
	//모든 칸에 대해 돌려본다
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			go(i,j,0,0);
	
			//한번에 그리기 불가능한 ㅏㅓㅗㅜ는 직접해준다
			//ㅗㅜ
			if(j+2 < m){
				int col = a[i][j] + a[i][j+1] + a[i][j+2];
				if(i+1 < n){
					int col2 = col + a[i+1][j+1];
					if(ans<col2) ans = col2;
				}
				if(i-1 >= 0){
					int col2 = col + a[i-1][j+1];
					if(ans<col2) ans = col2;
				}
			}
			//ㅓㅏ
			if(i+2 < n){
				int row = a[i][j] + a[i+1][j] + a[i+2][j];
				if(j+1 < m){
					int row2 = row + a[i+1][j+1];
					if(ans<row2) ans = row2;
				}
				if(j-1 >= 0){
					int row2 = row + a[i+1][j-1];
					if(ans<row2) ans = row2;
				}
			}
		}
	}
	
	cout<<ans;
	
	
	return 0;
}


//재귀 사용해서 푸는 문제
#include <iostream>
using namespace std;
int a[500][500];
bool c[500][500];
int n,m;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int ans = 0;
void go(int x, int y,int sum, int cnt){
	if(cnt == 4){
		if(ans<sum) ans = sum;
		return;
	}
	if(x < 0 || x >= n || y < 0 || y >= m) return;
	if(c[x][y]) return;
	c[x][y] = true;
	for(int k=0; k<4; k++){
		go(x+dx[k],y+dy[k],sum+a[x][y],cnt+1); //모든 모양이 4칸이동하는 것이므로 4번 순회
	}
	c[x][y]=false; //모두 순회해야하므로 다시 false
}
int main() {
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a[i][j];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			go(i,j,0,0);
      //ㅏ ㅓ ㅗ ㅜ 모양 모두 비교
			if(j+2 < m){
				int temp = a[i][j]+a[i][j+1]+a[i][j+2];
				if(i-1 >= 0){
					int temp2=temp+a[i-1][j+1];
					if(ans<temp2) ans=temp2;
				}
				if(i+1<n){
					int temp2=temp+a[i+1][j+1];
					if(ans<temp2) ans=temp2;
				}
			}
			if(i+2<n){
				int temp = a[i][j]+a[i+1][j]+a[i+2][j];
				if(j+1<m){
					int temp2=temp+a[i+1][j+1];
					if(ans<temp2) ans=temp2;
				}
				if(j-1>=0){
					int temp2=temp+a[i+1][j-1];
					if(ans<temp2) ans=temp2;
				}
			}
			
		}
	}
	cout << ans <<'\n';
	
	return 0;
}
