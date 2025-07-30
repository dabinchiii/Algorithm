import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);
	static int n, m, r;
	static int arr[][];
	
	// 0상 1하 2좌 3우
	static int dr[] = {-1, 1, 0, 0};
	static int dc[] = {0, 0, -1, 1};
	
	static int cw[] = {3, 2, 0, 1}; // 시계방향
	static int ccw[] = {2, 3, 1, 0}; // 반시계방향
	
	public static void main(String[] args) throws FileNotFoundException {
//		System.setIn(new FileInputStream("Test4.txt"));
		
		n = sc.nextInt();
		m = sc.nextInt();
		r = sc.nextInt();
		
		arr = new int[n][m];
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				arr[i][j] = sc.nextInt();
			}
		}
		
		for(int l=0; l<(n < m ? n : m) / 2; l++) {
			int w = m - 2 * l;
			int h = n - 2 * l;
			int cnt = r % (2 * (w + h) - 4);
			for(int j=0; j<cnt; j++) {
				rotate(l);
			}
		}
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
	}

	private static void rotate(int l) {
		int tmp = arr[l][l]; // 왼쪽꼭지점 값 백업
		
		for(int i=l; i<m - 1 - l; i++) { // 위쪽 모서리
			arr[l][i] = arr[l][i + 1];
		}
		for(int i=l; i<n - 1 - l; i++) { // 오른쪽 모서리
			arr[i][m - 1 - l] = arr[i + 1][m - 1 - l];
		}
		for(int i=m-1 - l; i>l; i--) { // 아래쪽 모서리
			arr[n - 1 - l][i] = arr[n - 1 - l][i - 1];
		}
		for(int i=n - 1 - l; i>l; i--) { // 왼쪽 모서리
			arr[i][l] = arr[i - 1][l];
		}
		
		arr[l + 1][l] = tmp;
	}

}
