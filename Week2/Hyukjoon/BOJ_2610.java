package graph;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

public class BOJ_2610 {

  private static final String INPUT_DIR = "baekJoon/java/input.txt";
  private static final String OUTPUT_DIR = "baekJoon/java/output.txt";
  public static final int NOT_CONNECTED = 10000;

  private static int N;
  private static int M;
  private static List<List<Integer>> graph = new ArrayList<>();
  private static List<Set<Integer>> forest = new ArrayList<>();
  private static List<Integer> leaders = new ArrayList<>();

  public static void main(String[] args) throws Exception {
    input();
    initForest();
    solution();

    System.out.println(forest.size());
    Collections.sort(leaders);
    leaders.forEach(System.out::println);
  }

  private static void solution() {
    for (final Set<Integer> tree : forest) {
      final List<Integer> treeList = new ArrayList<>(tree);
      final int vertexCount = treeList.size();
      final int[][][] DP = initDP(vertexCount, treeList);

      for (int k = 1; k < vertexCount; k++) {
        final Integer targetVertex = treeList.get(k);
        final List<Integer> linkedVertexes = graph.get(targetVertex);

        for (int i = 0; i < vertexCount; i++) {
          for (int j = 0; j < vertexCount; j++) {
            DP[k][i][k] = (linkedVertexes.contains(treeList.get(i))) ? 1 : DP[k - 1][i][k];
            DP[k][k][j] = (linkedVertexes.contains(treeList.get(j))) ? 1 : DP[k - 1][k][j];
            DP[k][i][j] = Math.min(DP[k - 1][i][j], DP[k][i][k] + DP[k][k][j]);
          }
        }
      }
      int leaderIndex = Integer.MAX_VALUE;
      int minCount = Integer.MAX_VALUE;
      for (int i = 0; i < vertexCount; i++) {
        int max = 0;
        for (int j = 0; j < vertexCount; j++) {
          if (i == j) {
            continue;
          }
          max =  Math.max(DP[vertexCount - 1][i][j], max);
        }
        if (max < minCount) {
          leaderIndex = i;
          minCount = max;
        }
      }
      leaders.add(treeList.get(leaderIndex));
    }
  }

  private static int[][][] initDP(final int vertexCount, final List<Integer> treeList) {
    final int[][][] DP = new int[vertexCount][vertexCount][vertexCount];

    for (final int[][] ints : DP) {
      for (final int[] anInt : ints) {
        Arrays.fill(anInt, NOT_CONNECTED);
      }
    }

    for (int i = 1; i < treeList.size(); i++) {
      final Integer vertex = treeList.get(i);
      if (graph.get(treeList.get(0)).contains(vertex)) {
        DP[0][0][i] = 1;
        DP[0][i][0] = 1;
      }
    }

    return DP;
  }

  private static void initForest() {
    final boolean[] visited = new boolean[N + 1];

    for (int i = 1; i <= N; i++) {
      if (visited[i]) {
        continue;
      }

      final Set<Integer> linkedVertexes = new HashSet<>();
      final Queue<Integer> queue = new LinkedList<>();
      queue.add(i);
      visited[i] = true;
      linkedVertexes.add(i);

      while (!queue.isEmpty()) {
        final Integer currentVertex = queue.poll();

        for (final Integer linkedVertex : graph.get(currentVertex)) {
          if (visited[linkedVertex]) {
            continue;
          }
          visited[linkedVertex] = true;
          linkedVertexes.add(linkedVertex);
          queue.add(linkedVertex);
        }
      }
      forest.add(linkedVertexes);
    }
  }

  private static void input() throws Exception {
    //file io로 변경
    System.setIn(new FileInputStream(INPUT_DIR));
    System.setOut(new PrintStream(new FileOutputStream(OUTPUT_DIR)));

    final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());

    for (int i = 0; i <= N; i++) {
      graph.add(new ArrayList<>());
    }

    st = new StringTokenizer(br.readLine());
    M = Integer.parseInt(st.nextToken());

    for (int index = 0; index < M; index++) {
      st = new StringTokenizer(br.readLine());
      final int index1 = Integer.parseInt(st.nextToken());
      final int index2 = Integer.parseInt(st.nextToken());
      graph.get(index1).add(index2);
      graph.get(index2).add(index1);
    }
  }
}
