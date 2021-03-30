#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int num[1000001];
    vector<int> prime;

    int temp,a,b;
    int flag = 0;
    while(1){
        scanf("%d",&n);
        temp = 0;
        flag = 0;
        a = 0;
        b = 0;
        if(n == 0) break;
        for(int i = 3; i<=n/2;i+=2){
            a = 0;
            b = 0;
            flag = 0;
            for(int j = 2; j<=sqrt(i); j++){
                if(i%j == 0){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) {
                flag = 0;
                continue;
            }
            temp = n - i;
            for(int j = 2 ; j<=sqrt(temp);j++){
                if(temp % j == 0){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                cout << n << " = " << i << " + " << temp << "\n";
                break;
            }
        }
    }
    

    return 0;
}