#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> money; // 수익
map<string, string> parent; // 자기, 부모

void divide(string person, int cost) {
    if(person == "-") return;
    int forParent = cost * 0.1;
    
    money[person] += cost - forParent;    
    if(forParent) divide(parent[person], forParent);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    for(int i = 0; i < enroll.size(); i++) {
        if(referral[i] == "-") {
            parent[enroll[i]] = "center";
        }
        else {
            parent[enroll[i]] = referral[i];
        }
        money[enroll[i]] = 0;       
    }
    
    for(int i = 0; i < seller.size(); i++) {
        divide(seller[i], amount[i] * 100);
    }
    
    for(int i = 0; i < enroll.size(); i++) {
        answer.push_back(money[enroll[i]]);
    }
    
    return answer;
}