#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    int dp[100000][3];
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[2][0] = 1;
    dp[2][1] = 2;
    dp[2][2] = 2;
    dp[3][0] = 1;
    dp[3][1] = 2;
    dp[3][2] = 3;
    for(int i = 4; i<10001 ; i++){
        dp[i][0] = 1;
        dp[i][1] = dp[i-2][1]+1;
        dp[i][2] = dp[i-3][2]+dp[i][1];
    }
    int temp;
    int result;
    for(int i= 0; i<N; i++){
        cin >> temp;
        cout << dp[temp][2] << endl;
    }

    return 0;
}