package dp;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.StringTokenizer;

public class BOJ_17425 {

  private static final String INPUT_DIR = "baekJoon/java/input.txt";
  private static final String OUTPUT_DIR = "baekJoon/java/output.txt";
  private static final int MAX_NUM = 1000001;
  private static final long[] PREFIX_SUM = new long[MAX_NUM];

  private static BufferedReader br;

  private static int T;

  public static void main(String[] args) throws Exception {
    input();
    final StringBuilder sb = new StringBuilder();

    for (int i = 1; i < MAX_NUM; i++) {
      int n = 1;
      PREFIX_SUM[i] += PREFIX_SUM[i - 1];
      while (i * n < MAX_NUM) {
        PREFIX_SUM[i * n++] += i;
      }
    }

    while (T-- > 0) {
      final String input = new StringTokenizer(br.readLine()).nextToken();
      final int number = Integer.parseInt(input);
      sb.append(PREFIX_SUM[number]).append("\n");
    }

    System.out.println(sb);
  }

  private static void input() throws Exception {
    //file io로 변경
    System.setIn(new FileInputStream(INPUT_DIR));
    System.setOut(new PrintStream(new FileOutputStream(OUTPUT_DIR)));

    br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    T = Integer.parseInt(st.nextToken());
  }
}
