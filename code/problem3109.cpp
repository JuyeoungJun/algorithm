#include <iostream>
#include <algorithm>
#include <deque>
#include <string>

using namespace std;

int R, C;
char board[10001][501];
int answer = 0;
int flag = 0;
int dx[3] = { -1, 0, 1};
int dy[3] = { 1, 1, 1};
int visited[10001][501] = {0};

int makePipe(int x, int y){
    if(y == C-1){
        flag = 1;
        return 0;
    }

    if(x-1 >= 0 && board[x-1][y+1] == '.' && visited[x-1][y+1] == 0){
        board[x-1][y+1] = 'p';
        visited[x-1][y+1] = 1;
        makePipe(x-1,y+1);
        if(flag == 1) return 0;
        board[x-1][y+1] = '.';
    }
    if(board[x][y+1] == '.' && visited[x][y+1] == 0){
        board[x][y+1] = 'p';
        visited[x][y+1] = 1;
        makePipe(x,y+1);
        if(flag == 1) return 0;
        board[x][y+1] = '.';
    }
    if(x+1 < R && board[x+1][y+1] == '.' && visited[x+1][y+1] == 0){
        board[x+1][y+1] = 'p';
        visited[x+1][y+1] = 1;
        makePipe(x+1,y+1);
        if(flag == 1) return 0;
        board[x+1][y+1] = '.';
    }


    return 0;
}

int main(){
    cin >> R >> C;
    string temp;
    for(int r = 0; r<R; r++){
        cin >> temp;
        for(int c = 0; c<C; c++){
            board[r][c] = temp[c];
        }
    }

    for(int i = 0; i<R; i++){
        // cout << "========================" << endl;
        // cout << "where: " << i << endl;
        makePipe(i,0);
        if(flag == 1){
            answer++;
            flag = 0;
        }

        // for(int r = 0; r<R; r++){
        //     for(int c= 0; c<C; c++){
        //         cout << board[r][c] << " ";
        //     }
        //     cout << endl;
        // }

    }

    cout << answer << endl;
    return 0;
}