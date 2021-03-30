#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;
int N, M;
int r,c,d;
int board[51][51];
int direction[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

int direction_check(){
    int di = d;
    di -= 1;
    if(di == -1) di = 3;
    int go = -1;
    for(int i = 0; i<4; i++){
        if(((r+direction[di][0]) < 0) || ((r+direction[di][0]) >= N)){
            di--;
            if(di == -1) di = 3;
            continue;
        } 
        if(((c+direction[di][1]) <0) || ((c+direction[di][1]) >= M)){
            di--;
            if(di == -1) di = 3;
            continue;
        }

        if((board[r+direction[di][0]][c+direction[di][1]]) == 0){
            go = di;
            break;
        }
        else{
            di--;
            if(di == -1) di = 3;
        }

    }

    return go;
}

int move(){
    int result = 2;

    board[r][c] = 2;

    while(1){
        int check = direction_check();
        /*
        cout << r << " " << c << " " << d << endl;
        cout << check << endl;
        for(int i = 0 ; i<N; i++){
            for(int j = 0; j<M; j++){
                cout << board[i][j] << "  ";
            } 
            cout << endl;
        }*/

        if(check == -1){
            int d_temp = (d+2)%4;
            if ( ((r+direction[d_temp][0]) < 0) || ((r+direction[d_temp][0]) >= N) )
            {
                break;
            }
            else if(((c+direction[d_temp][1]) < 0) || ((c+direction[d_temp][1]) >= M)){
                break;
            }
            else if((board[r+direction[d_temp][0]][c+direction[d_temp][1]]) == 1){
                break;
            }
            if((board[r+direction[d_temp][0]][c+direction[d_temp][1]]) != 1){
                r += direction[d_temp][0];
                c += direction[d_temp][1];
                continue;
            }

        }
        d = check;
        r += direction[d][0];
        c += direction[d][1];
        board[r][c] = result;
        result++;
    }

    return result;

}

int main(){
    cin >> N >> M;
    cin >> r >> c >> d;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> board[i][j];
        }
    }

    int answer = move();
    cout << answer-1 << endl;


    return 0;
}