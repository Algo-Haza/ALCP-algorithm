#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[101][101];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    // arr에 순서대로 값 넣기
    int num = 1;
    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= columns; j++) {
            arr[i][j] = num++;
         }
        
    }
    
    // 쿼리
    for(int i = 0; i < queries.size(); i++) {
        vector<int> tmp;
        vector<pair<int, int>> xy;
        
        int mn = 1e9;
        int st_y = queries[i][0];
        int st_x = queries[i][1];
        int en_y = queries[i][2];
        int en_x = queries[i][3];
        
        // 오른쪽
        for(int i = st_x; i <= en_x; i++) {
            tmp.push_back(arr[st_y][i]);
            mn = min(mn, arr[st_y][i]);
            xy.push_back({st_y, i});
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
        
        rotate(tmp.rbegin(), tmp.rbegin()+1, tmp.rend());
        
        for(int i = 0; i < xy.size(); i++){
            arr[xy[i].first][xy[i].second] = tmp[i];
        }
        
        answer.push_back(mn);
    }
    

    return answer;
}