package dp;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.StringTokenizer;

public class BOJ_11660 {

  private static final String INPUT_DIR = "baekJoon/java/input.txt";
  private static final String OUTPUT_DIR = "baekJoon/java/output.txt";

  private static BufferedReader br;
  private static int N;
  private static int M;
  private static int[][] map;
  private static int[][] sum;

  public static void main(String[] args) throws Exception {
    input();
    while (M-- > 0) {
      final StringTokenizer st = new StringTokenizer(br.readLine());

      final int x1 = Integer.parseInt(st.nextToken());
      final int y1 = Integer.parseInt(st.nextToken());

      final int x2 = Integer.parseInt(st.nextToken());
      final int y2 = Integer.parseInt(st.nextToken());

      int ans = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
      System.out.println(ans);
    }
  }

  private static void input() throws Exception {
    //file io로 변경
    System.setIn(new FileInputStream(INPUT_DIR));
    System.setOut(new PrintStream(new FileOutputStream(OUTPUT_DIR)));

    br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    map = new int[N + 1][N + 1];
    sum = new int[N + 1][N + 1];

    for (int i = 1; i <= N; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 1; j <= N; j++) {
        map[i][j] = Integer.parseInt(st.nextToken());
        sum[i][j] = map[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
      }
    }
  }
}
