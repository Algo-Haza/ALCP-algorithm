import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ_1774 {

  private static final String INPUT_DIR = "baekJoon/java/input.txt";
  private static final String OUTPUT_DIR = "baekJoon/java/output.txt";

  private static double total = 0;
  private static Vertex[] vertexes;
  private static int[] parents;
  private static PriorityQueue<Edge> edges = new PriorityQueue<>();
  private static int N;
  private static int M;
  private static int cnt = 0;

  public static void main(String[] args) throws Exception {
    input();

    createEdges();

    while (!edges.isEmpty()) {
      final Edge edge = edges.poll();
      if (findRoot(edge.v1Index) != findRoot(edge.v2Index)) {
        cnt++;
        unionGraph(edge.v1Index, edge.v2Index);
        total += edge.weight;
      }
    }

    final double round = Math.round((total * 100));
    System.out.printf("%.2f", round / 100.0);
  }

  private static void createEdges() {
    for (int i = 1; i < N; i++) {
      for (int j = i + 1; j <= N; j++) {
        final Edge edge = new Edge(i, j, calculateWeight(vertexes[i], vertexes[j]));
        edges.add(edge);
      }
    }
  }

  private static void input() throws Exception {
    //file io로 변경
    System.setIn(new FileInputStream(INPUT_DIR));
    System.setOut(new PrintStream(new FileOutputStream(OUTPUT_DIR)));

    final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    vertexes = new Vertex[N + 1];
    parents = new int[N + 1];

    for (int i = 1; i <= N; i++) {
      parents[i] = i;
    }

    for (int i = 1; i <= N; i++) {
      st = new StringTokenizer(br.readLine());
      int x = Integer.parseInt(st.nextToken());
      int y = Integer.parseInt(st.nextToken());
      vertexes[i] = new Vertex(x, y);
    }

    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());
      int v1 = Integer.parseInt(st.nextToken());
      int v2 = Integer.parseInt(st.nextToken());
      unionGraph(v1, v2);
    }
  }

  static double calculateWeight(final Vertex v1, final Vertex v2) {
    return Math.sqrt(Math.pow(v1.x - v2.x, 2) + Math.pow(v1.y - v2.y, 2));
  }

  static void unionGraph(final int vertex1Index, final int vertex2Index) {
    final int root1 = findRoot(vertex1Index);
    final int root2 = findRoot(vertex2Index);

    if (root1 > root2) {
      parents[vertex1Index] = root2;
    } else {
      parents[vertex2Index] = root1;
    }
  }

  static int findRoot(final int vertexIndex) {
    if (parents[vertexIndex] == vertexIndex) {
      return vertexIndex;
    } else {
      return findRoot(parents[vertexIndex]);
    }
  }

  static class Edge implements Comparable<Edge> {

    int v1Index;
    int v2Index;
    double weight;

    public Edge(final int v1Index, final int v2Index, final double weight) {
      this.v1Index = v1Index;
      this.v2Index = v2Index;
      this.weight = weight;
    }

    @Override
    public int compareTo(final Edge edge) {
      return Double.compare(this.weight, edge.weight);
    }
  }

  static class Vertex {

    int x;
    int y;

    public Vertex(final int x, final int y) {
      this.x = x;
      this.y = y;
    }
  }
}
