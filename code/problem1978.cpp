#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int num[1001];
int result = 0;

int main(){
    int N,a;
    vector<int> value;
    num[1] = 0;
    for(int i = 2; i<1001 ; i++){
        num[i] = 1;
    }
    /*
    for(int i = 4 ; i<1001 ; i = i+2){
        num[i] = 0;
    }*/
    for(int i = 2; i<1001; i++){
        if(num[i] == 1){
            for(int j = i*i ; j<1001; j+=i){
                num[j] = 0;
            }
        }
    }
    cin >> N;
    //cout << N << endl;
    for(int i = 0; i<N; i++){
        cin >> a;
        if(num[a] == 1){
            result ++;
        }
    }
    cout << result << endl;
    return 0;
}