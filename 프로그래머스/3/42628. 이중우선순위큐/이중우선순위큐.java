import java.util.*;

class Solution {
    public int[] solution(String[] operations) {
        TreeMap<Integer, Integer> pq = new TreeMap<>();
        
        for(String op : operations){
            String tokens[] = op.split(" ");
            int num = Integer.parseInt(tokens[1]);
            
            if(tokens[0].equals("I")){ // 숫자 삽입
                if(!pq.containsKey(num)) pq.put(num, 1);
                else pq.put(num, pq.get(num) + 1);
            }
            else if(num == 1){ // 최댓값 삭제
                if(pq.isEmpty()) continue;
                int key = pq.lastKey();
                int cnt = pq.get(key);
                if(cnt == 1) pq.remove(key);
                else pq.put(num, cnt - 1);
            }
            else{ // 최솟값 삭제
                if(pq.isEmpty()) continue;
                
                int key = pq.firstKey();
                int cnt = pq.get(key);
                if(cnt == 1) pq.remove(key);
                else pq.put(key, cnt - 1);
            }
        }
        
        if(pq.isEmpty()) return new int[]{0, 0};
        
        return new int[]{pq.lastKey(), pq.firstKey()};
    }
}