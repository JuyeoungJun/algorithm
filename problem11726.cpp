#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int square[10001];
int result;
/*
void makeSol(int k){
    if(k == 0){
        result ++;
        return;
    }
    if(k < 0){
        return;
    }
    for(int i = 1; i<3; i++){
        makeSol(k-i);      
    }
}
*/

int main(){
    int n;
    cin >> n;
    square[1] = 1;
    square[2] = 2;
    for(int i = 3; i<=n ; i++){
        result = 0;
        square[i] = square[i-1] + square[i-2];
        square[i] = square[i] % 10007;
    }
    result = square[n];
    cout << result << endl;
    return 0;
}