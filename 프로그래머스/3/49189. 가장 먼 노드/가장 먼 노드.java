import java.util.*;

class Solution {
    public int solution(int n, int[][] edge) {
        List<Integer>[] g = new ArrayList[n + 1];
        for(int i=1; i<=n; i++) g[i] = new ArrayList<>();
        
        for(int[] e : edge){
            g[e[0]].add(e[1]);
            g[e[1]].add(e[0]);
        }
        
        ArrayDeque<int[]> q = new ArrayDeque<>();
        boolean visited[] = new boolean[n + 1];
        int maxDist = -1, ans = 0;
        
        q.offer(new int[]{1, 0});
        visited[1] = true;
        
        while(!q.isEmpty()){
            int[] curr = q.poll();
            
            for(int nxt : g[curr[0]]){
                if(visited[nxt]) continue;
                
                int dist = curr[1] + 1;
                visited[nxt] = true;
                q.offer(new int[]{nxt, dist});
                
                if(dist > maxDist){
                    maxDist = dist;
                    ans = 0;
                }
                if(dist == maxDist) ++ans;
            }
        }
        
        
        return ans;
    }
}