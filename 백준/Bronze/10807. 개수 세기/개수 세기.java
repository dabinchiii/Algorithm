import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.Vector;

public class Main{
	static int n, v, ans;
//	static int[] arr;
	
	public static void main(String[] args) throws IOException{
		BufferedReader bs = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(bs.readLine());
		
//		arr = new int[n];
		
		StringTokenizer st = new StringTokenizer(bs.readLine());
		v = Integer.parseInt(bs.readLine());
		
		for(int i=0; i<n; i++) {
//			arr[i] = Integer.parseInt(st.nextToken());
			if(Integer.parseInt(st.nextToken()) == v) {
				ans++;
			}
		}
		
		System.out.println(ans);
		
	}
}