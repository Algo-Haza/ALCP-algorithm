package tree;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.StringTokenizer;

public class BOJ_1197 {

  private static final String INPUT_DIR = "baekJoon/java/input.txt";
  private static final String OUTPUT_DIR = "baekJoon/java/output.txt";

  private static PriorityQueue<Edge> edges = new PriorityQueue<>();
  private static int[] parent;
  private static int V;
  private static int E;

  public static void main(String[] args) throws Exception {
    input();

    parent = new int[V + 1];
    for (int i = 1; i <= V; i++) {
      parent[i] = i;
    }

    final Set<Integer> selectedVertex = new HashSet<>();
    int total = 0;

    while (!edges.isEmpty()) {
      final Edge edge = edges.poll();
      if (findParent(edge.v1) == findParent(edge.v2)) {
        continue;
      }
      selectedVertex.add(edge.v1);
      selectedVertex.add(edge.v2);
      unionVertex(edge.v1, edge.v2);
      total += edge.weight;
    }
    System.out.println(total);
  }

  private static int findParent(final int vertex) {
    if (parent[vertex] == vertex) {
      return vertex;
    } else {
      return findParent(parent[vertex]);
    }
  }

  private static void unionVertex(final int v1, final int v2) {
    final int parent1 = findParent(v1);
    final int parent2 = findParent(v2);

    if (parent1 > parent2) {
      parent[parent1] = parent2;
    } else {
      parent[parent2] = parent1;
    }
  }

  private static void input() throws Exception {
    //file io로 변경
    System.setIn(new FileInputStream(INPUT_DIR));
    System.setOut(new PrintStream(new FileOutputStream(OUTPUT_DIR)));

    final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    V = Integer.parseInt(st.nextToken());
    E = Integer.parseInt(st.nextToken());

    for (int i = 0; i < E; i++) {
      st = new StringTokenizer(br.readLine());
      int v1 = Integer.parseInt(st.nextToken());
      int v2 = Integer.parseInt(st.nextToken());
      int weight = Integer.parseInt(st.nextToken());
      edges.add(new Edge(v1, v2, weight));
    }
  }

  static class Edge implements Comparable<Edge> {

    int v1;
    int v2;
    int weight;

    public Edge(final int v1, final int v2, final int weight) {
      this.v1 = v1;
      this.v2 = v2;
      this.weight = weight;
    }

    @Override
    public int compareTo(final Edge edge) {
      if (this.weight > edge.weight) {
        return 1;
      } else if (this.weight == edge.weight) {
        return 0;
      } else {
        return -1;
      }
    }
  }
}
