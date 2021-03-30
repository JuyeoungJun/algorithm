/*
    시뮬레이션
    x, y 좌표 문제 조건에 맞게 잘 설정하기
*/


#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int A, B;
int N, M;

int direction[4][2] = { {1,0}, {0,-1}, {-1,0}, {0,1} };

struct robot{
    int x;
    int y;
    int d;

};

deque<robot> robots;

int board[101][101] = {0};

int main(){
    cin >> A >> B;
    cin >> N >> M;

    int x,y;
    char d;

    for(int i = 0; i<N; i++){
        cin >> x >> y >> d;
        int di = 0;
        if(d == 'E'){
            di = 0;
        }
        else if(d == 'W'){
            di = 2;
        }
        else if(d == 'N'){
            di = 3;
        }
        else{
            di = 1;
        }

        robot temp;
        temp.x = x-1;
        temp.y = y-1;
        temp.d = di;
        board[x-1][y-1] = i+1;
        robots.push_back(temp);
    }

    int flag = 0;

    for(int i = 0; i<M; i++){
        int r,iter;
        char com;
        cin >> r >> com >> iter;

        if(flag == 1) continue;

        if(com == 'F'){
            int nextx = robots[r-1].x + (iter*direction[robots[r-1].d][0]);
            int nexty = robots[r-1].y + (iter*direction[robots[r-1].d][1]);

            nextx = robots[r-1].x;
            nexty = robots[r-1].y;
            for(int j = 0; j<iter; j++){
                nextx += direction[robots[r-1].d][0];
                nexty += direction[robots[r-1].d][1];
                if(nextx < 0 || nextx >= A || nexty <0 || nexty >= B){
                    cout << "Robot " << r << " crashes into the wall" << endl;
                    flag = 1;
                    break;
                }

                if(board[nextx][nexty] != 0) {
                    cout << "Robot " << r << " crashes into robot " << board[nextx][nexty] << endl;;
                    flag = 1;
                    break;
                }
                
            }
            if(flag == 1) continue;
            else{
                board[robots[r-1].x][robots[r-1].y] = 0;
                robots[r-1].x = nextx;
                robots[r-1].y = nexty;
                board[nextx][nexty] = r;
            }
        }
        else if(com == 'R'){
            int dir = robots[r-1].d;
            dir += iter;
            dir %= 4;
            robots[r-1].d = dir;
        }
        else{
            int dir = robots[r-1].d;
            int tempiter = iter%4;
            for(int j = 0; j<tempiter; j++){
                robots[r-1].d--;
                if(robots[r-1].d == -1){
                    robots[r-1].d = 3;
                }
            }
        }
    }
    if(flag == 0 ) cout << "OK" << endl;

    return 0;
}