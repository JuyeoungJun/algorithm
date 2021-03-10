#include <iostream>

using namespace std;

int T,H,W;
int board[11][26];
int answer = 0;
int check[11][26];
int solve(int depth){
    /*
    for(int i = 0; i<H; i++){
        for(int j = 0; j<W; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;*/
    
    for(int i = 0; i<H-1; i++){
        for(int j = 0; j<W-1; j++){
            //cout << i << " " << j << endl;
            if(check[i][j] > depth+1){
                continue;
            }
            if(board[i][j] != 0) continue;
            if(board[i][j+1] != 0 ) continue;
            if(board[i+1][j] != 0 ) continue;
            if(board[i+1][j+1] != 0) continue;
            
            board[i][j] = depth+1;
            board[i][j+1] = depth+1;
            board[i+1][j] = depth+1;
            board[i+1][j+1] = depth+1;
            check[i][j] = depth+1;
            solve(depth+1);
            board[i][j] = 0;
            board[i][j+1] = 0;
            board[i+1][j] = 0;
            board[i+1][j+1] = 0;
            
        }
    }
    answer = max(answer,depth);
    return 0;
}

int main(){

    cin >> T;
    //cout << "Sample Output" << endl;
    for(int i = 0; i<T; i++){
        cin >> H >> W;
        answer = 0;
        for(int j = 0; j<H; j++){
            for(int k = 0; k<W; k++){
                cin >> board[j][k];
                check[j][k] = 0;
            }
        }
        solve(0);
        cout << "#" << i+1 << " " << answer << endl;
    }
    return 0;
}