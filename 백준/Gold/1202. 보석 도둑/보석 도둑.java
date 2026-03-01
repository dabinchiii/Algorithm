import java.util.Arrays;
import java.util.PriorityQueue;

public class Main{
	
	
	public static void main(String[] args) throws Exception {
		int N = read();
		int K = read();
		
		long[] gem = new long[N];
		int[] bag = new int[K];
		
		long w, v;
		for(int i=0; i<N; i++) {
			w = read();
			v = read();
			gem[i] = (w << 32) | v; // 상위 32비트: 무게, 하위 32비트: 가
		}
		
		for(int i=0; i<K; i++) {
			bag[i] = read();
		}
		
		// ===== solve =====
		
		long ans = 0;
		
		Arrays.sort(gem);
		Arrays.sort(bag);
		
		PriorityQueue<Integer> pq = new PriorityQueue<>(); // 최소 
		
		int idx = 0;
		for(int i=0; i<K; i++) {
			while(idx < N && (gem[idx] >> 32) <= bag[i]) pq.offer(-(int)gem[idx++]);
			if(!pq.isEmpty()) ans -= pq.poll();
		}
		
		System.out.println(ans);
	}
	
	static int read() throws Exception {
        int c;
        do {
            c = System.in.read();
        } while (c <= 32); // 공백, 엔터 무시
        int n = c & 15;
        while ((c = System.in.read()) > 32) {
            n = (n << 3) + (n << 1) + (c & 15); // n * 10 + (c - '0')
        }
        return n;
    }
}