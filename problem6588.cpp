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
    /*
    for(int i = 0; i<1000001;i++){
        num[i] = 1;
    }
    
    num[0] = 0;
    num[1] = 0;*/
    /*
    for(int i = 2; i<=1000;i++){
        if(num[i] = 1){
            for(int j = i*i ; j<1000000; j= j+i){
                num[j] = 0;
            }
        }
    }

    for(int i = 2 ; i < 1000001; i++){
        if(num[i] == 1){
            prime.push_back(i);
        }
    }
    //cout << num[6] << endl;*/

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
            //cout << i << endl;
            if(flag == 1) {
                flag = 0;
                continue;
            }
            temp = n - i;
            //cout << temp << endl;
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