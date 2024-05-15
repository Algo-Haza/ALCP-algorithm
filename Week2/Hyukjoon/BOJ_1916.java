package graph;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ_1916 {

    private static final String INPUT_DIR = "baekJoon/java/input.txt";
    private static final String OUTPUT_DIR = "baekJoon/java/output.txt";
    private static final int CANT_MOVE = Integer.MAX_VALUE;
    private static final int NO_CONNECTED_INDEX = -1;

    private static int N;
    private static int M;
    private static LinkedList<LinkedList<Edge>> MAP;
    private static int DIST[];
    private static boolean CHECK[];
    private static int SRC;
    private static int DEST;

    public static void main(String[] args) throws IOException {
        input();

        dijkstra(SRC);

        System.out.println(DIST[DEST]);
    }

    private static void dijkstra(final int src) {
        final PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(src, 0));

        DIST[src] = 0;

        while (!pq.isEmpty()) {
            final Edge srcEdge = pq.poll();
            int dest = srcEdge.nextCity;

            if (!CHECK[dest]) {
                CHECK[dest] = true;

                for (final Edge edge : MAP.get(dest)) {
                    if (!CHECK[edge.nextCity] && DIST[edge.nextCity] > DIST[dest] + edge.weight) {
                        DIST[edge.nextCity] = DIST[dest] + edge.weight;
                        pq.add(new Edge(edge.nextCity, DIST[edge.nextCity]));
                    }
                }
            }
        }
    }

    private static void input() throws IOException {
        //file io로 변경
        System.setIn(new FileInputStream(INPUT_DIR));
        System.setOut(new PrintStream(new FileOutputStream(OUTPUT_DIR)));

        final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());

        initMap();

        for (int index = 0; index < M; index++) {
            st = new StringTokenizer(br.readLine());
            int src = Integer.parseInt(st.nextToken());
            int dest = Integer.parseInt(st.nextToken());
            int time = Integer.parseInt(st.nextToken());

            MAP.get(src).push(new Edge(dest, time));
        }

        st = new StringTokenizer(br.readLine());
        SRC = Integer.parseInt(st.nextToken());
        DEST = Integer.parseInt(st.nextToken());
    }

    private static void initMap() {
        MAP = new LinkedList<>();
        DIST = new int[N + 1];
        CHECK = new boolean[N + 1];

        Arrays.fill(DIST, CANT_MOVE);

        for (int i = 0; i <= N; i++) {
            MAP.push(new LinkedList<>());
        }
    }

    static class Edge implements Comparable<Edge> {
        final int nextCity;
        final int weight;

        public Edge(final int nextCity, final int weight) {
            this.nextCity = nextCity;
            this.weight = weight;
        }

        @Override
        public int compareTo(final Edge o) {
            return weight - o.weight;
        }
    }
}
