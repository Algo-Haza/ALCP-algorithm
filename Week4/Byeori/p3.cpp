#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int n;
int a[51];
int s;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> s;
    for (int i = 0; i < n - 1 && s > 0; ++i) {
        int maxPos = i;
        for (int j = i + 1; j < n && j <= i + s; ++j) {
            if (a[j] > a[maxPos]) {
                maxPos = j;
            }
        }
        
        for (int j = maxPos; j > i; --j) {
            swap(a[j], a[j - 1]);
            --s;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << " ";
    }
    cout << a[n - 1];
    return 0;
}
