# Programmers 2021 Dev Matching

## 다단계 칫솔판매

- https://school.programmers.co.kr/learn/courses/30/lessons/77486
- **재귀**를 사용해서 풀면 쉬웠다!
- 추천 문제
    - Silver 2 색종이 만들기 https://www.acmicpc.net/problem/2630
    - Silver 1 Z https://www.acmicpc.net/problem/1074
    - Gold 5 Moo 게임 https://www.acmicpc.net/problem/5904

<br>

## 행렬 테두리 회전하기

- https://school.programmers.co.kr/learn/courses/30/lessons/77485
- N년도에 코딩테스트 문제에 자주 나왔던, 행렬 회전 문제이다. 정사각형, 직사각형, 시계 방향, 반시계 방향, 90도, 180도, 270도 등 다양한 변형이 존재한다.
- 행렬 자체를 회전하는 것이 아니라, **행렬은 그대로 두고 특정 컨베이어 벨트만 회전하는 것이 핵심이다.** 따라서 구현 문제를 풀듯이 한땀한땀 풀면 된다.

1. 행렬에 1부터 값 채우기
2. 시작 위치를 기준으로 시계 방향으로 오른쪽, 아래, 왼쪽, 위의 숫자들을 벡터에 담는다.
       
```cpp

        // 오른쪽
        for(int i = st_x; i <= en_x; i++) {
            tmp.push_back(arr[st_y][i]);
            mn = min(mn, arr[st_y][i]);
            xy.push_back({st_y, i}); // 시계 방향으로 한 칸 움직인 숫자들을 넣을 좌표를 저장
        }
        
        // 아래
        for(int i = st_y + 1; i <= en_y; i++){
            tmp.push_back(arr[i][en_x]);
            mn = min(mn, arr[i][en_x]);
            xy.push_back({i, en_x});
        }
        
        // 왼쪽
        for(int i = en_x-1; i >= st_x; i--){
            tmp.push_back(arr[en_y][i]);
            mn = min(mn, arr[en_y][i]);
            xy.push_back({en_y, i});
        }
        
        // 위
        for(int i = en_y-1; i >= st_y+1; i--){
            tmp.push_back(arr[i][st_x]);
            mn = min(mn, arr[i][st_x]);
            xy.push_back({i, st_x});
        }
```

3. algorithm 헤더의 rotate 함수를 이용해서 오른쪽으로 한 칸 이동한다.

```cpp
rotate(tmp.rbegin(), tmp.rbegin()+1, tmp.rend()); // 오른쪽으로 한 칸
rotate(tmp.begin(), tmp.begin()+1, tmp.end()); // 왼쪽으로 한 칸
```

<br>

## 로또의 최고 순위와 최저 순위

- https://school.programmers.co.kr/learn/courses/30/lessons/77484#
- 일치하는 개수를 세고 케이스에 맞게 등수를 계산하면 되는 쉬운 문제이다.
- 쉽지만 의외로 한 번에 맞기가 쉽지 않다. 어떤 예외 케이스를 고려하지 않아 삽질했는지 나눠보자!

```cpp
    /*
        [1, 2, 3, 4, 5, 6] [7, 8, 9, 10, 11, 12]
        0이 없으면서 일치하는 숫자가 없는 경우를 고려하지 않아서 테스트 케이스 14번만 틀렸다.
        가능한 경우의 수를 모두 체크하면서 테스트 케이스를 만들어보자!!!!!
    */
    if(m_lottos[0] == 0 && equi == 0) answer.push_back(6); 
    else answer.push_back(7 - equi - m_lottos[0]);
    
    if(equi == 0) answer.push_back(6); 
    else answer.push_back(7 - equi); 
```