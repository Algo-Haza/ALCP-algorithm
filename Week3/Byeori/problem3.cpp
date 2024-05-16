#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

long long era[1000001]={0};
long long sum[1000001]={0};
int t, n;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        era[0]=0;
    cin>>t;
    for(int i=1;i<=1000000;i++){
        for(int j=1;i * j <= 1000000;j++){
            era[i*j]+=i;
        }
    }
    for(int i=1;i<=1000000;i++){
        sum[i]+=sum[i-1]+era[i];
    }
    while(t-->0){
        int a;
        cin>>a;
        cout<<sum[a]<<'\n';
    }
}
