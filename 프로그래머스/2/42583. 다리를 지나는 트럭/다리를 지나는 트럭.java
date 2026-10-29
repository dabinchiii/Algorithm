import java.util.*;
import java.io.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        ArrayDeque<int[]> q = new ArrayDeque<>();
        int sum = 0, t = -1;
        
        for(int w : truck_weights){
            ++t;
            
            while(!q.isEmpty() && q.peek()[0] + bridge_length <= t){
                sum -= q.poll()[1];
            }
            
            while(sum + w > weight){
                int[] curr = q.poll();
                sum -= curr[1];
                t = curr[0] + bridge_length;
            }
            
            q.offer(new int[]{t, w});
            sum += w;
        }
        
        return t + bridge_length + 1;
    }
}