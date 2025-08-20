import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static int N, M;
	
	static int[] parent, rank;
	
	public static void main(String[] args) throws IOException {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			
			parent = new int[N + 1];
			rank = new int[N + 1];
			
			for(int i=1; i<=N; i++) parent[i] = i;
			
			int comm, a, b;
			for(int i=0; i<M; i++) {
				st = new StringTokenizer(br.readLine());
				comm = Integer.parseInt(st.nextToken());
				a = Integer.parseInt(st.nextToken());
				b = Integer.parseInt(st.nextToken());
				
				if(comm == 0) {
					makeUnion(a, b);
				}
				else {
					bw.write(isUnion(a, b) ? "YES\n" : "NO\n");
				}
				
			}
			
		
		bw.flush();
		bw.close();
	}
	
	static void makeUnion(int a, int b) {		
		int rootA = findRoot(a);
	    int rootB = findRoot(b);

	    if(rootA == rootB) return;

	    if(rank[rootA] < rank[rootB]) {
	    	parent[rootA] = rootB; // rootB가 새로운 루트
	    }
	    else if(rank[rootA] < rank[rootB]) {
	    	parent[rootB] = rootA; // rootA가 새로운 루트
	    }
	    else { // 같은 경우
	    	parent[rootB] = rootA; // rootA가 새로운 루트
	    	rank[rootA]++; // 랭크 증가
	    }
	    
	    return;
	}
	
	static int findRoot(int x) {
		if(parent[x] == x) return x;
	    parent[x] = findRoot(parent[x]);
	    return parent[x];
	}
	static boolean isUnion(int a, int b) {
		return findRoot(a) == findRoot(b);
	}
}