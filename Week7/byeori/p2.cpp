#include <string>
#include <vector>
#include <iostream>

using namespace std;
int arr[101][101];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            arr[i][j] = i * columns + j + 1;
        }
    }

    vector<int> answer;
            int minValue = 987654321;
int x, y;
    for(int i = 0; i < queries.size(); i++) {
        int x1 = queries[i][0] - 1;
        int y1 = queries[i][1] - 1;
        int x2 = queries[i][2] - 1;
        int y2 = queries[i][3] - 1;

        
        int now = arr[x1][y1];
        for(y = y1; y < y2; y++) {
            int next = arr[x1][y + 1];
            arr[x1][y + 1] = now;
            now = next;
            minValue = min(minValue, now);
        }
        
        for(x = x1; x < x2; x++) {
            int next = arr[x + 1][y2];
            arr[x + 1][y2] = now;
            now = next;
            minValue = min(minValue, now);

        }
        
        for(y = y2; y > y1; y--) {
            int next = arr[x2][y - 1];
            arr[x2][y - 1] = now;
            now = next;
            minValue = min(minValue, now);

        }
        
        for(x = x2; x > x1; x--) {
            int next = arr[x - 1][y1];
            arr[x - 1][y1] = now;
            now = next;
            minValue = min(minValue, now);

        }

        arr[x1][y1+1] = now;
        minValue = min(minValue, now);

        answer.push_back(minValue);
        minValue = 987654321;
    }
    return answer;
}

