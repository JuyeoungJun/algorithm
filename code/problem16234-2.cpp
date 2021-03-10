#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N,L,R;
int board[51][51];
int temp_board[51][51];

deque<pair<int,int> > make_union(int x,int y){
    deque<pair<int,int> > result;
    deque<pair<int,int> > q;
    q.push_back(make_pair(x,y));
    temp_board[x][y] = 1;
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        //위
        if(a-1>=0 && temp_board[a-1][b] == 0){
            if(abs(board[a-1][b]-board[a][b]) <= R &&  abs(board[a-1][b]-board[a][b]) >= L){
                q.push_back(make_pair(a-1,b));
                temp_board[a-1][b] = 1;
                result.push_back(make_pair(a-1,b));
            }
        }
        //오
        if(b+1<N && temp_board[a][b+1] == 0){
            if(abs(board[a][b+1]-board[a][b]) <= R &&  abs(board[a][b+1]-board[a][b]) >= L){
                q.push_back(make_pair(a,b+1));
                temp_board[a][b+1] = 1;
                result.push_back(make_pair(a,b+1));
            }
        }
        //아래
        if(a+1<N && temp_board[a+1][b] == 0){
            if(abs(board[a+1][b]-board[a][b]) <= R &&  abs(board[a+1][b]-board[a][b]) >= L){
                q.push_back(make_pair(a+1,b));
                temp_board[a+1][b] = 1;
                result.push_back(make_pair(a+1,b));
            }
        }

        //왼
        if(b-1>=0 && temp_board[a][b-1] == 0){
            if(abs(board[a][b-1]-board[a][b]) <= R &&  abs(board[a][b-1]-board[a][b]) >= L){
                q.push_back(make_pair(a,b-1));
                temp_board[a][b-1] = 1;
                result.push_back(make_pair(a,b-1));
            }
        }
        q.pop_front();
    }

    if(result.size() == 0) return result;
    else{
        result.push_front(make_pair(x,y));
        return result;
    }
}


int sol(int depth){
    /*
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }*/

    for(int i = 0; i<51; i++){
        for(int j = 0; j<51; j++){
            temp_board[i][j] = 0;
        }
    }

    deque<deque<pair<int,int> > >result;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(temp_board[i][j] == 0){
                deque<pair<int,int> > temp;
                temp = make_union(i,j);
                if(temp.size() != 0) result.push_back(temp);
            } 
        }
    }    
    
    if(result.size() == 0){
        return depth;
    }
    else{
        for(int i = 0; i<result.size(); i++){
            /*
            for(int j = 0; j<result[i].size(); j++){
                cout << result[i][j].first << " " <<result[i][j].second << endl;
            }*/
            int s = 0;
            for(int j = 0; j<result[i].size(); j++){
                s += board[result[i][j].first][result[i][j].second];
            }
            s = s/result[i].size();
            for(int j = 0; j<result[i].size(); j++){
                board[result[i][j].first][result[i][j].second] = s;
            }
        }
        return sol(depth+1);
    }

}

int main(){
    cin >> N >> L >> R;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> board[i][j];
        }
    }

    cout << sol(0) << endl;

    return 0;
}