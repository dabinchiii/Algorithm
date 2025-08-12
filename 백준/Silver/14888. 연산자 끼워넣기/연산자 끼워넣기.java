import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static int n;
	static int[] arr;
	static int[] oper; // +, -, *, /
	static int ansMin, ansMax;
	
	public static void main(String[] args)  throws IOException{
		n = Integer.parseInt(br.readLine());
    	arr = new int[n];
    	oper = new int[4];
    	
    	st = new StringTokenizer(br.readLine());
    	for(int i=0; i<n; i++) {
    		arr[i] = Integer.parseInt(st.nextToken());
    	}
    	
    	st = new StringTokenizer(br.readLine());
    	for(int i=0; i<4; i++) {
    		oper[i] = Integer.parseInt(st.nextToken());
    	}
		
    	solve();
    	
    	System.out.println(ansMax + "\n" + ansMin);
	}
	
	static void solve() {
		ansMin = 1000000000;
		ansMax = -1000000000;
		
		
		dfs(1, arr[0]);
		
	}
	
	static void dfs(int cnt, int curr) {
		if(cnt == n) {
			ansMin = Math.min(ansMin, curr);
			ansMax = Math.max(ansMax, curr);
			return;
		}
		
		for(int i=0; i<4; i++) {
			if(oper[i] == 0) continue;
			
			oper[i]--;
			if(i == 0) { // +
				dfs(cnt + 1, curr + arr[cnt]);
			}
			else if(i == 1) { // -
				dfs(cnt + 1, curr - arr[cnt]);
			}
			else if(i == 2) { // *
				dfs(cnt + 1, curr * arr[cnt]);
			}
			else { // /
				dfs(cnt + 1, curr / arr[cnt]);
			}
			oper[i]++;
		}
	}
}
