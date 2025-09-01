import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int N, M;
	static int[] parent, rank;
	static int ans;
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		parent = new int[N];
		rank = new int[N];
		
		makeSet();
		
		ans = 0;
		
		int a, b;
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			
			boolean res = makeUnion(a, b);
			
			if(!res) {
				ans = i + 1;
				break;
			}
		}
		
		System.out.println(ans);
		
		return;
	}
	
	static void makeSet() {
		for(int i=0; i<N; i++) {
			parent[i] = i;
			rank[i] = 1;
		}
		return;
	}
	
	static int findRoot(int x) {
		if(parent[x] == x) return parent[x]; // 자신이 루트
		return parent[x] = findRoot(parent[x]); // 경로 압축
	}
	
	static boolean makeUnion(int a, int b) {
		int rootA = findRoot(a);
		int rootB = findRoot(b);
		
		if(rootA == rootB) return false; // 이미 같은 집합이라서 합치기 실패 (사이클)
		
		if(rank[rootA] > rank[rootB]) { // A가 더 크다 => A에 합침
			parent[rootB] = rootA;
			rank[rootA] += rank[rootB];
		}
		else { // B가 더 크다 => B에 합침
			parent[rootA] = rootB;
			rank[rootB] += rank[rootA];
		}
		
		return true;
	}
}
