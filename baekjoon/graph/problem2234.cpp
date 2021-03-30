#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

int n,m;
int direction[4][2] = { {0,-1}, {-1,0}, {0,1}, {1,0} };
deque<int> wall[51][51];
int board[51][51] = {0};

int makeSol(int nowa, int nowb, int count){
    queue<pair<int,int> > q;
    q.push(make_pair(nowa,nowb));
    int result = 1;
    board[nowa][nowb] = count;
    
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;

        for(int i = 0 ; i<4; i++){
            if(wall[a][b][i] == 0){
                int nexta = a + direction[i][0];
                int nextb = b + direction[i][1];
                if(nexta >= 0 && nexta < m && nextb >=0 && nextb < n){
                    if(board[nexta][nextb] == 0){
                        q.push(make_pair(nexta,nextb));
                        board[nexta][nextb] = count;
                        result++;
                    }

                }
            }
        }
        q.pop();
    }
    return result;
}

int main(){
    cin >> n >> m;
    int temp;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            deque<int> tempwall;
            cin >> temp;
            for(int k = 0; k<4; k++){
                wall[i][j].push_back(temp%2);
                temp/=2;
            }
        }
    }
    int count = 0;
    int M = 0;
    deque<int> cmp;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(board[i][j] == 0){
                count ++;
                int tt = makeSol(i,j,count);
                M = max(M, tt);
                cmp.push_back(tt);
            }
        }
    }
    cout << count << endl;
    cout << M << endl;
    int MM = 0;
    for(int i = 0; i<m; i++){
        for(int j = 0;j<n ;j++){
            for(int k = 0; k<4; k++){
                int nexta = i+direction[k][0];
                int nextb = j+direction[k][1];
                if(nexta >= 0 && nexta < m && nextb >=0 && nextb <n){
                    if(board[i][j] != board[nexta][nextb]){
                        MM = max(MM, cmp[board[i][j]-1]+cmp[board[nexta][nextb]-1]);
                    }
                }
            }
        }
    }
    cout << MM << endl;
    return 0;
}