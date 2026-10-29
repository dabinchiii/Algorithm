import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int N = nums.length;
        HashSet<Integer> s = new HashSet<>();
        for(int num : nums) s.add(num);
        
        return Math.min(s.size(), N / 2);
    }
}