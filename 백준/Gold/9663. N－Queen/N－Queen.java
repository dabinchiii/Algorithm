import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int n;
	static boolean[] cols, dia, undia;
	
	static int ans;
	
	public static void main(String[] args) throws FileNotFoundException, IOException {
		n = Integer.parseInt(br.readLine());
		cols = new boolean[n + 1];
		dia = new boolean[2 * n + 1];
		undia = new boolean[2 * n + 1];
		solve();
		System.out.println(ans);
	}
	
	static void solve() {
		dfs(1);
	}
	
	static void dfs(int row) {
		if(row == n + 1) {
			ans++;
			return;
		}
		
		for(int col = 1; col<= n; col++) {
			if(cols[col] || dia[row + col] || undia[row - col + n]) continue;
			
			cols[col] = true;
			dia[row + col] = true;
			undia[row - col + n] = true;
			
			dfs(row + 1);
			
			cols[col] = false;
			dia[row + col] = false;
			undia[row - col + n] = false;
		}
		
	}
	
}
