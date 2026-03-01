import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main{
	public static int N;
	public static int[][] gs;
	public static int dest, ig;
	public static int ans;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		gs = new int[N + 1][2];
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			gs[i][0] = Integer.parseInt(st.nextToken());
			gs[i][1] = Integer.parseInt(st.nextToken());
		}
		
		st = new StringTokenizer(br.readLine());
		dest = Integer.parseInt(st.nextToken());
		ig = Integer.parseInt(st.nextToken());
		
		Arrays.sort(gs, 0, N, (a, b) -> Integer.compare(a[0], b[0]));
		gs[N][0] = dest;
		
		PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> Integer.compare(b,  a));
		
		int limit = ig;
		boolean fail = false;
		ans = 0;
		for(int i=0; i<=N; i++) {
			while(gs[i][0] > limit) { // 못 감 
				if(pq.isEmpty()) { // 갈 수 있는 주유소도 없음 
					fail = true;
					break;
				}
				
				limit += pq.poll();
				++ans;
			}
			
			if(fail) break;
			
			pq.offer(gs[i][1]);
		}
		
		if(limit < dest) ans = -1;
		
		System.out.println(ans);
	}
}