import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        HashMap<String, Integer> mp = new HashMap<>();
        
        for(String pt : participant){
            if(!mp.containsKey(pt)) mp.put(pt, 1);
            else mp.put(pt, mp.get(pt) + 1);
        }
        
        for(String cp : completion){
            mp.put(cp, mp.get(cp) - 1);
        }
        
        for(String name : mp.keySet()){
            if(mp.get(name) > 0) return name;
        }
        
        return "";
    }
}