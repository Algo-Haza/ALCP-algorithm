#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int cnt=0;
int ran=0;
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    sort(lottos.begin(),lottos.end());    
    sort(win_nums.begin(),win_nums.end());
    
    int j=0;
    for(int i=0;i<lottos.size();i++){
        while(lottos[i]>win_nums[j]){
            j++;
        }
        if(lottos[i]==0) ran++;
        else if(lottos[i]==win_nums[j]) cnt++;
    }
    cout<<ran<<cnt;
    vector<int> answer;
    if(cnt+ran==0){
        answer.push_back(6);
    }else{
        answer.push_back(7-(cnt+ran));
    }
    if(cnt==0){
        answer.push_back(6);
    }else{
        answer.push_back(7-(cnt));
    }
    return answer;
}
