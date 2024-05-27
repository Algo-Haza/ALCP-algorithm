#include <iostream>

using namespace std;

int N;
int answer = 0;
int main() {
    // input
    cin >> N;

    while(N >= 0) {
        if(N % 5 == 0) {
            answer += N / 5;
            cout << answer;
            exit(0);
        }
        N -= 3; // 정확히 그 무게만큼
        answer++;       
    }
    cout << -1;
}