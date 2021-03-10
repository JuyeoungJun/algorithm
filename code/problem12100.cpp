#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int map[21][21];
int result = 0;

void shift(int dir){
    deque<int> q;
    if(dir == 0){
       //위 
        for(int i = 0 ; i<N; i++){
            for(int j = 0; j<=N ; j++){
                if(map[j][i] != 0){
                    q.push_back(map[j][i]);
                    map[j][i] = 0;
                }
            }
            int idx = 0;
            while(!q.empty()){
                int temp = q.front();
                q.pop_front();
                if(q.empty()){
                    map[idx][i] = temp;
                    break;
                }
                else if(temp == q.front()){
                    temp *= 2;
                    q.pop_front();
                }
                map[idx][i] = temp;
                idx++;
            }
        }

    }
    else if(dir == 1){
        //아래
        for(int i = 0 ; i<N; i++){
            for(int j = N-1; j>=0 ; j--){
                if(map[j][i] != 0){
                    q.push_back(map[j][i]);
                    map[j][i] = 0;
                }
            }
            int idx = N-1;
            while(!q.empty()){
                int temp = q.front();
                q.pop_front();
                if(q.empty()){
                    map[idx][i] = temp;
                    break;
                }
                else if(temp == q.front()){
                    temp *= 2;
                    q.pop_front();
                }
                map[idx][i] = temp;
                idx--;
            }
        }
    }
    else if(dir == 2){
        //오
        for(int i = 0 ; i<N; i++){
            for(int j = N-1; j>=0 ; j--){
                if(map[i][j] != 0){
                    q.push_back(map[i][j]);
                    map[i][j] = 0;
                }
            }
            int idx = N-1;
            while(!q.empty()){
                int temp = q.front();
                q.pop_front();
                if(q.empty()){
                    map[i][idx] = temp;
                    break;
                }
                else if(temp == q.front()){
                    temp *= 2;
                    q.pop_front();
                }
                map[i][idx] = temp;
                idx--;
            }
        }

    }
    else{
        //왼
        for(int i = 0 ; i<N; i++){
            for(int j = 0; j<N ; j++){
                if(map[i][j] != 0){
                    q.push_back(map[i][j]);
                    map[i][j] = 0;
                }
            }
            int idx = 0;
            while(!q.empty()){
                int temp = q.front();
                q.pop_front();
                if(q.empty()){
                    map[i][idx] = temp;
                    break;
                }
                else if(temp == q.front()){
                    temp *= 2;
                    q.pop_front();
                }
                map[i][idx] = temp;
                idx++;
            }
        }
    }

}

int find_max(){
    int max_value = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N ; j++){
            max_value = max(max_value,map[i][j]);
        }
    }
    return max_value;
}

int find_sol(int depth){
    if(depth == 5){
        result = max(result,find_max());
        return 0;
    }
    int tempmap[21][21];
    for(int i = 0 ; i<N ; i++){
        for(int j = 0; j < N ; j++){
            tempmap[i][j] = map[i][j];
        }
    }

    for(int i = 0; i<4; i++){
        shift(i);
        find_sol(depth+1);
        for(int i = 0 ; i<N ; i++){
            for(int j = 0; j < N ; j++){
                map[i][j] = tempmap[i][j];
            }
        }
    }
    return 0;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j<N ; j++){
            cin >> map[i][j];
        }
    }

    find_sol(0);
    cout << result << endl;
    return 0;
}