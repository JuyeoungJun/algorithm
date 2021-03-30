/*
  플루이드워샬 알고리즘
 */

#include <iostream>
#include <deque>
#include <algorithm>
#include <set>

using namespace std;

int N, K;
int board[11][11];
int dist[11][11];
int answer = 987654321;
int visited[11];

void DFS(int where, int depth, int d){

    if(depth == N) {
        answer = min(answer, d);
        return ;
    }
    
    for(int i = 0; i<N; i++){
        if(visited[i] == 0){
            visited[i] = 1;
            DFS(i,depth+1,d+dist[where][i]);
            visited[i] = 0;
        }
    }
}

int main(){
    cin >> N >> K;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> board[i][j];
            dist[i][j] = board[i][j];
        }
    }

    for(int i = 0; i<N; i++){
        visited[i] = 0;
    }
    for(int k = 0; k<N; k++){
        for(int a = 0; a<N; a++){
            for(int b = 0; b<N; b++){
                if(dist[a][k] + dist[k][b] < dist[a][b]){
                    dist[a][b] = dist[a][k] + dist[k][b];
                }
            }
        }
    }
    
    visited[K] = 1;
    DFS(K,1,0);
    cout << answer << endl;

    return 0;
}