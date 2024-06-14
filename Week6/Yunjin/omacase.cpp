#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int L, Q;

class Query {
    public :
        int cmd, t, x, n;
        string name;

        Query(int cmd, int t, int x, string name, int n) {
            this->cmd = cmd;
            this->t = t;
            this->x=x;
            this->name = name;
            this->n = n;
        }
};

vector<Query> queries; // command 저장
set<string> names; // 등장한 사람 목록
map<string, vector<Query>> p_queries; // 각 사람마다 주어진 초밥 명령만을 관리
map<string, int> entry_time; // 각 사람마다 입장 시간 관리
map<string, int> position; // 각 사람의 위치
map<string, int> exit_time; // 각 사람의 퇴장 시간

bool cmp(Query q1, Query q2) {
    if(q1.t != q2.t) return q1.t < q2.t;
    return q1.cmd < q2.cmd;
}

int main() {
    // input
    cin >> L >> Q;
    for(int i = 0; i < Q; i++) {
        int cmd = -1;
        int t = -1, x = -1, n = -1;
        string name;
        cin >> cmd;
        if(cmd == 100) cin >> t >> x >> name;
        else if(cmd == 200) cin >> t >> x >> name >> n;
        else cin >> t;

        queries.push_back(Query(cmd, t, x, name, n)); // 쿼리들 저장

        // 사람마다 주어진 초밥 명령 목록 관리
        if(cmd == 100) p_queries[name].push_back(Query(cmd, t, x, name, n));

        // 손님이 입장한 시간과 위치 관리
        else if(cmd == 200) {
            names.insert(name); // 손님 목록
            entry_time[name] = t; // 손님의 입장 시간
            position[name] = x; // 손님의 위치
        }
    }

    // 각 손님마다 자신의 이름이 적힌 초밥을 언제 먹는지 계산
    for(string name : names) {
        // 퇴장 시간 관리 : 마지막으로 먹는 초밥 시간 중 가장 늦은 시간
        exit_time[name] = 0;

        // 손님의 명령 목록
        for(Query q : p_queries[name]) {
            // 초밥이 손님 등장 전 주어진 상황
            int time_to_removed = 0;
            if(q.t < entry_time[name]) {
                // 손님의 입장 시간에 초밥의 위치 구하기
                int t_sushi_x = (q.x + (entry_time[name] - q.t)) % L;

                // 몇 초 지나야 초밥을 만나는지 계산
                int additional_t = (position[name] - t_sushi_x + L) % L;

                time_to_removed = entry_time[name] + additional_t;
            }

            // 초밥이 손님 등장 이후 주어진 상황
            else {
                int additional_t = (position[name] - q.x + L) % L;
                time_to_removed = q.t + additional_t;
            }

            // 초밥이 사라지는 시간 중 가장 늦은 시간 업데이트
            exit_time[name] = max(exit_time[name], time_to_removed);

            // 초밥이 사라지는 111번 쿼리 추가
            queries.push_back(Query(111, time_to_removed, -1, name, -1));

        }
    }

    // 손님이 마지막으로 초밥을 먹은 시간 t 계산
    // 손님이 t 시간에 오마카세를 떠난 222 Query 추가
    for(string name : names) {
        queries.push_back(Query(222, exit_time[name], -1, name, -1));
    }

    // 전체 쿼리를 시간 순으로 정렬
    // t가 동일하다면 300이 가장 뒤로 가도록 정렬
    sort(queries.begin(), queries.end(), cmp);

    int people_num = 0;
    int sushi_num = 0;
    for(int i = 0; i < queries.size(); i++) {
        if(queries[i].cmd == 100) // 초밥 추가
            sushi_num++;
        else if(queries[i].cmd == 111) // 초밥 제거
            sushi_num--;
        else if(queries[i].cmd == 200) // 사람 추가
            people_num++;
        else if(queries[i].cmd == 222) // 사람 제거
            people_num--;
        else // 사진 촬영
            cout << people_num << " " << sushi_num << "\n";
    }
    return 0;
}