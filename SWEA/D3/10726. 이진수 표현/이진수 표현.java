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
    
    public static void main(String[] args) throws IOException {
    	int T;
    	T = Integer.parseInt(br.readLine().trim());
    	for(int t=1; t<=T; t++) {
    		st = new StringTokenizer(br.readLine());
    		N = Integer.parseInt(st.nextToken());
    		M = Integer.parseInt(st.nextToken());
    		
    		int x = (1 << N) - 1;
        	if((M & x) == x) bw.write("#" + t + " " + "ON" + "\n");
        	else bw.write("#" + t + " " + "OFF" + "\n");
    	}
    	bw.flush();
    	bw.close();
    	
    	return;
	}
    
}