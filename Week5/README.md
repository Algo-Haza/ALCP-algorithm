# 최소신장트리

### 1. MST (최소 신장 트리)란?

최소 신장 트리(Minimum Spanning Tree, MST)는 그래프 이론에서 주어진 연결 그래프의 모든 정점을 포함하면서, 간선들의 가중치 합이 최소가 되는 트리를 의미합니다. 간단히 말해, 네트워크의 모든 노드를 연결하되, 전체 연결 비용을 최소화하는 방법입니다.

최소 연결 = 간선의 수가 가장 적다.
n개의 정점을 가지는 그래프의 최소 간선의 수는 (n-1)개이고, (n-1)개의 간선으로 연결되어 있으면 필연적으로 트리 형태가 되고 이것이 바로 Spanning Tree가 된다.
즉, 그래프에서 일부 간선을 선택해서 만든 트리

<img width="721" alt="image" src="https://github.com/Algo-Haza/ALCP-algorithm/assets/81238093/d8831755-ed76-4120-a9ee-6cd1b68c5757">

DFS, BFS을 이용하여 그래프에서 신장 트리를 찾을 수 있다.
탐색 도중에 사용된 간선만 모으면 만들 수 있다.
하나의 그래프에는 많은 신장 트리가 존재할 수 있다.
Spanning Tree는 트리의 특수한 형태이므로 모든 정점들이 연결 되어 있어야 하고 사이클을 포함해서는 안된다.
따라서 Spanning Tree는 그래프에 있는 n개의 정점을 정확히 (n-1)개의 간선으로 연결

### 2. 크루스칼 알고리즘 (Kruskal’s Algorithm)

간선을 중심으로 최소 신장 트리를 구성하는 대표적인 알고리즘입니다. 모든 간선을 가중치 순서대로 정렬한 후, 사이클을 생성하지 않으면서 최소 가중치의 간선을 선택하는 방식입니다.

1. **모든 간선을 가중치의 오름차순으로 정렬합니다.**

<img width="645" alt="image" src="https://github.com/Algo-Haza/ALCP-algorithm/assets/81238093/bf5be82a-3a25-4ff8-bd0f-c3362001c790">

2. **가장 가중치가 낮은 간선부터 선택합니다.**

<img width="663" alt="image" src="https://github.com/Algo-Haza/ALCP-algorithm/assets/81238093/b506e848-e6cd-417a-ba9d-4d3c0d2c4824">

3. **b-d를 선택하면 a-b-d 사이클이 형성되므로 선택하지 않습니다.**

<img width="655" alt="image" src="https://github.com/Algo-Haza/ALCP-algorithm/assets/81238093/639e9640-2f7a-4549-ad93-1e5a9e765b5b">

4. **모든 정점이 연결될 때까지 반복합니다.**

<img width="641" alt="image" src="https://github.com/Algo-Haza/ALCP-algorithm/assets/81238093/d9182486-2add-4616-8d01-2d3446ed9550">

- 간선을 정렬하는 데 O(E log E)의 시간이 소요되므로, 간선이 많은 그래프에서 비효율적일 수 있습니다.

### 4. 프림 알고리즘 (Prim’s Algorithm)

한 정점에서 시작하여 연결된 정점들을 확장해 나가는 방식으로 최소 신장 트리를 구성합니다. 시작 정점에서부터 가장 낮은 가중치의 간선을 선택해 트리를 확장합니다.

1. **임의의 정점을 시작 정점으로 선택합니다.**

<img width="332" alt="image" src="https://github.com/Algo-Haza/ALCP-algorithm/assets/81238093/fab39bd7-83af-4b29-9a81-a53bb8d593ef">

2. **트리에 연결된 정점에서 최소 가중치의 간선을 선택하고, 선택된 간선으로 연결된 정점을 트리에 추가합니다.**

<img width="316" alt="image" src="https://github.com/Algo-Haza/ALCP-algorithm/assets/81238093/be1ca0a3-193d-42eb-b5d3-bc26da8144f3">

3. **모든 정점이 포함될 때까지 반복합니다.**

<img width="316" alt="image" src="https://github.com/Algo-Haza/ALCP-algorithm/assets/81238093/2d0697c3-3424-4ce7-b3e5-3492c10559de">

### 장점 및 단점

- 연결된 노드만을 고려하기 때문에, 간선이 많은 밀집 그래프에서 효율적입니다.
- 초기 정점 선택에 따라 시간복잡도가 달라질 수 있습니다.

### 5. 크루스칼 알고리즘 vs 프림 알고리즘

- **크루스칼 알고리즘:** 간선 중심, 간선이 적은 그래프에서 유리.
- **프림 알고리즘:** 정점 중심, 간선이 많은 그래프에서 유리.
