#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N; // 격자 크기
int M; // 게임 턴 수
int P; // 산타
int C; // 루돌프의 힘
int D; // 산타의 힘
int rr, rc; // 루돌프의 위치

int r_dx[8] = {0, 1, 1, 1, 0, -1, -1,-1};
int r_dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

// 좌하우상
// int s_dx[4] = {0, 1, 0, -1};
// int s_dy[4] = {-1, 0, 1, 0};

int s_dx[4] = {-1, 0, 1, 0};
int s_dy[4] = {0, 1, 0, -1};

int r_dir_r;
int r_dir_c;

int s_dir_r;
int s_dir_c;

int turn;

class location {
    public : 
        int row, col, score;
        int crush = 0;
        bool isDead = false;

        location(int row, int col, int score, int crush, bool isDead){
            this->row = row;
            this->col = col;
            this->score = score;
            this->crush = crush;
            this->isDead = isDead;
        }
};

vector<location> santa; // 산타 P명의 위치, 기절여부, 탈락여부, 점수
int board[51][51]; // 산타 이름 기억
vector<int> dist; // 루돌프와 산타의 거리

void dead_check(int s) {
    if(santa[s].row <= 0 || santa[s].row > N
    || santa[s].col <= 0 || santa[s].col > N) {
        santa[s].isDead = true;
    }
}

int cal_dist() {
    int min_dist = 5000;
    int min_santa = -1;
    for(int i = 1; i < santa.size(); i++) {
        if(santa[i].isDead) continue;
        dist[i] = pow(santa[i].row - rr, 2) + pow(santa[i].col - rc, 2);
        if(dist[i] < min_dist) {
            min_dist = dist[i];
            min_santa = i;
        }
        else if(dist[i] == min_dist) {
            if(santa[min_santa].row < santa[i].row) {
                cout << "\t\tfirst case\n";
                cout << "\t\t" << min_santa << " " << i << "\n";
                min_santa = i;
            }
            else if(santa[min_santa].row == santa[i].row) {
                cout << "\t\tsecond case\n";
                if(santa[min_santa].col < santa[i].col) {
                    min_santa = i;
                }
            }
        }
    }
    return min_santa;
}

void dolf_move(int s) {
    int santa_row = santa[s].row;
    int santa_col = santa[s].col;

    int min_dist = 5000;
    int closest_row = -1;
    int closest_col = -1;

    for(int d = 0; d < 8; d++) {
        int next_rr = rr + r_dx[d];
        int next_rc = rc + r_dy[d];
        int dist = pow(next_rr - santa_row, 2) + pow(next_rc - santa_col, 2);

        if(dist < min_dist) {
            min_dist = dist;
            closest_row = next_rr;
            closest_col = next_rc;
            r_dir_r = r_dx[d];
            r_dir_c = r_dy[d];
        }
    }

    board[rr][rc] = 0;
    rr = closest_row;
    rc = closest_col;
    // board[rr][rc] = -1;

}

void dolf_confused_check(int s) {
    int santa_row = santa[s].row;
    int santa_col = santa[s].col;

    if((santa_row == rr) && (santa_col == rc)) {
        // 기절, score + C, dir로 C칸 밀려나기
        santa[s].score += C;
        santa[s].crush = turn; // t 턴에서 기절, t+2 턴에서 정상

        board[santa_row][santa_col] = -1;
        santa[s].row += C * r_dir_r;
        santa[s].col += C * r_dir_c;

        // 상호작용 여부
        if(board[santa[s].row][santa[s].col] != 0) { // 이동 위치에 산타 존재 - 상호작용
            // 1칸 해당 방향으로 밀림
            santa[board[santa[s].row][santa[s].col]].row += r_dir_r;
            santa[board[santa[s].row][santa[s].col]].col += r_dir_c;

            // 밀린 산타 탈락 여부
            dead_check(board[santa[s].row][santa[s].col]);

        }

        // 탈락 여부
        dead_check(s);

    }
}

