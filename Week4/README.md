# 개념

## 1. 그리디란

- 각 단계에서 최적이라고 생각되는 것을 선택해나가는 방식
- 항상 최적의 값을 보장하는 게 아니라, 최적의 값의 ‘근사한 값’을 목표로
- 어떤말인지 예시
    
    ex) 노드에서 가장 합이 높은 방법 선택하는 방법
    
    - 최적이 아닐 수도 있지만 근사한 값으로 그리디하게 선택
    - 이걸 ‘근시안적 방법론’이라고 함
        - 단기적인 목표를 중심으로 한 전략적인 접근 방법
    
    ![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/4711311f-47f1-4e6b-a920-de6077d9f159/942a07c8-1935-4170-a8b0-2f35048800e0/Untitled.png)
    

## 2. 두 가지 조건

### 1) 탐욕 선택 속성 (greedy choice property)

- 각 단계에서 ‘최선의 선택’을 했을 때, 전체 문제에 대한 최적해를 구할 수 있는 경우

### 2) 최적 부분 구조 (optimal substructure)

- 전체 문제의 최적해가 ‘부분 문제의 최적해로 구성’될 수 있는 경우
- 즉, 전체 문제를 작은 부분 문제로 나누어 각각의 부분 문제에서 최적의 해를 구한 후 조합할 수 있는 경우

## 3. 단계

### 1) 문제의 최적해 구조 결정

### 2) 문제 구조에 맞게 선택 절차 정의 - 선택 절차 (selection procedure)

- ‘현재 상태’에서 ‘최적인 선택’

### 3) 선택 절차에 따라 선택 수행

### 4) 선택된 해가 문제의 조건 만족하는지 검사 - 적절성 검사 (feasibility check)

- 선택한 항목이 문제의 조건을 만족시키는지 확인

### 5) 조건 만족하지 않으면 해당 해 제외

### 6) 모든 선택이 완료되면 해답 검사 - 해답 검사 (solution check)

- 모든 선택이 완료되면, ‘최종 선택’이 ‘문제 조건 만족’시키는지 확인
- 조건 만족시키면 해답으로 인정

### 7) 조건 만족하지 않으면 해답으로 인정되지 않음

## 4. 그리디 vs DP

| 분류 | 그리디 | DP |
| --- | --- | --- |
| 설명 | 각 단계에서 최적의 선택하는 방식으로 문제 해결 | 작은 문제의 해를 메모이제이션하여 중복 계산 피함 |
| 성립 조건 | 1. 탐욕 선택 속성 (Greedy Choice Property)
2. 최적 부분 구조 (Optimal Substructure) | 1. 중복 부분 문제 (overlapping subproblems)
2. 최적 부분 구조 (Optimal substructure) |
| 중복 부분 문제 | 중복 부분 문제 해결 X | 중복 부분 문제 해결 O |

## 5. 한계

- 모든 문제에서 최적해를 보장하지 않음.
- ex) 배낭 문제의 경우 → DP or backtracking 필요

# 문제

## 설탕 배달

- (dp & greedy)  두 가지 방법

### 설탕 배달: https://www.acmicpc.net/problem/2839

### 그리디

```cpp
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, cnt = 0;
	cin >> n;

	while (n >= 0) {
		if (n % 5 == 0) {
			cnt += n / 5;
			cout << cnt;
			return 0;
		}
		n -= 3;
		cnt++;
	}
	cout << -1;
}
```

## 회의실 배정(재작년 현대 모비스)

회의실 배정: https://www.acmicpc.net/problem/1931 

- 종료 시점에 대해서 정렬
    - 정렬 결과
        
        ![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/4711311f-47f1-4e6b-a920-de6077d9f159/3be2d3b5-c132-4a48-a1ac-7062a9e5e74f/Untitled.png)
        

