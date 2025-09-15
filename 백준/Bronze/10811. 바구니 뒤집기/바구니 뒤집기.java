import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int N, M;
	static int[] arr;
			
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		arr = new int[N + 1];
		for(int i=1; i<=N; i++) arr[i] = i;
		
		int a, b;
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			
			int len = (b - a) / 2;
			for(int j=0; j<=len; j++) {
				int tmp = arr[a + j];
				arr[a + j] = arr[b - j];
				arr[b - j] = tmp;
			}
			
		}
		
		StringBuilder sb = new StringBuilder();
		for(int i=1; i<=N; i++) sb.append(arr[i] + " ");
		System.out.println(sb.toString());
	}
}
