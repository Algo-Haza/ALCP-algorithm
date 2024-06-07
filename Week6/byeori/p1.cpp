#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, int> name;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    for(int i=0;i<enroll.size();i++){
        name[enroll[i]]=i;
    }
    
    vector<int> answer(enroll.size(),0);

    for(int i=0;i<seller.size();i++){
        string now=seller[i];
        int money=amount[i]*100;
        while(now!="-"&&money>0){
            answer[name[now]]+=(money-(money/10));
            money/=10;
            now=referral[name[now]];
        }
    }
    return answer;
}
