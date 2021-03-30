#include <iostream>
#include <algorithm>
#include <deque>
#include <string>

using namespace std;

int n,k;
deque<int> coin;
int dp[10001];

int main(){
    cin >> n >> k;
    int temp;

    for(int i = 0; i<10001; i++){
        dp[i] = 0;
    }

    for(int i = 0; i<n; i++){
        cin >> temp;
        coin.push_back(temp);
        dp[temp] = 1;
    }
    return 0;
}