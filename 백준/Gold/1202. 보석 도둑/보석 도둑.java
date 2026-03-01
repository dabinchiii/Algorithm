import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Gem implements Comparable<Gem>{
	int w, v;
	
	public Gem(int w, int v) {
		this.w = w;
		this.v = v;
	}

	@Override
	public int compareTo(Gem o) { // 보석 무게 기준 오름차
		return Integer.compare(this.w, o.w);
	}
}

public class Main{
	
	public static int N, K;
	public static Gem[] gem;
	public static int[] bag;
	public static long ans;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		gem = new Gem[N];
		bag = new int[K];
		
		int w, v;
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			
			w = Integer.parseInt(st.nextToken());
			v = Integer.parseInt(st.nextToken());
			
			gem[i] = new Gem(w, v);
		}
		
		for(int i=0; i<K; i++) {
			bag[i] = Integer.parseInt(br.readLine());
		}
		
		// ===== solve =====
		
		ans = 0;
		
		Arrays.sort(gem);
		Arrays.sort(bag);
		
		PriorityQueue<Integer> pq = new PriorityQueue<>(); // 최소 
		
		int idx = 0;
		for(int i=0; i<K; i++) {
			while(idx < N && gem[idx].w <= bag[i]) pq.offer(-gem[idx++].v);
			if(!pq.isEmpty()) ans -= pq.poll();
		}
		
		System.out.println(ans);
	}
}