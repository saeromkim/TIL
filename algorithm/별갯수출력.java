/*
문제: 이 문제에는 표준 입력으로 두 개의 정수 n과 m이 주어집니다.
별(*) 문자를 이용해 가로의 길이가 n, 세로의 길이가 m인 직사각형 형태를 출력해보세요.

나의 풀이: 
b는 세로의 개수, a는 *문자 입력 수. 
c=b로 정의하여 b개수만큼 개행문자를 입력하되, 한번 루프를 수행할때마다 -1을 해준다.
c가 0이 아닐때만 개행문자를 추가하고 마지막에 출력한다.
*/
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        
        String print="";
        int c=b;
        
        for(int j=1; j<=b; j++){
            for(int i=1; i<=a; i++){
                print+="*";
            }
            if(c!=0){
                print=print+"\n";
                c-=1;
            }
        }

        System.out.println(print);
    }
}
