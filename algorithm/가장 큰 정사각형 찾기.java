/*
1와 0로 채워진 표(board)가 있습니다. 표 1칸은 1 x 1 의 정사각형으로 이루어져 있습니다. 
표에서 1로 이루어진 가장 큰 정사각형을 찾아 넓이를 return 하는 solution 함수를 완성해 주세요. 
(단, 정사각형이란 축에 평행한 정사각형을 말합니다.)
- 표(board)는 2차원 배열로 주어집니다.
- 표(board)의 행(row)의 크기 : 1000 이하의 자연수
- 표(board)의 열(column)의 크기 : 1000 이하의 자연수
- 표(board)의 값은 1또는 0으로만 이루어져 있습니다.

풀이: DP(Dynamic Programming) 알고리즘 사용
board[1][1]부터 왼쪽,상단,왼쪽상단 세가지 값을 비교하여 최솟값을 구한다.
최솟값+1을 dp[][]배열에 넣는다.
*/
import java.lang.*;//Math 클래스 사용
class Solution
{
    public int solution(int [][]board)
    {
        int [][] dp = new int[1001][1001];//int[1000][1000]이라고 하면 효율성 테스트 실패 뜸.
        int answer = 0;
        
        for(int i=1; i<=board.length; i++){
            for(int j=1; j<=board[0].length; j++){
                if(board[i-1][j-1]!=0){ //원래 배열의 왼쪽상단이 0이 아닌경우에 실행한다. (구하려고 하는 값의 범위를 벗어나지 않도록)
                   dp[i][j]= Math.min(dp[i-1][j-1],Math.min(dp[i-1][j],dp[i][j-1]))+1;
                   answer=Math.max(answer,dp[i][j]);
                }
            }
        }        

        return answer*answer;
    }
}
