/*
    시뮬레이션
    마지막에 한번에 board에 표기하는 것 주의
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <set>

using namespace std;

int N,M;
char board[101][101];
int direction[9][2] = { {1,-1}, {1,0}, {1,1}, {0,-1}, {0,0}, {0,1}, {-1,-1}, {-1,0}, {-1,1} };

struct enemy{
    int r;
    int c;
    bool alive;
    int index;
};
int flag = 0;
deque<enemy> e;

int myr;
int myc;

void move(){
    int nextboard[101][101] = {0};
    for(int i = 0; i<e.size(); i++){
        if(!e[i].alive) continue;
        board[e[i].r][e[i].c] = '.';
        int fin_nextr;
        int fin_nextc;
        int min_distance = 987654321;
        for(int j = 0; j<9; j++){
            int nextr = e[i].r + direction[j][0];
            int nextc = e[i].c + direction[j][1];

            if(nextr >= 0 && nextr <N && nextc >=0 && nextc < M){
                if(abs(myr-nextr) + abs(myc-nextc) < min_distance){
                    fin_nextr = nextr;
                    fin_nextc = nextc;
                    min_distance = abs(myr-nextr) + abs(myc-nextc);
                }
            }
        }
        if(board[fin_nextr][fin_nextc] == 'I'){
            flag = 1;
            return ;
        }
        if(nextboard[fin_nextr][fin_nextc] != 0){
            e[i].alive = false;
            if(nextboard[fin_nextr][fin_nextc] != -1){
                e[nextboard[fin_nextr][fin_nextc]-1].alive = false;
                nextboard[fin_nextr][fin_nextc] = -1;
            }
        }
        else{
            nextboard[fin_nextr][fin_nextc] = i+1;
            e[i].r = fin_nextr;
            e[i].c = fin_nextc;
        }
    }
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(nextboard[i][j] >= 1) board[i][j] = 'R';
        }
    }
}

int main(){
    cin >> N >> M;
    int cnt = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> board[i][j];
            if(board[i][j] == 'R'){
                enemy temp;
                temp.r = i;
                temp.c = j;
                temp.alive =true;
                temp.index = cnt;
                e.push_back(temp);
                cnt++;
            }
            else if(board[i][j] == 'I'){
                myr = i;
                myc = j;
            }
        }
    }    

    string input;
    cin >> input;

    for(int i = 0; i<input.size(); i++){
        int what;
        what = input[i]-'0'-1;
        board[myr][myc] = '.';
        myr += direction[what][0];
        myc += direction[what][1];

        if(board[myr][myc] == 'R') {
            cout << "kraj " <<i+1 << endl;
            flag = 1;
            break;
        }

        board[myr][myc] = 'I';

        move();

       if(flag == 1){
           cout << "kraj " << i+1 << endl;
           break;
       } 
    }
    if(flag == 0){
        for(int j = 0; j<N; j++){
            for(int k = 0; k<M; k++){
                cout << board[j][k];
            }
            cout << endl;
        }
    }
    return 0;
}