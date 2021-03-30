#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

int N,M;
int board[9][9];
int safezone;
deque<pair<int,int> > virus;

int spread(){
    int result = 0;
    int tempboard[9][9];
    deque<pair<int,int> > q;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            tempboard[i][j] = board[i][j];
        }
    }

    for(int i = 0; i<virus.size(); i++){
        q.push_back(virus[i]);
    }

    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;

        if(a-1 >= 0 && tempboard[a-1][b] == 0){
            q.push_back(make_pair(a-1,b));
            tempboard[a-1][b] = 2;
        }
        if(a+1 < N && tempboard[a+1][b] == 0){
            q.push_back(make_pair(a+1,b));
            tempboard[a+1][b] = 2;
        }
        if(b-1 >= 0 && tempboard[a][b-1] == 0){
            q.push_back(make_pair(a,b-1));
            tempboard[a][b-1] = 2;
        }
        if(b+1 < M && tempboard[a][b+1] == 0){
            q.push_back(make_pair(a,b+1));
            tempboard[a][b+1] = 2;
        }

        q.pop_front();
    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){ 
            if(tempboard[i][j] == 0 ){
                result++;
            }
        }
    }
    return result;
}

void makeWall(int count, int where){
    if(count == 3){
        safezone = max(spread(),safezone);
        return;
    }

    int x;
    int y;

    while(where < N*M){
        x = where/M;
        y = where%M;
        if(board[x][y] == 0){
            board[x][y] = 1;
            makeWall(count+1, where+1);
            board[x][y] = 0;
        }
        where++;
    }



}

int main(){
    cin >> N >> M;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> board[i][j];
            if(board[i][j] == 2){
                virus.push_back(make_pair(i,j));
            }
        }
    }

    makeWall(0,0);

    cout << safezone;
    return 0;
}