import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;
 
public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    
    static int N, M;
    static String ans;
    
    public static void main(String[] args) throws IOException {
    	int T;
    	T = Integer.parseInt(br.readLine().trim());
    	for(int t=1; t<=T; t++) {
    		st = new StringTokenizer(br.readLine());
    		N = Integer.parseInt(st.nextToken());
    		M = Integer.parseInt(st.nextToken());
    		
    		solve();
    		
    		bw.write("#" + t + " " + ans + "\n");
    		
    	}
    	bw.flush();
    	bw.close();
    	
    	return;
	}
    
    static void solve() {
    	int curr = M;
    	for(int i=0; i<N; i++) {
    		if((curr & 1) != 1) {
    			ans = "OFF";
    			return;
    		}
    		curr >>= 1;
    	}
    	ans = "ON";
    	return;
    }
}