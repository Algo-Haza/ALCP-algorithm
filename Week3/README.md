# 누적합(PrefixSum)

## Summary

가장 간단하게 누적합은 주어진 배열이 있을 때, 그 배열의 구간의 값을 빠르게 계산하기 위해 나온 방법이다.

### Declare PrefixSum

***Input:*** arr[] = {10, 20, 10, 5, 15}  
***Output:*** prefixSum[] = {10, 30, 40, 45, 60}

prefixSum[0] = 10,  
prefixSum[1] = prefixSum[0] + arr[1] = 30,  
prefixSum[2] = prefixSum[1] + arr[2] = 40

이처럼 O(n)의 방법으로 초기화가 가능하다.

### 누적합을 사용해 두 Index(L,R) 사이의 합을 구하기

> [!abstract] 기본적인 형태
> 크기의 배열 arr[]가 주어지고, index L과 R이 주어졌을 때, 인덱스 L에서 R까지의 배열 요소의 합을 출력합니다.

해결 방법

- PrefixSum을 초기화한다.
- 모든 쿼리(index L~R 사이의 값을 구해라)에 대해 아래와 같이 수행한다.
    - L이 1보다 크다면
        - ans = prefixSum[R] - PrefixSum[L-1]
    - 작다면
        - ans = prefixSum[0]

### 접근 방법

보통 누적합 문제는 $L$~$R$ 까지 원소의 합을 $M$번 구해야 하는 문제로 나옴.

그냥 계산하는건 어렵지 않음. 특정 구간의 원소의 합을 여러 번 구해야할 때 누적합으로 접근해볼 수 있을 것 같다.

### 시간복잡도

상황을 다음과 같이 가정해보자
> [!abstract] 상황
> size는 $N$이고, $L$~$R$ 까지 원소의 합을 $M$번 구해야 한다.

만약 가장 단순하게 누적합을 접근한다면 $O(n^2m)$ 이지만,
prefixSum을 적용하면 $O(n+m)$ 번의 시간이 걸린다.(선형시간)

# 문제

## 구간합 구하기 4

구간 합 구하기 4 : https://www.acmicpc.net/problem/11659

가장 디폴트 누적합 문제 위에서 설명헀던 것처럼 preifxSum을 만들고 해당 문제를 풀면 됨

## 구간합 구하기 5

구간 합 구하기 5  :https://www.acmicpc.net/problem/11660

살짝 응용이 들어간 2차원 배열의 구간합 문제

푸는 방법은 크게 두가지

- 1차원 prefixSum 배열을 여러 개 만들어서 계산하기
- 2차원 prefixSum 배열을 만들기

### 2차원 배열

요 부분 좀 재밌어서 들고와봤다.
사실 1차원 여러 개로 풀다가 2차원 prefixSum 보고 좀 신기했습니다.

#### Approach

preifxSum 만드는 것 또한 일종의 DP의 Bottom-up 형식으로 구성되어 있다.

`prefixSum[i] = prefixSum[i-1] + arr[i]`

2차원에서 확장을 시도해보자.

`prefixSum[i][j]` 을 `(0,0)` 부터 `(i ,j)` 까지의 원소의 합이라 정의해볼 수 있다.
여기서 정의할 때 배열의 크기를 i, j라고 생각하는 것이 포인트다.
그냥 쭉 더 해버리면 안 됨

그런식으로 정의하면 아래와 같이 (x1,y1) ~ (x2, y2)까지의 누적합을 구할 수 있다.
![](https://i.imgur.com/ADEPVJc.png)
전체의 합에서 노랑 부분, 초록 부분을 빼고 겹친 부분은 더하면 빨간 영역을 구할 수 있다.

#### prefixSum 초기화

그러면 prefixSum을 어떻게 초기화하는지 보자

사실 누적합에서 가장 시간이 많이 들어가는 것은 prefixSum을 세팅하는 것이다.
계산은 O(1)밖에 안 걸리니까 여기서 점화식을 찾는게 포인트

![](https://i.imgur.com/GnwP7pO.png)
지금의 화면에서 prefixSum[3][3] 을 구해본다고 하자.
그런 경우 파란 부분과 초록 부분을 더하고, 겹치는 부분을 뺀뒤 4를 더하면 된다.

여기서 중요한건 이전 원소들 만으로 prefixSum을 구할 수 있다는 것이다.
하위 문제들로 구성하기에 선형적으로 배열의 크기만큼 반복하면 prefixSum을 위한 세팅이 끝난다.

> [!summary] prefixSum 점화식
> prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + arr[i]
> [j]

이러한 특징을 이용하면 입력을 받자마자 prefixSum을 초기화시킬 수 있다.

#### 결과 계산

![](https://i.imgur.com/ADEPVJc.png)
결과 계산은 아까 표를 들고 오겠다.
여기서 빨간영역 즉 (2,2) ~ (4,4) 가 되는 영역을 구하고 싶다면

ans = prefixSum[4][4] - prefixSum[3][4] - prefixSum[4][3] + prefixSum[3][3]

이런식으로 한 번에 계산할 수 있다.

일반화하면 아래와 같이 선언 가능
> [!summary] 계산하기
> ans = prefixSum[i][j] - prefixSum[i-1][j] - prefixSum[i][j-1] + prefixSum[i-1][j-1]

## 약수의 합

약수의 합 : https://www.acmicpc.net/problem/17425

요거는 사실 에라토스테네스의 체가 거의 메인이고 누적합 향 첨가? 정도 된 문제긴 합니다.
하지만 누적합으로 접근하고 어떤식으로 해야 prefixSum을 초기화할 수 있는지?
해보면 좋을 것 같아서 들고왔어요.

## 나머지 합

나머지 합 : https://www.acmicpc.net/problem/10986

나머지의 특성을 잘 활용해야 한다.

얘도 살짝 누적합의 응용