void santa_move(int s) { // santa s의 이동
    if(turn == 5) {
        cout << "\t santa_move " << santa[s].crush << "\n";
    }

    // 기절하거나 탈락
    if(santa[s].crush < turn + 2 && santa[s].crush > 0) return;
    if(santa[s].isDead) return;

    // 기절 초기화
    santa[s].crush = 0;
    //cout << "\t santa_move " << s << "\n";

    // 루돌프와 현재 거리
    int cur_dist = dist[s];

    int santa_row = santa[s].row;
    int santa_col = santa[s].col;

    int new_santa_row = -1;
    int new_santa_col = -1;
    int std_dist = 5000;
    for(int d = 0; d < 4; d++) {
        int next_santa_row = santa_row + s_dx[d];
        int next_santa_col = santa_col + s_dy[d];

        if(turn == 2 && s == 5) {
            cout << "here " << board[next_santa_row][next_santa_col] << "\n";
        }

        // 움직일 수 없는 경우
        if(next_santa_row <= 0 || next_santa_row > N
        || next_santa_col <= 0 || next_santa_col > N
        || board[next_santa_row][next_santa_col] != 0) continue;

        // 움직일 수 있는데 가까워지지 않는 경우
        int now_dist = pow(santa_row - rr, 2) + pow(santa_col - rc, 2);
        int new_dist = pow(next_santa_row - rr, 2) + pow(next_santa_col - rc, 2);
        if(s == 1) {
            cout << "now " << now_dist << "new " << new_dist << "\n";
        }
        
        if(now_dist < new_dist) continue;
        if(std_dist > new_dist) std_dist = new_dist;
        else continue;

        // 움직일 수 있고 가까워지는 경우
        new_santa_row = next_santa_row;
        new_santa_col = next_santa_col;
        s_dir_r = s_dx[d];
        s_dir_c = s_dy[d];

    }

    // -1이면 반환
    if(new_santa_row == -1) return;
    else { // 이동
        board[santa[s].row][santa[s].col] = 0;
        santa[s].row = new_santa_row;
        santa[s].col = new_santa_col;
        
        // 산타가 움직여서 루돌프와 충돌이 난 경우
        if(santa[s].row == rr && santa[s].col == rc) {
           // 기절, score + D, dir로 D칸 밀려나기
            santa[s].score += D;
            santa[s].crush = turn; // t 턴에서 기절, t+2 턴에서 정상

            board[santa_row][santa_col] = -1;
            santa[s].row -= D * s_dir_r;
            santa[s].col -= D * s_dir_c;

            // 상호작용 여부
            if(board[santa[s].row][santa[s].col] != 0) { // 이동 위치에 산타 존재 - 상호작용
                // 1칸 해당 방향으로 밀림
                santa[board[santa[s].row][santa[s].col]].row -= s_dir_r;
                santa[board[santa[s].row][santa[s].col]].col -= s_dir_c;

                // 밀린 산타 탈락 여부
                dead_check(board[santa[s].row][santa[s].col]);

            }

            // 탈락 여부
            dead_check(s);

        }
        board[santa[s].row][santa[s].col] = s;
        if(turn == 2 && s == 4) { cout << "sssss " << board[santa[s].row][santa[s].col]; }
    }

}

int main() {

    // input
    cin >> N >> M >> P >> C >> D;
    cin >> rr >> rc;
    board[rr][rc] = -1;

    santa.resize(P + 1, location(0, 0, 0, 0, false));
    dist.resize(P + 1);
    //santa.push_back(location(0, 0, 0, 0, false));

    for(int i = 1; i <= P; i++) {
        int num, row, col;
        cin >> num >> row >> col;
        //santa.push_back(location(row, col, 0, 0, false));
        santa[num].row = row;
        santa[num].col = col;
        board[row][col] = num;
    }

    // game turn
    for(int t = 0; t < M; t++) {
        // 루돌프와 가장 가까운 산타 번호
        turn = t;
        int min_santa = cal_dist();
        cout << min_santa << " min\n";

        // 루돌프 이동
        dolf_move(min_santa); // 8방향 중에서 가장 가까워지는 위치로 이동

        // min_santa와 dolf 충돌 판단
        dolf_confused_check(min_santa);

        // 산타 1번부터 순서대로 루돌프에 가까워지는 위치로 이동
        for(int i = 1; i <= P; i++) {
            if(santa[i].crush + 2 == turn) {
                santa[i].crush = 0;
            }
            santa_move(i);
        }

        // point
        for(int i = 1; i < santa.size(); i++) {
            if(!santa[i].isDead) santa[i].score++;
        }

        // final score
        for(int i = 1; i < santa.size(); i++) {
            cout << santa[i].score << " ";
        }
        cout << "\n";
        cout << rr << " " << rc << "\n";
        for(int i = 1; i < santa.size(); i++) {
            cout << "\t" << santa[i].row << " " << santa[i].col << "\n";
        }
    }

    // // final score
    // for(int i = 1; i < santa.size(); i++) {
    //     cout << santa[i].score << " ";
    // }


    
   
    return 0;
}