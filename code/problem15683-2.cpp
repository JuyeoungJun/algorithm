#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

struct cctv{
    int x;
    int y;
    int what;
};

int N, M;
int board[9][9];
deque<cctv> tv;
deque<int> dir;
int answer = 987654321;

int see(){
    int temp_board[9][9];
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M;j++){
            temp_board[i][j] = board[i][j];
        }
    }
    for(int i = 0; i<tv.size(); i++){
        int a = tv[i].x;
        int b = tv[i].y;
        if(dir[i] == 0){
            if(tv[i].what == 1){
                //오
                for(int j = b+1; j<M; j++){
                    if(temp_board[a][j] == 6) break;
                    else if(temp_board[a][j] == 0){
                        temp_board[a][j] = -1;
                    }
                }
            }
            else if(tv[i].what == 2){
                //오
                for(int j = b+1; j<M; j++){
                    if(temp_board[a][j] == 6) break;
                    else if(temp_board[a][j] == 0) temp_board[a][j] = -1;
                    
                }
                //왼
                for(int j = b-1; j>=0 ; j--){
                    if(temp_board[a][j] == 6) break;
                    else if(temp_board[a][j] == 0) temp_board[a][j] = -1;
                }
            }
            else if(tv[i].what == 3){
                //오
                for(int j = b+1; j<M; j++){
                    if(temp_board[a][j] == 6) break;
                    else if(temp_board[a][j] == 0) temp_board[a][j] = -1;
                    
                }
                //아래
                for(int j = a+1; j<N; j++){
                    if(temp_board[j][b] == 6) break;
                    else if(temp_board[j][b] == 0) temp_board[j][b] = -1;
                }
            }
            else if(tv[i].what == 4){
                //오
                for(int j = b+1; j<M; j++){
                    if(temp_board[a][j] == 6) break;
                    else if(temp_board[a][j] == 0) temp_board[a][j] = -1;
                    
                }
                //아래
                for(int j = a+1; j<N; j++){
                    if(temp_board[j][b] == 6) break;
                    else if(temp_board[j][b] == 0) temp_board[j][b] = -1;
                }
                //왼
                for(int j = b-1; j>=0 ; j--){
                    if(temp_board[a][j] == 6) break;
                    else if(temp_board[a][j] == 0) temp_board[a][j] = -1;
                }
            }
            else if(tv[i].what == 5){
                                //오
                for(int j = b+1; j<M; j++){
                    if(temp_board[a][j] == 6) break;
                    else if(temp_board[a][j] == 0) temp_board[a][j] = -1;
                    
                }
                //아래
                for(int j = a+1; j<N; j++){
                    if(temp_board[j][b] == 6) break;
                    else if(temp_board[j][b] == 0) temp_board[j][b] = -1;
                }
                //왼
                for(int j = b-1; j>=0 ; j--){
                    if(temp_board[a][j] == 6) break;
                    else if(temp_board[a][j] == 0) temp_board[a][j] = -1;
                }
                //위
                for(int j = a-1; j>=0; j--){
                    if(temp_board[j][b] == 6) break;
                    else if(temp_board[j][b] == 0) temp_board[j][b] = -1;
                }
            }
        }
        else if(dir[i] == 1){
            if(tv[i].what == 1){
                //아래
                for(int j = a+1; j<N; j++){
                    if(temp_board[j][b] == 6) break;
                    else if(temp_board[j][b] == 0) temp_board[j][b] = -1;
                }
            }
            else if(tv[i].what == 2){
                //아래
                for(int j = a+1; j<N; j++){
                    if(temp_board[j][b] == 6) break;
                    else if(temp_board[j][b] == 0) temp_board[j][b] = -1;
                }
                                //위
                for(int j = a-1; j>=0 ;j--){
                    if(temp_board[j][b] == 6) break;
                    else if(temp_board[j][b] == 0) temp_board[j][b] = -1;
                }
            }
            else if(tv[i].what == 3){
                                //아래
                for(int j = a+1; j<N; j++){
                    if(temp_board[j][b] == 6) break;
                    else if(temp_board[j][b] == 0) temp_board[j][b] = -1;
                }
                                //왼
                for(int j = b-1; j>=0 ; j--){
                    if(temp_board[a][j] == 6) break;
                    else if(temp_board[a][j] == 0) temp_board[a][j] = -1;
                }
            }
            else if(tv[i].what == 4){
                                                //아래
                for(int j = a+1; j<N; j++){
                    if(temp_board[j][b] == 6) break;
                    else if(temp_board[j][b] == 0) temp_board[j][b] = -1;
                }
                                //왼
                for(int j = b-1; j>=0 ; j--){
                    if(temp_board[a][j] == 6) break;
                    else if(temp_board[a][j] == 0) temp_board[a][j] = -1;
                }
                                                //위
                for(int j = a-1; j>=0 ;j--){
                    if(temp_board[j][b] == 6) break;
                    else if(temp_board[j][b] == 0) temp_board[j][b] = -1;
                }
            }
        }
        else if(dir[i] == 2){
            if(tv[i].what == 1){
                                //왼
                for(int j = b-1; j>=0 ; j--){
                    if(temp_board[a][j] == 6) break;
                    else if(temp_board[a][j] == 0) temp_board[a][j] = -1;
                }
            }
            else if(tv[i].what == 3){
                //왼
                for(int j = b-1; j>=0 ; j--){
                    if(temp_board[a][j] == 6) break;
                    else if(temp_board[a][j] == 0) temp_board[a][j] = -1;
                }
                //위
                for(int j = a-1; j>=0 ;j--){
                    if(temp_board[j][b] == 6) break;
                    else if(temp_board[j][b] == 0) temp_board[j][b] = -1;
                }
            }
            else if(tv[i].what == 4){
                //왼
                for(int j = b-1; j>=0 ; j--){
                    if(temp_board[a][j] == 6) break;
                    else if(temp_board[a][j] == 0) temp_board[a][j] = -1;
                }
                //위
                for(int j = a-1; j>=0; j--){
                    if(temp_board[j][b] == 6) break;
                    else if(temp_board[j][b] == 0) temp_board[j][b] = -1;
                }
                                //오
                for(int j = b+1; j<M; j++){
                    if(temp_board[a][j] == 6) break;
                    else if(temp_board[a][j] == 0) temp_board[a][j] = -1;
                    
                }
            }
        }
        else if(dir[i] == 3){
            if(tv[i].what == 1){
                                //위
                for(int j = a-1; j>=0; j--){
                    if(temp_board[j][b] == 6) break;
                    else if(temp_board[j][b] == 0) temp_board[j][b] = -1;
                }
            }
            else if(tv[i].what == 3){
                                //위
                for(int j = a-1; j>=0; j--){
                    if(temp_board[j][b] == 6) break;
                    else if(temp_board[j][b] == 0) temp_board[j][b] = -1;
                }
                                //오
                for(int j = b+1; j<M; j++){
                    if(temp_board[a][j] == 6) break;
                    else if(temp_board[a][j] == 0) temp_board[a][j] = -1;
                    
                }
            }
            else if(tv[i].what == 4){
                                //위
                for(int j = a-1; j>=0 ;j--){
                    if(temp_board[j][b] == 6) break;
                    else if(temp_board[j][b] == 0) temp_board[j][b] = -1;
                }
                                //오
                for(int j = b+1; j<M; j++){
                    if(temp_board[a][j] == 6) break;
                    else if(temp_board[a][j] == 0) temp_board[a][j] = -1;
                }
                                //아래
                for(int j = a+1; j<N; j++){
                    if(temp_board[j][b] == 6) break;
                    else if(temp_board[j][b] == 0) temp_board[j][b] = -1;
                }
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(temp_board[i][j] == 0){
                cnt++;
            }
        }
    }

    return cnt;
}

int sol(int depth){
    if(depth == tv.size()){

        int temp = see();

        answer = min(answer,temp);
        return 0;
    }

    if(tv[depth].what == 1){
        for(int i = 0; i<4; i++){
            dir.push_back(i);
            sol(depth+1);
            dir.pop_back();
        }
    }
    else if(tv[depth].what == 2){
        for(int i = 0; i<2; i++){
            dir.push_back(i);
            sol(depth+1);
            dir.pop_back();
        }
    }
    else if(tv[depth].what == 3){
        for(int i = 0; i<4; i++){
            dir.push_back(i);
            sol(depth+1);
            dir.pop_back();
        }
    }
    else if(tv[depth].what == 4){
        for(int i = 0; i<4; i++){
            dir.push_back(i);
            sol(depth+1);
            dir.pop_back();
        }
    }
    else if(tv[depth].what == 5){
        dir.push_back(0);
        sol(depth+1);
        dir.pop_back();

    }
    return 0;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> board[i][j];
            if(board[i][j] >= 1 && board[i][j] <= 5){
                cctv temp;
                temp.x = i;
                temp.y = j;
                temp.what = board[i][j];
                tv.push_back(temp);
            }
        }
    }

    sol(0);
    cout << answer << endl;
    return 0;
}