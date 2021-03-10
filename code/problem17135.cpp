#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

deque<int> comb;
int board[16][16];
int N,M,D;
int answer = 0;
int coun = 0;


pair<int,int> find_enemy(deque<deque<int> > boar,int a, int b){
    pair<int,int> result;
    result = make_pair(-1,-1);
    int visited[16][16] = {0};
    deque<pair<int,int> > q;
    q.push_back(make_pair(N,b));
    /*
    for(int i = 0; i<boar.size(); i++){
        for(int j = 0; j<boar[i].size(); j++){
            cout << boar[i][j] << " ";
        }
        cout << endl;
    }*/
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        //cout << x << " " << y << endl;
        if((x!= N) && boar[x][y] == 1){
            result.first = x;
            result.second = y;
            break;
        }
        if(((y-1) >= 0)){
            if(x != N){
                //cout << "1!" << endl;
                //cout <<abs(a-x)+abs(b-y+1) << endl;
                if(((abs(a-x)+abs(b-y+1)) <= D) && (visited[x][y-1] == 0)){
                    //cout << "2!" << endl;
                    q.push_back(make_pair(x,y-1));
                    visited[x][y-1] = 1;
                }
            }
        }
        if(x-1 >= 0){
            if(((abs(a-x+1) + abs(b-y))<=D ) && (visited[x-1][y] == 0)){
                q.push_back(make_pair(x-1,y));
                visited[x-1][y] = 1;
            }
        }
        if(y+1 < M){
            if( x!= N){
                if(((abs(a-x) + abs(b-y-1)) <= D) && (visited[x][y+1] == 0)){
                    q.push_back(make_pair(x,y+1));
                    visited[x][y+1] = 1;
                }
            }
        }
        q.pop_front();
    }
    //cout << result.first << " " << result.second << endl;
    return result;
}
int get_score(deque<int> archer){
    //cout << "=======================" << endl;
    int result = 0;
    deque<deque<int> > t_board;
    for(int i = 0; i<N; i++){
        deque<int> tt;
        for(int j = 0; j<M; j++){
            tt.push_back(board[i][j]);
        }
        t_board.push_back(tt);
        tt.clear();
    }

    set<pair<int,int> > kill;
    int howmany = 0;

    while(1){
        //cout << "howmany: " <<howmany << endl;
        if(coun <= howmany) break;
        for(int i = 0; i<archer.size(); i++){
            if(archer[i] == 1){
                pair<int,int> temp = find_enemy(t_board,N,i);
                if(temp.first == -1 && temp.second == -1){
                    continue;
                }
                kill.insert(temp);
            }
        }
        
        result += kill.size();
        howmany += kill.size();
        for(auto iter = kill.begin(); iter != kill.end(); iter++){
            t_board[iter->first][iter->second] = 0; 
        }

        deque<int> ttt;
        for(int i = 0; i<M; i++){
            ttt.push_back(0);
        }
        for(int i = 0; i<M; i++){
            if(t_board[N-1][i] == 1){
                howmany+=1;
            }
        }
        t_board.pop_back();
        t_board.push_front(ttt);
        /*
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                cout << t_board[i][j] << " ";
            }
            cout << endl;
        }*/
        kill.clear();
    }
    return result;
}


int main(){
    cin >> N >> M >> D;

    for(int i = 0; i< N ; i++){
        for(int j = 0; j<M; j++){
            cin >> board[i][j]; 
            if(board[i][j] == 1) coun++;
        }
    }
    for(int i = 0; i<(M-3); i++){
        comb.push_back(0);
    }
    for(int i = 0; i<3; i++){
        comb.push_back(1);
    }

    do{ 
        int res = get_score(comb);
        //cout << res << endl;
        answer = max(answer, res);

    }while(next_permutation(comb.begin(),comb.end()));


    cout << answer << endl;
    return 0;
}