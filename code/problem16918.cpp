#include <iostream>
#include <algorithm>
#include <deque>
#include <string>

using namespace std;

int R,C,N;
char board[201][201];
int expiredTime[201][201];

void setBomb(int time){
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            if(board[i][j] == '.'){
                board[i][j] = 'O';
                expiredTime[i][j] = time+3; 
            }
        }
    }
}

void boom(int time){
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C ; j++){
            if(expiredTime[i][j] == time){
                board[i][j] = '.';
                expiredTime[i][j] = 0;

                if(i+1 < R){
                    board[i+1][j] = '.';
                    expiredTime[i+1][j] = 0;
                }
                if(i-1 >= 0){
                    board[i-1][j] = '.';
                    expiredTime[i-1][j] = 0;
                }
                if(j-1 >= 0){
                    board[i][j-1] = '.';
                    expiredTime[i][j-1] = 0;
                }
                if(j+1 < C){
                    board[i][j+1] = '.';
                    expiredTime[i][j+1] = 0;
                }

            }
        }
    }
}

int main(){
    cin >> R >> C >> N;
    string temp;
    for(int i = 0; i<R; i++){
        cin >> temp;
        for(int j = 0; j<C; j++){
            board[i][j] = temp[j];
            expiredTime[i][j] = 3;
        }
    }

    for(int time = 1; time<=N; time++){
        boom(time);
        if(time%2 == 0){
            setBomb(time);
        }
        

    }

    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            cout << board[i][j];
        }
        cout << endl;
    }


    return 0;
}