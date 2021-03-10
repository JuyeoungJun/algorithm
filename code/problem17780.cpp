#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;


struct horse{
    int a;
    int b;
    int d;
    deque<int> upper;
};

int N, K;
deque<horse> h;
int board[13][13];
deque<int> st[13][13];
int direction[4][2] = { {0,1}, {0,-1}, {-1,0}, {1,0} };

int move(int i){
    int nexta = h[i].a + direction[h[i].d][0];
    int nextb = h[i].b + direction[h[i].d][1];        
    if(nexta >= N || nexta <0 || nextb >=N || nextb < 0 || board[nexta][nextb] == 2){
        if(h[i].d == 0){
            h[i].d = 1;
        }
        else if(h[i].d == 1){
            h[i].d = 0;
        }
        else if(h[i].d == 2){
            h[i].d = 3;
        }
        else{
            h[i].d = 2;
        }
        nexta = h[i].a + direction[h[i].d][0];
        nextb = h[i].b + direction[h[i].d][1];
    }
    if(nexta >= N || nexta < 0 || nextb >= N || nextb <0 || board[nexta][nextb] == 2){
        return 0;
    }
    deque<int> &now = st[h[i].a][h[i].b];
    deque<int> &next = st[nexta][nextb];
    auto where = find(now.begin(),now.end(),i);

    if(board[nexta][nextb] == 1){
        reverse(where,now.end());
    }

    for(auto it = where; it != now.end(); it++){
        h[*it].a = nexta;
        h[*it].b = nextb;
        next.push_back(*it);
    }

    now.erase(where,now.end());
    return next.size();
}

int main(){
    cin >> N >> K;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> board[i][j];
        }
    }

    int x,y,z;
    for(int i = 0; i<K; i++){
        cin >> x >> y >> z;
        horse temp;
        temp.a = x-1;
        temp.b = y-1;
        temp.d = z-1;
        st[x-1][y-1].push_back(i);
        h.push_back(temp);
    }
    int turn = 0;
    for(int t = 1; t<= 1000 ; t++){
        for(int i = 0; i<K; i++){
            if(st[h[i].a][h[i].b].front() != i) continue;
            if(move(i) >= 4){
                cout << t << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}