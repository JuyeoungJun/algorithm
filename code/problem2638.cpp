/*
    BFS
*/

#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

int board[101][101];
int direction[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int N, M;

int meltCheese(){
    queue<pair<int, int> > q;
    q.push(make_pair(0,0));
    int checker[101][101] = {0};
    checker[0][0] = -1;
    deque<pair<int,int> > saveCheese;

    while(!q.empty()){
        int nowa = q.front().first;
        int nowb = q.front().second;
        for(int i = 0; i<4; i++){
            int nexta = nowa+direction[i][0];
            int nextb = nowb+direction[i][1];

            if(nexta >= 0 && nexta <N && nextb >=0 && nextb <M){
                if(board[nexta][nextb] == 0 && checker[nexta][nextb] != -1){
                    checker[nexta][nextb] = -1;
                    q.push(make_pair(nexta,nextb));
                }
                else if(board[nexta][nextb] == 1){
                    checker[nexta][nextb]++;
                    if(checker[nexta][nextb] == 2){
                        saveCheese.push_back(make_pair(nexta,nextb));
                    }
                }

            }

        }
        q.pop();
    }

    if(saveCheese.size() == 0){
        return 0;
    }
    else{
        while(!saveCheese.empty()){
            int nowa = saveCheese.front().first;
            int nowb = saveCheese.front().second;
            
            board[nowa][nowb] = 0;

            saveCheese.pop_front();
        }

    }

    return 1;
}

int main(){

    cin >> N >> M;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> board[i][j];
        }
    }

    int time = 0;
    for(; ;time++){
        if(!meltCheese()) break;
    }

    cout << time << endl;
    return 0;
}