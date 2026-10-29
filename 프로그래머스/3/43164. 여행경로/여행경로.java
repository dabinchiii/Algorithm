import java.util.*;

class Solution {
    int N; // 남은 항공권 수
    Map<String, TreeMap<String, Integer>> g; // g[출발][도착] = 남은 티켓 수
    String[] path;
    boolean findAns;
    
    public String[] solution(String[][] tickets) {
        N = tickets.length;
        g = new HashMap<>();
        path = new String[N + 1];
        
        for(String[] tck : tickets){
            String a = tck[0], b = tck[1];
            
            if(!g.containsKey(a)){
                g.put(a, new TreeMap<>());
            }
            
            TreeMap<String, Integer> tg = g.get(a);
            
            if(tg.containsKey(b)){
                tg.put(b, tg.get(b) + 1);
            }
            else{
                tg.put(b, 1);
            }
        }
        
        path[0] = "ICN";
        
        findAns = false;
        dfs(1);
        
        return path;
    }
    
    private void dfs(int cnt){
        if(cnt == N + 1){
            findAns = true;
            return;
        }
        
        String curr = path[cnt - 1];
        
        if(g.get(curr) == null) return;
        for(Map.Entry<String, Integer> nxt : g.get(curr).entrySet()){
            if(nxt.getValue() == 0) continue;
            
            path[cnt] = nxt.getKey();
            nxt.setValue(nxt.getValue() - 1);
            
            dfs(cnt + 1);
            if(findAns) return;
            
            nxt.setValue(nxt.getValue() + 1);
        }
        
        return;
    }
}