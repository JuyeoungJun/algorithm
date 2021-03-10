#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

struct tree{
    int meal;
    deque<int> t;

};

int N,M,K;
int A[11][11];
tree tr[11][11];

int spring(){
    for(int i = 0; i<N; i++){
        for(int j = 0 ; j<N; j++){
            if(tr[i][j].t.size() != 0){
                int k;
                sort(tr[i][j].t.begin(),tr[i][j].t.end());
                for(k = 0 ; k<tr[i][j].t.size(); k++){
                    if(tr[i][j].meal >= tr[i][j].t[k]){
                        tr[i][j].meal -= tr[i][j].t[k];
                        tr[i][j].t[k]++;
                    }
                    else{
                        break;
                    }
                }
                int l = tr[i][j].t.size();
                for(int z = k; z<l; z++){
                    tr[i][j].meal += tr[i][j].t[z]/2;
                }
                for(int z = k; z<l; z++){
                    tr[i][j].t.pop_back();
                }
                
            }
        }
    }
    return 0;
}

int fall(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            for(int k = 0; k<tr[i][j].t.size(); k++){
                if(tr[i][j].t[k]%5 == 0){
                    //위
                    if(i-1 >= 0){
                        tr[i-1][j].t.push_front(1);
                    }
                    if(i-1 >= 0 && j+1 < N){
                        tr[i-1][j+1].t.push_front(1);
                    }
                    //오
                    if(j+1 < N){
                        tr[i][j+1].t.push_front(1);
                    }
                    if(i+1 < N && j+1<N){
                        tr[i+1][j+1].t.push_front(1);
                    }
                    //아래
                    if(i+1 < N) {
                        tr[i+1][j].t.push_front(1);
                    }
                    if(i+1 < N && j-1 >=0){
                        tr[i+1][j-1].t.push_front(1);
                    }
                    //왼
                    if(j-1 >= 0){
                        tr[i][j-1].t.push_front(1);
                    }
                    if(i-1 >=0 && j-1>=0){
                        tr[i-1][j-1].t.push_front(1);
                    }
                }
            }
        }
    }
    return 0;
}

int winter(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            tr[i][j].meal += A[i][j];
        }
    }
    return 0;
}

int main(){
    cin >> N >> M >> K;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> A[i][j];
            tr[i][j].meal = 5;
        }
    }
    int x,y,z;
    for(int i = 0; i<M; i++){
        cin >> x >> y >> z;
        tr[x-1][y-1].t.push_back(z);
    }
    for(int i = 0; i<K; i++){
        spring();
        fall();
        winter();
    }
    int answer = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            answer += tr[i][j].t.size();
        }
    }
    cout << answer << endl;
    return 0;
}