/*
    플로이드-와샬 알고리즘
*/

#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int gr[102][102] = {0};

int main(){
    int M,N;
    cin >> N;
    cin >> M;

    for(int i = 0; i<M; i++){
        int a, b;
        cin >> a >> b;
        gr[a][b] = 1;
    }

    for(int k = 1; k<=N; k++){
        for(int i = 1; i<=N; i++){
            for(int j = 1; j<=N; j++){
                if(gr[i][k] == 1 && gr[k][j] == 1){
                    gr[i][j] = 1;
                }
            }
        }
    }

    for(int i =  1; i<=N; i++){
        int cnt = 0;
        for(int j = 1; j<=N; j++){
            if(gr[i][j] == 0 && gr[j][i] == 0) cnt++;
        }
        cout << cnt-1 << endl;
    }

    return 0;
}