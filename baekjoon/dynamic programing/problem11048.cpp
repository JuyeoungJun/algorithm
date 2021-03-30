#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    int mapp[N][M];
    int result[N][M];
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M ; j++){
            result[i][j] = 0;
        }
    }
    for(int i = 0; i<N ; i++){
        for(int j = 0; j < M ; j++){
            scanf("%d",&mapp[i][j]);
        }
    }

    queue<pair<int,int> > q;
    q.push(make_pair(0,0));
    result[0][0] = mapp[0][0];
    result[N-1][M-1] = mapp[N-1][M-1];
    while(1){

        if(q.empty()){
            break;
        }
        if(q.front().first == N-1 && q.front().second == M-1){
            q.pop();
            continue;
        }
        if(q.front().first == N-1){
            if(mapp[q.front().first][q.front().second+1] + result[q.front().first][q.front().second] > result[q.front().first][q.front().second+1]){
                q.push(make_pair(q.front().first,q.front().second+1));
                result[q.front().first][q.front().second+1] = mapp[q.front().first][q.front().second+1] + result[q.front().first][q.front().second];
            }
            q.pop();
            continue;
        }
        else if(q.front().second == M-1){
            if(mapp[q.front().first+1][q.front().second] + result[q.front().first][q.front().second] > result[q.front().first+1][q.front().second]){
                q.push(make_pair(q.front().first+1,q.front().second));
                result[q.front().first+1][q.front().second] = mapp[q.front().first+1][q.front().second] + result[q.front().first][q.front().second];
            }
            q.pop();
            continue;
        }
        else{
            if(mapp[q.front().first][q.front().second+1] + result[q.front().first][q.front().second] > result[q.front().first][q.front().second+1]){
                q.push(make_pair(q.front().first,q.front().second+1));
                result[q.front().first][q.front().second+1] = mapp[q.front().first][q.front().second+1] + result[q.front().first][q.front().second];
            }
            if(mapp[q.front().first+1][q.front().second] + result[q.front().first][q.front().second] > result[q.front().first+1][q.front().second]){
                q.push(make_pair(q.front().first+1,q.front().second));
                result[q.front().first+1][q.front().second] = mapp[q.front().first+1][q.front().second] + result[q.front().first][q.front().second];
            }
            q.pop();
        }
    }

    cout << result[N-1][M-1] << endl;
    return 0;
}