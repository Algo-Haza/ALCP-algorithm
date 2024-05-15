package dp;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.StringTokenizer;

public class BOJ_10986 {

  private static final String INPUT_DIR = "baekJoon/java/input.txt";
  private static final String OUTPUT_DIR = "baekJoon/java/output.txt";

  private static int N;
  private static int M;
  private static int[] arr;
  private static int[] sum;
  private static long[] remainder;

  public static void main(String[] args) throws Exception {
    input();

    long ans = 0;
    for (final long canCount : remainder) {
      if (canCount < 2) {
        continue;
      }
      ans += (canCount) * (canCount - 1) / 2;
    }
    System.out.println(ans + remainder[0]);
  }

  private static void input() throws Exception {
    //file io로 변경
    System.setIn(new FileInputStream(INPUT_DIR));
    System.setOut(new PrintStream(new FileOutputStream(OUTPUT_DIR)));

    final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    arr = new int[N];
    sum = new int[N];
    remainder = new long[M];

    st = new StringTokenizer(br.readLine());
    arr[0] = Integer.parseInt(st.nextToken()) % M;
    sum[0] = arr[0];
    remainder[sum[0]]++;

    for (int i = 1; i < N; i++) {
      arr[i] = Integer.parseInt(st.nextToken()) % M;
      sum[i] = (sum[i - 1] + arr[i]) % M;
      remainder[sum[i]]++;
    }
  }
}
