#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

int N,M,K;
int A[51][51];
deque<deque<int> > com;
int visited[7];
int direction[4][2] = { {0,1}, {1,0} , {0,-1}, {-1,0} };
int answer = 987654321;
void rotation(int r, int c, int s){
    for(int i = s; i> 0; i--){
        int a = r-i;
        int b = c-i+1;
        int next = A[a][b-1];
        int index = 1;
        A[r-i][c-i] = A[r-i+1][c-i];
        int di = 0;
        while(1){
            if(index == (i*2)*4){
                break;
            }
            int temp;
            temp = next;
            next = A[a][b];
            A[a][b] = temp;
            if((index%(i*2)) == 0){
                di++;
            }
            a += direction[di][0];
            b += direction[di][1];
            index++;
        }

    }
}

int find_sol(int depth){
    if(depth == K){
        int result = 987654321;
        for(int i = 0; i<N ; i++){
            int cmp = 0;
            for(int j = 0; j<M; j++){
                cmp += A[i][j];
            }
            result = min(result,cmp);
        }
        answer = min(result,answer);
        return 0;
    }
    for(int i = 0; i< com.size(); i++){
        if(visited[i] == 0){
            int AT[51][51];
            for(int i = 0; i<N; i++){
                for(int j = 0; j<M; j++){
                    AT[i][j] = A[i][j];
                }
            }
            visited[i] = 1;
            rotation(com[i][0]-1,com[i][1]-1,com[i][2]);
            find_sol(depth+1);
            for(int i = 0; i<N; i++){
                for(int j = 0; j<M; j++){
                    A[i][j] = AT[i][j];
                }
            }
            visited[i] = 0;
        }
    }
    return 0;
}

int main(){
    cin >> N >> M >> K;

    for(int i = 0; i<N ; i++){
        for(int j = 0; j<M ; j++){
            cin >> A[i][j]; 
        }
    }

    for(int i = 0 ; i<K ; i++){
        int r,c,s;
        deque<int> temp;
        cin >> r >> c >> s;
        temp.push_back(r);
        temp.push_back(c);
        temp.push_back(s);
        com.push_back(temp);
    }

    find_sol(0);

    cout << answer << endl;
    return 0;
}