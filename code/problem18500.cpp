#include <iostream>
#include <deque>
#include <algorithm>
#include <queue>

using namespace std;

int R,C;

char board[101][101];

int checkCluster(int a, int b){
    // cout << a << " " << b << endl;
    if(a >= R || a < 0 || b>=C || b<0) return 0;

    queue<pair<int, int> > q;
    int vistied[101][101] = {0};
    int m[C];

    for(int i = 0; i<C; i++){
        m[i] = -1;
    }

    q.push(make_pair(a,b));
    vistied[a][b] = 1;
    m[b] = a;
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        if(r == R-1) {
            return 1;
        }
        //위
        if(r-1 >= 0 ){
            if(vistied[r-1][c] == 0 && board[r-1][c] == 'x'){
                q.push(make_pair(r-1,c));
                m[c] = max(m[c],r-1);
                vistied[r-1][c] = 1;
            }
        }
        //아래
        if(r+1 < R){
            if(vistied[r+1][c] == 0 && board[r+1][c] == 'x'){
                q.push(make_pair(r+1,c));
                m[c] = max(m[c],r+1);
                vistied[r+1][c] = 1;
            }
        }
        //오
        if(c+1 < C){
            if(vistied[r][c+1] == 0 && board[r][c+1] == 'x'){
                q.push(make_pair(r,c+1));
                m[c+1] = max(m[c+1],r);
                vistied[r][c+1] = 1;
            }
        }
        //왼
        if(c-1 >= 0){
            if(vistied[r][c-1] == 0 && board[r][c-1] == 'x'){
                q.push(make_pair(r,c-1));
                m[c-1] = max(m[c-1],r);
                vistied[r][c-1] = 1;
            }
        }
        q.pop();
    }
    int distance = 987654321;
    deque<pair<int,int> > temp;
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            // cout << vistied[i][j] << " ";
            if(vistied[i][j] == 1){
                board[i][j] = '.';
                temp.push_back(make_pair(i,j));
            }
        }
        // cout << endl;
    }
    // cout << endl;


    for(int i = 0 ; i<C ; i++){
        if(m[i] == -1) continue;
        int bo = R;
        int bbo = m[i];
        for(int j = R-1; j>=0; j--){
            if(board[j][i] == 'x') bo = j;
            if(vistied[j][i] == 1){
                bbo = j;
            }
            if(bo - bbo > 0) distance = min(distance,(bo-bbo));
        }
    }
    // cout << distance << endl;
    // for(int i = 0 ; i<C; i++){
    //     cout << "C: " << i <<endl;
    //     cout << "M: " << M[i] << "m: " << m[i] << endl;
    // }

    for(int i = 0; i<temp.size(); i++){
        board[temp[i].first+distance-1][temp[i].second] = 'x';
    }
    

    return 0;
}

int destory(int turn, int what){
    int b = -1;
    if(turn == 0){
        for(int i = 0; i<C; i++){
            if(board[what][i] == 'x'){
                b = i;
                break;
            }
        }
    }
    else{
        for(int i = C-1; i>=0; i--){
            if(board[what][i] == 'x'){
                b = i;
                break;
            }
        }
    }

    if(b == -1) return 0;

    board[what][b] = '.';
    
    // cout << "===========================" << endl;
    // cout << "where: " <<what << " " << b << endl;
    if(b-1 >= 0 && board[what][b-1] == 'x'){
        checkCluster(what,b-1);
    }
    if(b+1 < C && board[what][b+1] == 'x'){
        checkCluster(what,b+1);
    }
    
    if(what+1 < R && board[what+1][b] =='x'){
        checkCluster(what+1,b);
    }
    
    if(what-1 >= 0 && board[what-1][b] == 'x'){
        checkCluster(what-1,b);
    }
    
    // for(int i = 0; i<R; i++){
    //     for(int j = 0; j<C; j++){
    //         cout << board[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}


int main(){
    cin >> R >> C;
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            cin >> board[i][j];
        }
    }

    int N;
    cin >> N;
    int what;
    for(int i = 0; i<N; i++){
        cin >> what;
        what = R-what;

        destory(i%2,what);

    }
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
    
    return 0;
}