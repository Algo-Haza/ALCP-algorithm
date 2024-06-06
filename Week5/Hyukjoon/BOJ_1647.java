package tree;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ_1647 {

  private static final String INPUT_DIR = "baekJoon/java/input.txt";
  private static final String OUTPUT_DIR = "baekJoon/java/output.txt";

  private static PriorityQueue<Edge> edges = new PriorityQueue<>();
  private static int[] roots;
  private static int rootCount;
  private static int N;
  private static int M;

  public static void main(String[] args) throws Exception {
    input();

    roots = new int[N + 1];
    rootCount = N;
    for (int i = 1; i <= N; i++) {
      roots[i] = i;
    }

    int totalWeight = 0;
    while (rootCount > 2) {
      final Edge edge = edges.poll();
      if (findRoot(edge.v1) == findRoot(edge.v2)) {
        continue;
      }
      totalWeight += edge.cost;
      unionGraph(edge.v1, edge.v2);
    }

    System.out.println(totalWeight);
  }

  private static void input() throws Exception {
    //file io로 변경
    System.setIn(new FileInputStream(INPUT_DIR));
    System.setOut(new PrintStream(new FileOutputStream(OUTPUT_DIR)));

    final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());
      int v1 = Integer.parseInt(st.nextToken());
      int v2 = Integer.parseInt(st.nextToken());
      int weight = Integer.parseInt(st.nextToken());
      edges.add(new Edge(v1, v2, weight));
    }
  }

  static void unionGraph(final int v1, final int v2) {
    final int root1 = findRoot(v1);
    final int root2 = findRoot(v2);
    if (root1 > root2) {
      roots[root2] = root1;
    } else {
      roots[root1] = root2;
    }
    rootCount -= 1;
  }

  static int findRoot(final int vertex) {
    if (roots[vertex] == vertex) {
      return vertex;
    } else {
      return findRoot(roots[vertex]);
    }
  }

  static class Edge implements Comparable<Edge> {

    int v1;
    int v2;
    int cost;

    public Edge(final int v1, final int v2, final int cost) {
      this.v1 = v1;
      this.v2 = v2;
      this.cost = cost;
    }

    @Override
    public int compareTo(final Edge edge) {
      return this.cost - edge.cost;
    }
  }
}
