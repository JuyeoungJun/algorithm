#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int board[21][21];
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int result = 0;

int max_board(){
    int s = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            s= max(s,board[i][j]);
        }
    }
    return s;
}

void mov_board(int direc){
    deque<int> tmp;
    if(direc == 0){
        for(int i = 0; i<N; i++){
            tmp.clear();
            for(int j = 0; j<N; j++){
                if(board[j][i] != 0){
                    tmp.push_back(board[j][i]);
                    board[j][i] = 0;
                }
            }
            int index = 0;
            while(!tmp.empty()){
                board[index][i] = tmp.front();
                if(tmp.size()==1){
                    break;
                }
                tmp.pop_front();
                if(board[index][i] == tmp.front()){
                    board[index][i] *= 2;
                    tmp.pop_front();
                }
                index+=1;
            }
        }
    }
    else if(direc == 1){
        for(int i = 0; i<N; i++){
            tmp.clear();
            for(int j = N-1; j>=0; j--){
                if(board[j][i] != 0){
                    tmp.push_back(board[j][i]);
                    board[j][i] = 0;
                }
            }
            int index = N-1;
            while(!tmp.empty()){
                board[index][i] = tmp.front();
                if(tmp.size()==1){
                    break;
                }
                tmp.pop_front();
                if(board[index][i] == tmp.front()){
                    board[index][i] *= 2;
                    tmp.pop_front();
                }
                index-=1;
            }
        }
    }
    else if(direc == 2){
        for(int i = 0; i<N; i++){
            tmp.clear();
            for(int j = N-1; j>=0; j--){
                if(board[i][j] != 0){
                    tmp.push_back(board[i][j]);
                    board[i][j] = 0;
                }
            }

            int index = N-1;
            while(!tmp.empty()){
                board[i][index] = tmp.front();
                if(tmp.size()==1){
                    break;
                }
                tmp.pop_front();
                if(board[i][index] == tmp.front()){
                    board[i][index] *= 2;
                    tmp.pop_front();
                }
                index-=1;
            }
        }
    }
    else{
        for(int i = 0; i<N; i++){
            tmp.clear();
            for(int j = 0; j<N; j++){
                if(board[i][j] != 0){
                    tmp.push_back(board[i][j]);
                    board[i][j] = 0;
                }
            }
            int index = 0;
            while(!tmp.empty()){
                board[i][index] = tmp.front();
                if(tmp.size()==1){
                    break;
                }
                tmp.pop_front();
                if(board[i][index] == tmp.front()){
                    board[i][index] *= 2;
                    tmp.pop_front();
                }
                index+=1;
            }
        }
    }
}

void make_comb(int depth){
    if(depth == 6){
        result = max(result,max_board());
        return ;
    }
    int temp_board[21][21];
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            temp_board[i][j] = board[i][j];
        }
    }
    for(int i = 0; i<4; i++){
        mov_board(i);
        make_comb(depth+1);
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                board[i][j] = temp_board[i][j];
            }
        }
    }

}

int main(){
    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> board[i][j];
        }
    }
    make_comb(1);
    cout << result << endl;
    return 0;
}