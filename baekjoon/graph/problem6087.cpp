#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

int W, H;
char board[101][101];
int visited[101][101];
deque<pair<int, int> > point;
int direction[4][2] = { {0,1}, {1,0}, {0,-1},{-1,0} };

int main(){
    cin >> W >> H;


    for(int i = 0 ; i<H; i++){
        for(int j = 0; j<W; j++){
            cin >> board[i][j];
            if(board[i][j] == 'C'){
                point.push_back(make_pair(i,j));
            }
        }
    }

    for(int i = 0; i<H; i++){
        for(int j = 0; j<W; j++){
            visited[i][j] = 987654321;
        }
    }
    deque<deque<int> > q;
    deque<int> temp;
    temp.push_back(point[0].first);
    temp.push_back(point[0].second);
    temp.push_back(0);
    temp.push_back(-1);
    q.push_back(temp);
    temp.clear();
    int result = 987654321;
    while(!q.empty()){
        int a = q.front()[0];
        int b = q.front()[1];
        int mirror = q.front()[2];
        int dir = q.front()[3];
        q.pop_front();
        if(a == point[1].first && b == point[1].second){
            result = min(result,mirror);
            continue;
        }
        for(int i = 0; i<4; i++){
            if(dir != -1){
                if(i == dir-2 || i == dir+2) continue;
            }
            int nexta = a + direction[i][0];
            int nextb = b + direction[i][1];
            
            if(nexta >= 0 && nexta <H && nextb >= 0 && nextb < W){
                if(board[nexta][nextb] == '.' || board[nexta][nextb] == 'C'){
                    if(dir == -1){
                        temp.push_back(nexta);
                        temp.push_back(nextb);
                        temp.push_back(1);
                        temp.push_back(i);
                        q.push_back(temp);
                        visited[nexta][nextb] = 1;
                        temp.clear();
                    }
                    else if(dir == i){
                        if(visited[nexta][nextb] >= mirror){
                            temp.push_back(nexta);
                            temp.push_back(nextb);
                            temp.push_back(mirror);
                            temp.push_back(i);
                            q.push_back(temp);
                            visited[nexta][nextb] = mirror;
                            temp.clear();
                        }
                    }
                    else{
                        if(visited[nexta][nextb] >= mirror+1){
                            temp.push_back(nexta);
                            temp.push_back(nextb);
                            temp.push_back(mirror+1);
                            temp.push_back(i);
                            q.push_back(temp);
                            visited[nexta][nextb] = mirror+1;
                            temp.clear();
                        }
                    }
                }

            }
        }

    }

    cout << result-1 << endl;
    return 0;
}