- 일찍 끝나는 것부터 추가
- 그다음 시작할 수 있는 거 추가
- 코드
    
    ```cpp
    #include <iostream>
    #include <algorithm>
    #include <vector>
    using namespace std;
    vector<pair<int, int>> meeting;
    
    int main() {
    	ios::sync_with_stdio(false);
    	cin.tie(NULL);
    	cout.tie(NULL);
    
    	int n, start, finish, cnt = 1;
    	cin >> n;
    	for (int i = 0; i < n; i++) {
    		cin >> finish >> start;
    		meeting.push_back(make_pair(start, finish));
    	}
    	sort(meeting.begin(), meeting.end());
    
    	int end = meeting[0].first;
    	for (int i = 1; i < n; i++) {
    		if (end <= meeting[i].second) {
    			cnt++;
    			end = meeting[i].first;
    		}
    	}
    	cout << cnt;
    }
    ```
    

## 소트

소트: https://www.acmicpc.net/problem/1083

- max인 곳 찾기
- 가능한 만큼 앞으로 이동시키기
- 반복
- 코드
    
    ```cpp
    #include <iostream>
    using namespace std;
    int arr[51];
    
    int main() {
    	ios::sync_with_stdio(false);
    	cin.tie(NULL);
    	cout.tie(NULL);
    
    	int n, s, cnt, maxNum, maxIdx;
    	cin >> n;
    	for (int i = 0; i < n; i++) {
    		cin >> arr[i];
    	}
    	cin >> s;
    
    	for (int i = 0; i < n - 1 && s != 0; i++) {
    		cnt = 0;
    		maxNum = arr[i];
    		maxIdx = i;
    
    		//max인 곳 구하기
    		for (int j = i + 1; j < n && cnt < s; j++, cnt++) {
    			if (maxNum < arr[j]) {
    				maxNum = arr[j];
    				maxIdx = j;
    			}
    		}
    
    		//swap 과정
    		int k = maxIdx;
    		if (maxIdx > i) {
    			while (k != i) {
    				int temp = arr[k];
    				arr[k] = arr[k - 1];
    				arr[k - 1] = temp;
    				k--;
    			}
    		}
    		s -= (maxIdx - i);
    	}
    
    	for (int i = 0; i < n; i++) {
    		cout << arr[i] << " ";
    	}
    }
    ```
    

## 보석도둑

보석도둑: https://www.acmicpc.net/problem/1202

1. 용량이 작은 가방부터 채운다
    - 그리디하게
    - 용량이 작은 가방에 들어가지 못한 보석이 큰 가방에는 들어갈 수 있기 때문
2. 가방에 담을 수 있는 보석들을 걸러내기 위해 보석을 무게 순으로 정렬
    - 넣을 수 있는 것 중, 가격이 가장 높은 것을 담는다
    - 이때 우선순위 큐 이용
3. 반복
- 코드
    
    ```cpp
    #include <iostream>
    #include <algorithm>
    #include <queue>
    using namespace std;
    priority_queue<int, vector<int>, less<int>> max_pq;
    int n, k;
    int p;
    vector<pair<int, int>> gems;
    vector<int> backpacks;
    
    int fillBackpack(int index) {
    	while (p < n && gems[p].first <= backpacks[index]) {
    		max_pq.push(gems[p++].second);
    	}
    
    	if (max_pq.empty()) {
    		return 0;
    	}
    	else {
    		int ret = max_pq.top();
    		max_pq.pop();
    		return ret;
    	}
    }
    
    int main() {
    	ios::sync_with_stdio(false);
    	cin.tie(NULL);
    	cout.tie(NULL);
    
    	int w, v, c;
    
    	cin >> n >> k;
    
    	for (int i = 0; i < n; i++) {
    		cin >> w >> v;
    		gems.push_back({ w, v });
    	}
    
    	for (int i = 0; i < k; i++) {
    		cin >> c;
    		backpacks.push_back(c);
    	}
    
    	sort(gems.begin(), gems.end());
    	sort(backpacks.begin(), backpacks.end());
    
    	long long result = 0;
    
    	for (int i = 0; i < k; i++) {
    		result += (long long)fillBackpack(i);
    	}
    
    	cout << result;
    
    	return 0;
    }
    ```