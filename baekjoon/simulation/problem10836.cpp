/*
    시뮬레이션
    시간초과 주의
*/
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int M, N;
int board[701][701];
int direction[2][2] = { {-1,0}, {0,1} };
int store[1400] = {0};

int increase(int siz){
    int dir = 0;
    pair<int,int> now = make_pair(M-1,0);
    pair<int,int> next;
    for(int i = 0; i<siz; i++){
        board[now.first][now.second] += store[i];
        next = make_pair(now.first+direction[dir][0], now.second+direction[dir][1]);
        if(next.first == 0 && next.second == 0){
            dir = 1;
        }
        now = make_pair(next.first,next.second);
    }
    return 0;
}

int main(){
    cin >> M >> N;

    for(int i = 0; i<M ; i++){
        board[i][0] = 1;
    }


    for(int i = 0; i<M ; i++){
        board[0][i] = 1;
    }
    //1 4 4
    //2 9 3
    int a,b,c;
    int tempb, tempc;

    for(int i = 0; i<N; i++){
        cin >> a >> b >> c;
        for(int j = a; j < a+b; j++){
            store[j]++;
        }

        for(int j = a+b; j < a+b+c; j++){
            store[j]+=2;
        }
    }

    increase(2*M-1);

    int checkdirection[3][2] = { {0,-1}, {-1,-1}, {-1,0} };

    for(int j = 0; j<M; j++){
        for(int k = 0; k<M; k++){
            if(k == 0) { 
                cout << board[j][k] << " ";
                continue;    
            }
            cout << board[0][k] << " ";
        }
        cout << endl;
    }

    return 0;
}