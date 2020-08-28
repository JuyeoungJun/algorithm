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
        //cout << num[N-1][i] << " ";
    }
    //cout << endl;
    cout <<result%10007 << endl;
    return 0;
}
/*
1 1 1 1 1 1 1 1 1 1
1 2 3 4 5 6 7 8 9 10
1 3 6 10 15 21 28 36 45 55
1 4 10 20 
*/