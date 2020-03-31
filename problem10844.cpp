#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    int stair[N][10];
    int end[10];
    stair[0][0] = 0;
    for(int i = 1; i<10 ; i++){
        stair[0][i] = 1;
    }
    for(int i = 1; i<N ; i++){
        for(int j = 0; j<10 ; j++){
            stair[i][j] = 0;
        }
        for(int j = 0; j<10;j++){
            if(j == 0){
                stair[i][0] += stair[i-1][1]%1000000000;
            }
            else if(j == 9){
                stair[i][9] += stair[i-1][8]%1000000000;
            }
            else{
                stair[i][j] += (stair[i-1][j-1] + stair[i-1][j+1])%1000000000;
            }
        }
    }
    /*
    for(int i = 0; i<10 ;i++){
        cout << stair[1][i] << " " ;
    }*/
    int result = 0;
    for(int i = 0; i<10; i++){
        result += stair[N-1][i];
        result %= 1000000000;
    }
    cout << result << endl;
    return 0;
}