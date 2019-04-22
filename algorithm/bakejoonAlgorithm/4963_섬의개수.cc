/*
  30분만에 혼자 풀었당~~
  백준코드는 큐를 이용해서 풀었는데 나는 배열이 편해서 배열로 풀었다.
	x,y 좌표로 변경하여 연결요소의 개수의 개수 구하는 문제
*/
#include <iostream>
#include <algorithm>
using namespace std;
int x[] = {-1,0,1, -1,0,1, -1,0,1}; //대각선까지 탐색
int y[] = {1,1,1, 0,0,0, -1,-1,-1};
int a[50][50];
bool check[50][50];
int w,h;

void dfs(int i, int j){
    check[i][j] = true;
    for(int k=0; k<9; k++){
        int dx = i + x[k];
        int dy = j + y[k];
        if(dx>=0 && dx<h && dy>=0 && dy<w){
            if(check[dx][dy] == false && a[dx][dy] == 1){
                dfs(dx,dy);
            }
        }
    }
}

int main(){
    while(true){
        w=0, h=0;
        cin>>w>>h;
        if(w == 0 && h == 0) break; 
        //1. 배열 초기화
		for(int i=0; i<h; i++){
	            for(int j=0; j<w; j++){
	            	a[i][j] = 0;
	            	check[i][j] = false;
	            }
		}
        //2. 배열 입력 받기
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>a[i][j];
            }
        }
        //3. dfs 탐색하며 연결요소 개수 구하기
        int count = 0; //섬의 수
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(check[i][j] == false && a[i][j] == 1){
                    dfs(i,j);
                    count++;
                }
            }
        }
        cout<<count<<"\n";
        
    }
    
    return 0;
}
