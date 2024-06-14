package implementation;

import java.util.HashMap;
import java.util.Map;

public class Programmers_77486 {

  public static void main(String[] args) {
    final int[] solution = solution(
        new String[]{"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"},
        new String[]{"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"},
        new String[]{"young", "john", "tod", "emily", "mary"},
        new int[]{12, 4, 2, 5, 10}
    );
    for (final int i : solution) {
      System.out.println(i);
    }
  }

  public static int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
    final Map<String, Integer> nameIndexMap = new HashMap<>();
    final Map<String, String> parentMap = new HashMap<>();
    final int[] answer = new int[enroll.length];
    for (int i = 0; i < enroll.length; i++) {
      nameIndexMap.put(enroll[i], i);
      parentMap.put(enroll[i], referral[i]);
    }

    for(int i=0; i<seller.length; i++){

      String now = seller[i];
      int profit = 100 * amount[i];

      while(!now.equals("-")){
        int profitForParent = profit / 10; // 부모에게 넘겨줄 금액
        int nowProfit = profit - profitForParent; // 자신이 가져갈 금액

        // 자신의 index에 금액만큼 더함
        answer[nameIndexMap.get(now)] += nowProfit;

        // 노드는 부모로 이동하면서 수익을 부모에게 넘겨준 금액으로 초기화
        now = parentMap.get(now);
        profit /= 10;

        // 10%의 금액이 1원 미만인 경우
        if (profit < 1) {
          break;
        }
      }
    }
    return answer;
  }
}
