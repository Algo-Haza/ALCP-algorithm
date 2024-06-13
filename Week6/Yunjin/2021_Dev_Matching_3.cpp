#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<int, int> m_lottos; // 숫자, 개수

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    // 로또 맵
    for(int i = 0; i < lottos.size(); i++) {
        m_lottos[lottos[i]]++;
    }
    
    // win_num 돌면서 최저 순위 찾기
    int equi = 0;
    for(int i = 0; i < win_nums.size(); i++) {
        if(m_lottos[win_nums[i]]) {
            equi++;
            m_lottos[win_nums[i]]--;
        }
    }
    
    /*
        [1, 2, 3, 4, 5, 6] [7, 8, 9, 10, 11, 12]
        0이 없으면서 일치하는 숫자가 없는 경우를 고려하지 않아서 테스트 케이스 14번만 틀렸다.
        가능한 경우의 수를 모두 체크하면서 테스트 케이스를 만들어보자!!!!!
    */
    if(m_lottos[0] == 0 && equi == 0) answer.push_back(6); 
    else answer.push_back(7 - equi - m_lottos[0]);
    
    if(equi == 0) answer.push_back(6); 
    else answer.push_back(7 - equi); 
    
    return answer;
}