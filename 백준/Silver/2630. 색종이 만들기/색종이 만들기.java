import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int[][] board;
	static int cnt0, cnt1;
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		board = new int[N][N];
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		cnt0 = cnt1 = 0;
		check(0, 0, N);
		
		System.out.println(cnt0 + "\n" + cnt1);
	}
	
	static void check(int sr, int sc, int len) {
		int cnt = 0;
		int rEnd = sr + len;
		int cEnd = sc + len;
		for(int r=sr; r<rEnd; r++) {
			for(int c=sc; c<cEnd; c++) {
				cnt += board[r][c];
			}
		}
		
		if(cnt == len * len) { // 전체가 손상 영역(1)이다.
			++cnt1;
		}
		else if(cnt == 0) { // 전체가 정상 영역(0)이다.
			++cnt0;
		}
		else { // 손상 영역과 정상 영역이 섞여있다.
			int newLen = len / 2;
			check(sr, sc, newLen);
			check(sr + newLen, sc, newLen);
			check(sr, sc + newLen, newLen);
			check(sr + newLen, sc + newLen, newLen);
		}
	}
}
