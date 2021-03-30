#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int num[1001][10];
int N;

int main(){
    cin >> N;
    for(int i = 0; i<10; i++){
        num[0][i] = 1;
    }

    for(int i = 1; i<N; i++){
        for(int j = 0; j<10; j++){
            for(int k = j ; k>=0; k--){
                num[i][j] += num[i-1][k]%10007;
            }
        }
    }
    int result = 0;
    for(int i = 0; i<10; i++){
        result += num[N-1][i]%10007;
    }
    cout <<result%10007 << endl;
    return 0;
}
