#include <iostream>
#include <queue>
#include <cstring>
#include <stdio.h>

using namespace std;

int n, m, i, j;
int num[100001];


int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);    

	cin >>n >> m;
	for (int ii = 1; ii <= n; ii++) {
		cin >> num[ii];
		num[ii] += num[ii-1];
	}



	for (int ii = 0; ii < m;ii++) {
		cin >> i >> j;
		cout << num[j] - num[i-1] << '\n';
	}

}
