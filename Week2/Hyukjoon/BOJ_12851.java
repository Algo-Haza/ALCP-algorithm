package graph;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_12851 {

  private static final String INPUT_DIR = "baekJoon/java/input.txt";
  private static final String OUTPUT_DIR = "baekJoon/java/output.txt";

  private static int N;
  private static int K;
  private static boolean[] check = new boolean[100001];

  public static void main(final String[] args) throws Exception {
    input();
    solution();
  }

  private static void solution() {
    Queue<Integer> queue = new LinkedList<>();

    queue.add(N);
    boolean notFindFlag = true;
    int count = 0;
    int cnt = 0;
    while (!queue.isEmpty() && notFindFlag) {
      final int currentMoveCount = queue.size();

      for (int i = 0; i < currentMoveCount; i++) {
        final Integer currentNode = queue.poll();
        if (currentNode == K) {
          notFindFlag = false;
          count++;
        }
        if (currentNode - 1 >= 0 && !check[currentNode - 1]) {
          queue.add(currentNode - 1);
        }
        if (currentNode + 1 <= 100000 && !check[currentNode + 1]) {
          queue.add(currentNode + 1);
        }
        if (currentNode * 2 <= 100000 && !check[currentNode * 2]) {
          queue.add(currentNode * 2);
        }
        check[currentNode] = true;
      }
      cnt += 1;
    }

    System.out.println(cnt - 1);
    System.out.println(count);
  }

  private static void input() throws IOException {
    //file io로 변경
    System.setIn(new FileInputStream(INPUT_DIR));
    System.setOut(new PrintStream(new FileOutputStream(OUTPUT_DIR)));

    final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    K = Integer.parseInt(st.nextToken());
  }
}
