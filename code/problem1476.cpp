#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

int E,S,M;
int result = 1;

int main(){
    cin >> E >> S >> M;
    while(1){
        if(E == 1 && S == 1 && M == 1){
            break;
        }
        E--;
        S--;
        M--;
        if(E == 0){
            E = 15;
        }
        if(S == 0){
            S = 28;
        }
        if(M == 0){
            M = 19;
        }
        result ++;
    }
    cout << result;
    return 0;
}