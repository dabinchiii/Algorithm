import java.util.*;

class Solution {
    int N;
    boolean visited[];
    int[][] g;
    
    public int solution(int n, int[][] computers) {
        N = n;
        visited = new boolean[n];
        g = computers;
        
        int ans = 0;
        for(int i=0; i<N; i++){
            if(visited[i]) continue;
            
            bfs(i);
            ++ans;
        }
        
        return ans;
    }
    
    private void bfs(int start){
        ArrayDeque<Integer> q = new ArrayDeque<>();
        
        q.push(start);
        visited[start] = true;
        
        while(!q.isEmpty()){
            int curr = q.poll();
            
            for(int nxt=0; nxt<N; nxt++){
                if(curr == nxt || g[curr][nxt] == 0) continue;
                if(visited[nxt]) continue;
                
                q.push(nxt);
                visited[nxt] = true;
            }
        }
        
        return;
    }
}