import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        int ans = 0;
        
        for(int sc : scoville){
            pq.add((long)sc);
        }
        
        while(pq.size() > 1 && pq.peek() < K){
            long m1 = pq.poll();
            long m2 = pq.poll() << 1;
            pq.add(m1 + m2);
            
            ++ans;
        }
        
        if(pq.peek() < K) return -1;
        
        return ans;
    }
}