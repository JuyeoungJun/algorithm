#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int arr[10001];
    int dp[10001];
    for(int i = 0; i<n ; i++){
        scanf("%d",&arr[i]);
    }
    dp[0] = arr[0];
    dp[1] = arr[0]+arr[1];
    dp[2] = max(arr[0]+arr[1],arr[1]+arr[2]);
    dp[2] = max(dp[2],arr[0]+arr[2]);
    int temp;
    for(int i = 3 ; i< n ; i++){
        /*
        temp = dp[i-1];
        if(temp < dp[i-2]+arr[i]){
            temp = dp[i-2]+arr[i];
        }
        if(temp < dp[i-3]+arr[i]+arr[i-1]){
            temp = dp[i-3]+arr[i]+arr[i-1];
        }*/
        dp[i] = max(dp[i-1],dp[i-2]+arr[i]);
        dp[i] = max(dp[i],dp[i-3]+arr[i]+arr[i-1]);
    }
    printf("%d\n",dp[n-1]);
    return 0;
}