/*
    시뮬레이션
    배열 회전
*/
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

struct sticker{
    int r;
    int c;
    int area;
    deque<deque<int> > board;
};

int N,M,K;
deque<sticker> stickers;
int notebook[41][41];

bool checkAttach(int a, int b, deque<deque<int> > board){
    int r = board.size();
    int c = board[0].size();
    int flag = 0;
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c ;j++){
            if((board[i][j] + notebook[a+i][b+j]) == 2) return false;
        }
    }

    for(int i = a; i<a+r; i++){
        for(int j = b; j<b+c; j++){
            notebook[i][j] += board[i-a][j-b];
        }
    }

    return true;
}

deque<deque<int> > rotate(deque<deque<int> > board){
    deque<deque<int> > rotateBoard;
    
    for(int i = 0; i<board[0].size(); i++){
        deque<int> temp;
        for(int j = board.size()-1; j>=0; j--){
            temp.push_back(board[j][i]);
        }
        rotateBoard.push_back(temp);
    }

    return rotateBoard;
}

int attach(int idx){
    deque<deque<int> > nowBoard = stickers[idx].board;
    for(int r = 0; r<=3; r++){
        if(nowBoard[0].size() <= M && nowBoard.size() <= N){
            for(int i = 0 ; i<N-nowBoard.size()+1; i++){
                for(int j = 0; j<M-nowBoard[0].size()+1; j++){
                    if(checkAttach(i,j,nowBoard)){
                        return stickers[idx].area;
                    }
                }
            }
        }

        nowBoard = rotate(nowBoard);
    }
    
    return 0;
}

int main(){
    cin >> N >> M >> K;

    int r,c;
    int val;
    for(int i = 0; i<K; i++){
        cin >> r >> c;
        sticker s;
        s.r = r;
        s.c = c;
        int temparea = 0;
        for(int j = 0 ; j<r; j++){
            deque<int> temp;
            for(int k = 0; k<c; k++){
                cin >> val;
                temparea += val;
                temp.push_back(val);    
            }
            s.board.push_back(temp);
        }
        s.area = temparea;
        stickers.push_back(s);
    }
    
    int answer = 0;
    for(int i = 0; i<stickers.size(); i++){
        answer += attach(i);
    }
    cout << answer << endl;
    return 0;
} 