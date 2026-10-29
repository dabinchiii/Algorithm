import java.util.*;

class Solution {
    public int solution(int[][] jobs) {
        int N = jobs.length;
        
        // 요청시점 기준 오름차순 정렬
        Arrays.sort(jobs, (a, b) -> a[0] - b[0]); 
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if(a[1] != b[1]) return a[1] - b[1];
            return a[0] - b[0];
        });
        
        int t = 0, total = 0, idx = 0, done = 0;
        while(done < N){
            while(idx < N && jobs[idx][0] <= t){
                pq.add(jobs[idx++]);
            }
            
            if(pq.isEmpty()){
                t = jobs[idx][0];
                continue;
            }
            
            int[] curr = pq.poll();
            t += curr[1];
            total += t - curr[0]; // 반환 시간
            ++done;
        }
        
        return total / N;
    }
}