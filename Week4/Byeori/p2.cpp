#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> v;
int n, a, b;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push(make_pair(b, a));
    }

    int last = 0;
    int count = 0;
    while (!v.empty())
    {
        pair<int, int> now = v.top();
        v.pop();
        if (now.second >= last)
        {
            last = now.first;
            count++;
        }
    }
    cout << count;
    return 0;
}
