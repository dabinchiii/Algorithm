import java.util.*;

class Solution {
    private static int N, tg, ans;
    private static int[] nums;
    
    public int solution(int[] numbers, int target) {
        ans = 0;
        
        nums = numbers;
        tg = target;
        N = numbers.length;
        
        dfs(0, 0);
        
        return ans;
    }
    
    private static void dfs(int cnt, int res){
        if(cnt == N){
            if(res == tg) ++ans;
            return;
        }
        
        dfs(cnt + 1, res + nums[cnt]);
        dfs(cnt + 1, res - nums[cnt]);
        
        return;
    }
}