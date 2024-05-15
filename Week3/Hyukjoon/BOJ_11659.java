package dp;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.StringTokenizer;

public class BOJ_11659 {

  private static final String INPUT_DIR = "baekJoon/java/input.txt";
  private static final String OUTPUT_DIR = "baekJoon/java/output.txt";

  private static BufferedReader br;
  private static int N;
  private static int M;
  private static long[] numbers;
  private static long[] sum;

  public static void main(String[] args) throws Exception {
    input();
    while (M-- > 0) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      int start = Integer.parseInt(st.nextToken());
      int end = Integer.parseInt(st.nextToken());
      System.out.println(sum[end] - sum[start - 1]);
    }
  }

  private static void input() throws IOException {
    //file io로 변경
    System.setIn(new FileInputStream(INPUT_DIR));
    System.setOut(new PrintStream(new FileOutputStream(OUTPUT_DIR)));

    br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    st = new StringTokenizer(br.readLine());
    numbers = new long[N + 1];
    sum = new long[N + 1];

    for (int i = 1; i <= N; i++) {
      numbers[i] = Long.parseLong(st.nextToken());
      sum[i] = sum[i - 1] + numbers[i];
    }
  }
}
