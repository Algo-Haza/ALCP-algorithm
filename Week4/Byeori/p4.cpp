#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
pair<int, int> jewel[300001];
int knapsack[300001];
priority_queue<int> pq;
long long result = 0;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> jewel[i].first >> jewel[i].second;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> knapsack[i];
    }

    sort(jewel, jewel + n); 
    sort(knapsack, knapsack + k);  

    int idx = 0;
    for (int i = 0; i < k; i++)
    {
        while (idx < n && knapsack[i] >= jewel[idx].first)
        {
            pq.push(jewel[idx].second);
            idx++;
        }
        if (!pq.empty())
        {
            result += pq.top();
            pq.pop();
        }
    }
    cout << result;
    return 0;
}
