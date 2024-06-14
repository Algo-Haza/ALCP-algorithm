package implementation;

public class Programmers_77485 {

  public static void main(String[] args) {
    int[][] ints = new int[][]{{2, 2, 5, 4}, {3, 3, 6, 6}, {5, 1, 6, 3}};
    final int[] solution = solution(6, 6, ints);

    for (final int i : solution) {
      System.out.println(i);
    }
  }

  public static int[] solution(final int rows, final int columns, final int[][] queries) {
    final int[][] map = new int[rows + 1][columns + 1];
    final int[] ans = new int[queries.length];

    for (int i = 1; i <= rows; i++) {
      for (int j = 1; j <= columns; j++) {
        map[i][j] = ((i - 1) * columns) + j;
      }
    }

    for (int i = 0; i < queries.length; i++) {
      ans[i] = spinMap(map, queries[i]);
    }

    return ans;
  }

  public static int spinMap(final int[][] map, int[] query) {
    final int startRow = query[0];
    final int startCol = query[1];
    final int endRow = query[2];
    final int endCol = query[3];

    final int LD = map[endRow][startCol];
    final int RU = map[startRow][endCol];
    final int RD = map[endRow][endCol];
    int min = Math.min(LD, Math.min(RU, RD));

    //moveRight
    for (int i = endCol; i > startCol; i--) {
      map[startRow][i] = map[startRow][i - 1];
      min = Math.min(map[startRow][i], min);
    }

    //moveDown
    for (int i = endRow; i > startRow + 1; i--) {
      map[i][endCol] = map[i - 1][endCol];
      min = Math.min(map[i][endCol], min);
    }
    map[startRow + 1][endCol] = RU;

    //moveLeft
    for (int i = startCol; i < endCol; i++) {
      map[endRow][i] = map[endRow][i + 1];
      min = Math.min(map[endRow][i], min);
    }
    map[endRow][endCol - 1] = RD;

    //moveUp
    for (int i = startRow + 1; i < endRow; i++) {
      map[i - 1][startCol] = map[i][startCol];
      min = Math.min(map[i - 1][startCol], min);
    }
    map[endRow - 1][startCol] = LD;

    return min;
  }
}
