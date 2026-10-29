import java.util.*;

class Solution {
    public int[] solution(int[] prices) {
        int N = prices.length;
        ArrayDeque<int[]> st = new ArrayDeque<>();
        
        int[] ans = new int[N];
        
        for(int i=0; i<N; i++){
            while(!st.isEmpty() && st.getFirst()[0] > prices[i]){
                int idx = st.pop()[1];
                ans[idx] = i - idx;
            }
            
            st.push(new int[]{prices[i], i});
        }
        
        while(!st.isEmpty()){
            int idx = st.pop()[1];
            ans[idx] = N - 1 - idx;
        }
        
        return ans;
    }
}