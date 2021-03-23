/*
    시뮬레이션
    이전에 켜진 불 잘 고려해서 queue에 삽입
    BFS 변형
*/


#include <iostream>
#include <algorithm>
#include <deque>
#include <string>

using namespace std;

int N, M;

int direction[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
deque<pair<int, int> > sw[101][101];
int answer = 1;
int room[101][101];
int visited[101][101];
deque<pair<int, int> > q;

int turnOn(int a, int b){
    int cnt = 0;
    while(!sw[a][b].empty()){
        int nowa = sw[a][b].front().first;
        int nowb = sw[a][b].front().second;
        if(room[nowa][nowb] == 0){
            room[nowa][nowb] = 1;
            q.push_back(make_pair(nowa,nowb));
            cnt++;
        }
        sw[a][b].pop_front();
    }
    return cnt;
}

int main(){
    cin >> N >> M;



    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            room[i][j] = 0;
            visited[i][j] = 0;
        }
    }

    int x,y,a,b;
    for(int i = 0; i<M; i++){
        cin >> x >> y >> a >> b;
        sw[x][y].push_back(make_pair(a,b));
    }

    room[1][1] = 1;
    visited[1][1] = 1;
    answer += turnOn(1,1);
    q.push_front(make_pair(1,1));

    while(!q.empty()){
        int nowa = q.front().first;
        int nowb = q.front().second;
        int flag = 0;
        if(!(nowa == 1 && nowb == 1)){
            for(int i = 0; i<4; i++){ 
                int nexta = nowa+direction[i][0];
                int nextb = nowb+direction[i][1];
                if(nexta > 0 && nexta <= N && nextb > 0 && nextb <= N){
                    if(room[nexta][nextb] == 1 && visited[nexta][nextb] == 1){
                        answer += turnOn(nowa,nowb);
                        visited[nowa][nowb] = 1;
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(flag == 1){
            for(int i = 0; i<4; i++){ 
                int nexta = nowa+direction[i][0];
                int nextb = nowb+direction[i][1];
                if(nexta > 0 && nexta <= N && nextb > 0 && nextb <= N){
                    if(room[nexta][nextb] == 1 && visited[nexta][nextb] == 0){
                        q.push_back(make_pair(nexta,nextb));
                    }
                }
            }
        }

        q.pop_front();
    }
    
    cout << answer;
    return 0;
}