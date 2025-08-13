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
	
	static int L, C;
	static char[] a;
	static ArrayList<Character> arr;
	
	static char[] vowel = {'a', 'e', 'i', 'o', 'u'};
	
	public static void main(String[] args) throws FileNotFoundException, IOException {
		st = new StringTokenizer(br.readLine());
		L = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
	
		a = new char[C];
		arr = new ArrayList<>();
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<C; i++) {
			a[i] = st.nextToken().charAt(0);
		}
		
		solve();
	}
	
	static void solve() {
		Arrays.sort(a);
		combi(0, 0);
	}
	
	static void combi(int cnt, int start) {
		if(cnt == L) {
			int cntV = 0;
			for(char v : vowel) {
				if(arr.contains(v)) cntV++;
			}
			if(cntV < 1 || (L - cntV) < 2) return;
		
			String s = "";
			for(char x : arr) s += x;
			System.out.println(s);
			
			return;
		}
		
		for(int i=start; i<C; i++) {
			arr.add(a[i]);
			combi(cnt + 1, i + 1);
			arr.remove(arr.size() - 1);
		}
	}
	
}
