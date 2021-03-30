#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int R,C,T;
deque<pair<int,int> > cleaner;
int board[51][51];

int spread(){
    int temp[51][51];
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            temp[i][j] = 0;
        }
    }

    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            int count = 0;
            if(board[i][j] != 0){
                //위
                if(i-1 >= 0 && board[i-1][j] != -1){
                    count++;
                    temp[i-1][j] += board[i][j]/5;
                }
                //오
                if(j+1 < C){
                    count++;
                    temp[i][j+1] += board[i][j]/5;
                }
                //아래
                if(i+1 < R && board[i+1][j] != -1){
                    count++;
                    temp[i+1][j] += board[i][j]/5;
                }
                //왼
                if(j-1 >= 0 && board[i][j-1] != -1){
                    count++;
                    temp[i][j-1] += board[i][j]/5;
                }
                board[i][j] -= (board[i][j]/5)*count;
            }
        }
    }

    for(int i = 0 ; i<R; i++){
        for(int j = 0; j<C; j++){
            board[i][j] += temp[i][j];
        }
    }
    return 0;
}


int boom(){
    int direction[2][4][2] = { {{0,1}, {-1,0}, {0,-1}, {1,0}}, {{0,1},{1,0},{0,-1},{-1,0}} };
    for(int i = 0; i<2; i++){
        int a = cleaner[i].first;
        int b = cleaner[i].second+1;
        int temp = board[a][b];
        board[a][b] = 0;
        int what = 0;
        while(1){
            if(a == cleaner[i].first && b == cleaner[i].second){
                board[a][b] = -1;
                break;
            }
            if(a+direction[i][what][0] >= R || a+direction[i][what][0] < 0){
                what++;
            }
            if(b+direction[i][what][1] >= C || b+direction[i][what][1] < 0){
                what++;
            }
            a += direction[i][what][0];
            b += direction[i][what][1];
            swap(temp,board[a][b]);
        }
    }
    return 0;
}

int main(){
    cin >> R >> C >> T;

    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            cin >> board[i][j];
            if(board[i][j] == -1){
                cleaner.push_back(make_pair(i,j));
            }
        }
    }

    for(int i = 0; i<T; i++){
        //cout << "=======================" << endl;
        spread();
        /*
        for(int j = 0; j<R; j++){
            for(int k = 0; k<C; k++){
                cout << board[j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;*/
        boom();
        /*
        for(int j = 0; j<R; j++){
            for(int k = 0; k<C; k++){
                cout << board[j][k] << " ";
            }
            cout << endl;
        }*/
    }
    int answer = 0;
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            answer += board[i][j];
        }
    }
    cout << answer+2 << endl;
    return 0;
}