#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int N;
int board[101][101];
int dir[4][2] = { {0,1}, {-1,0}, {0,-1}, {1,0} };


int sol(int x, int y, int d, int g){
    deque<int> di;
    di.push_back(d);

    while(1){
        if(g == 0) break;

        int l = di.size();
        for(int i = l-1; i>=0; i--){
            di.push_back((di[i]+1)%4);
        }
        g--;
    }

    for(int i = 0; i<di.size(); i++){
        board[y][x] = 1;
        y += dir[di[i]][0];
        x += dir[di[i]][1];
    }
    board[y][x] = 1;
    return 0;
}

int check(int a, int b){
    if(board[a+1][b] == 0) return 0;
    if(board[a][b+1] == 0) return 0;
    if(board[a+1][b+1] == 0 ) return 0;
    return 1;

}

int main(){
    cin >> N;
    int x,y,d,g;
    for(int i = 0; i<N; i++){
        cin >> x >> y >> d >> g;
        sol(x,y,d,g);
        /*
        for(int j = 0; j<15; j++){
            for(int k = 0; k<15; k++){
                cout << board[j][k] << " ";
            }
            cout << endl;
        }
        cout << "====================" << endl;
*/
    }
    
    int answer = 0;
    for(int i = 0; i<100; i++){
        for(int j = 0; j<100; j++){
            if(board[i][j] == 1){
                if(check(i,j) == 1){
                    answer++;
                }
            }
        }
    }
    cout << answer << endl;
    return 0;
}