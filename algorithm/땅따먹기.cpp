/*
문제 설명
땅따먹기 게임을 하려고 합니다. 땅따먹기 게임의 땅(land)은 총 N행 4열로 이루어져 있고, 모든 칸에는 점수가 쓰여 있습니다. 
1행부터 땅을 밟으며 한 행씩 내려올 때, 각 행의 4칸 중 한 칸만 밟으면서 내려와야 합니다. 
단, 땅따먹기 게임에는 한 행씩 내려올 때, 같은 열을 연속해서 밟을 수 없는 특수 규칙이 있습니다.

예를 들면,

| 1 | 2 | 3 | 5 |

| 5 | 6 | 7 | 8 |

| 4 | 3 | 2 | 1 |

로 땅이 주어졌다면, 1행에서 네번째 칸 (5)를 밟았으면, 2행의 네번째 칸 (8)은 밟을 수 없습니다.

마지막 행까지 모두 내려왔을 때, 얻을 수 있는 점수의 최대값을 return하는 solution 함수를 완성해 주세요. 
위 예의 경우, 1행의 네번째 칸 (5), 2행의 세번째 칸 (7), 3행의 첫번째 칸 (4) 땅을 밟아 16점이 최고점이 되므로 16을 return 하면 됩니다.
*/

//c++ 정답코드
//DP 
#include<vector>
using namespace std;

int dp[100001][4] = {0};
int solution(vector<vector<int> > land)
{
    int r = land.size();
    for (int i = 0; i < 4; ++i)
    {
        dp[0][i] = land[0][i];
    }

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            for(int k = 0; k < 4; ++k)
            {
                if (j != k)
                {
                    dp[i][j] = max(dp[i][j], land[i][j] + dp[i-1][k]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 4; ++i)
    {
        ans = max(ans, dp[r-1][i]);
    }
    return ans;
}

//java로 푼 풀이
import java.lang.Math;
import java.util.*;
class Solution {
   
   int [][] dp = new int[100001][4];
   int solution(int[][] land) {
    
    int r = land.length;
    for (int i = 0; i < 4; i++)
    {
        dp[0][i] = land[0][i];
    }

    for (int i = 0; i <r; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                if (j != k)
                {
                    dp[i][j] = Math.max(dp[i][j], land[i][j] + dp[i-1][k]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        ans = Math.max(ans, dp[r-1][i]);
    }
    return ans;
   }
}
/*
같은 조건문인데 java.lang.ArrayIndexOutOfBoundsException: -1 에러가 난다. 
dp[i-1] 에서 i=0일때 -1값이 되어 오류가 나는 것 같은데 c++ 대신 java로 이 알고리즘을 푸는 방법이 뭘까?
*/
