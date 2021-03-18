#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

const int direction[4][2] = { {1,0},{-1,0},{0,1}, {0,-1} };
int answer = 0;

void DFS(deque<deque<char>> board, int K, pair<int,int> where, int depth){
    if(depth+1 == K){
        if(where.first == 0 && where.second == board[0].size()-1){
            answer++;
        }
        return ;
    }

    for(int i = 0; i<4; i++){
        int nextR = where.first + direction[i][0];
        int nextC = where.second + direction[i][1];

        if(nextR >= 0 && nextR < board.size() && nextC >=0 && nextC < board[0].size()){
            if(board[nextR][nextC] == '.'){
                board[nextR][nextC] = 'T';
                pair<int, int> nextWhere = make_pair(nextR,nextC);
                DFS(board, K, nextWhere, depth+1);
                board[nextR][nextC] = '.';
            }
        }
    }
}


int main(){
    int R, C, K;
    deque< deque<char>> board;
    string temp;

    cin >> R >> C >> K;

    for(int i = 0; i<R; i++){
        deque<char> tempDeque;
        cin >> temp;
        for(int j = 0; j<C; j++){
            tempDeque.push_back(temp[j]);
        }
        board.push_back(tempDeque);
    }

    pair<int,int> where = make_pair(R-1,0);
    board[R-1][0] = 'T';
    DFS(board,K,where,0);

    cout << answer << endl;

    return 0;
}