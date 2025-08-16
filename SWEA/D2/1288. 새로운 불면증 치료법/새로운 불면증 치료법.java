import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
 
public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    
    static int N;
    static int ans;
    
    public static void main(String[] args) throws IOException {
    	int T;
    	T = Integer.parseInt(br.readLine().trim());
    	for(int t=1; t<=T; t++) {
    		N = Integer.parseInt(br.readLine());
    		
    		solve();
    		
    		bw.write("#" + t + " " + ans + "\n");
    		
    	}
    	bw.flush();
    	bw.close();
    	
    	return;
	}
    
    static void solve() {
    	ans = 0;
    	
    	int curr = N;
    	boolean[] visited = new boolean[10];
    	int cnt = 0;
    	
    	while(true) {
    		int tmp = curr;
    		while(tmp > 0) {
    			if(!visited[tmp % 10]) {
    				visited[tmp % 10] = true;
    				cnt++;
    			}
    			tmp /= 10;
    		}
    		
    		if(cnt == 10) {
    			ans = curr;
    			break;
    		}
    		
    		curr += N;
    	}
    	return;
    }
}