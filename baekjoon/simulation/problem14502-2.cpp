#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

int board[9][9];
int N,M;
int answer = 0;
int f_safe = 0;
deque<pair<int,int> > where;

int count_safe(){
    int result = 0;
    deque<pair<int,int> > q;
    for(int i = 0; i<where.size(); i++){
        q.push_back(where[i]);
    }

    int temp_map[9][9];
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            temp_map[i][j] = board[i][j];
        }
    }

    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        
        if((a-1) >= 0 && (temp_map[a-1][b] == 0)){
            q.push_back(make_pair(a-1,b));
            temp_map[a-1][b] = 2;
            result++;
        }
        if((a+1) < N && (temp_map[a+1][b] == 0)){
            q.push_back(make_pair(a+1,b));
            temp_map[a+1][b] = 2;
            result++;            
        }
        if((b-1) >= 0 && (temp_map[a][b-1] == 0)){
            q.push_back(make_pair(a,b-1));
            temp_map[a][b-1] = 2;
            result++;            
        }
        if((b+1) < M && (temp_map[a][b+1] == 0)){
            q.push_back(make_pair(a,b+1));
            temp_map[a][b+1] = 2;
            result++;            
        }
        
        q.pop_front();
    }

    result = f_safe - result-3;

    return result;
}

int solve(int cnt){
    int temp_map[9][9];
    if(cnt == 3){
        answer = max(answer,count_safe());
        return 0;
    }

    /*
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            temp_map[i][j] = board[i][j];
        }
    }
*/

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(board[i][j] == 0){
                board[i][j] = 1;
                solve(cnt+1);
                board[i][j] = 0;
            }
        }
    }
    return 0;
}

int main(){
    cin >> N >> M;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>board[i][j];
            if(board[i][j] == 2){
                where.push_back(make_pair(i,j));
            }
            else if(board[i][j] == 0){
                f_safe++;
            }
        }
    }

    solve(0);
    cout << answer << endl;
    return 0;
    
}