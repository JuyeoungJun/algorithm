#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

struct tree{
    int x;
    int y;
    int age;
};

int N,M,K;
int A[11][11];
int ground[11][11];
tree t[101];
deque<int> who[11][11];

void spring(){
    for(int i = 0; i<N ; i++){
        for(int j = 0; j<N ; j++){
            if(who[i][j].empty()){
                continue;
            }
            int where = 0;
            int flag = 0;
            for(int k = 0; k<who[i][j].size(); k++){
                if(ground[i][j] - who[i][j][k] >= 0){
                    ground[i][j] -= who[i][j][k];
                    who[i][j][k] += 1;
                }
                else{
                    where = k;
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                for(int k = where; k<who[i][j].size();k++){
                    ground[i][j] += who[i][j][k]/2;
                }
                who[i][j].erase(who[i][j].begin()+where,who[i][j].end());
            }

            
        }
    }
}

void fall(){
    for(int i = 0; i<N ; i++){
        for(int j =0; j<N; j++){
            if(who[i][j].empty()){
                continue;
            }
            for(int k = 0; k<who[i][j].size();k++){
                if(who[i][j][k] % 5 == 0){
                    //위
                    if(i-1 >= 0){
                        who[i-1][j].push_front(1);
                    }
                    //아래
                    if(i+1 < N){
                        who[i+1][j].push_front(1);
                    }
                    //오
                    if(j+1 < N){
                        who[i][j+1].push_front(1);
                    }
                    //왼
                    if(j-1 >= 0){
                        who[i][j-1].push_front(1);
                    }
                    //1시
                    if(i-1 >= 0 && j+1 < N){
                        who[i-1][j+1].push_front(1);
                    }
                    //5시
                    if(i+1 < N && j+1 < N){
                        who[i+1][j+1].push_front(1);
                    }
                    //7시
                    if(i+1 < N && j-1 >= 0){
                        who[i+1][j-1].push_front(1);
                    }
                    //11시
                    if(i-1 >= 0 && j-1 >= 0){
                        who[i-1][j-1].push_front(1);
                    }
                }
            }
        }
    }
}

int find_result(){
    int result = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            result += who[i][j].size();
        }
    }
    return result;
}

int main(){
    cin >> N >> M >> K;
    for(int i = 0; i<N; i++){
        for(int j = 0 ; j<N; j++){
            cin >> A[i][j];
            ground[i][j] = 5;
        }
    }
    int tempx,tempy,tempa;
    for(int i = 0; i<M ; i++){
        cin >> tempx >> tempy >> tempa;
        who[tempx-1][tempy-1].push_back(tempa);
    }
    for(int i = 0; i<K; i++){
        spring();
        fall();
        for(int j = 0 ;j<N; j++){
            for(int k = 0; k<N; k++){
                ground[j][k] += A[j][k];
            }
        }
    }
    int result = 0;
    result = find_result();
    cout << result << endl;
    return 0;
}