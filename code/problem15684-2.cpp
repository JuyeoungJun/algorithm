#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int N,M,H;
int line[11][31];
int answer = 4;

bool check(){

    for(int i = 0; i<N; i++){
        int where = i;
        for(int j = 0; j<H; j++){
            where += line[where][j];
        }
        if(where != i) return false;
    }

    return true;
}

int make_line(int depth, int l, int h){
    if(depth >= answer) return 0;


    //if(depth >= 3) return -1;

    for(int i = l; i<N-1; i++){
        for(int j = h; j<H; j++){
            if(line[i][j] == 0 && line[i+1][j] == 0){
                line[i][j] = 1;
                line[i+1][j] = -1;
                if(check()){
                    answer = min(answer, depth+1);
                    line[i][j]= 0;
                    line[i+1][j] = 0;
                    return 0;
                }
                if(depth <= 1){
                    make_line(depth+1, l, h+1);
                }
                
                line[i][j] = 0;
                line[i+1][j] = 0;
            }
        }
    }
    return 0;
}

int main(){
    cin >> N >> M >> H;
    int a,b;
    for(int i = 0; i<M; i++){
        cin >> a >> b;
        line[b-1][a-1] = 1;
        line[b][a-1] = -1;
    }
    if(M == 0){
        cout << 0 << endl;
    }
    if(check()){
        cout << 0 << endl;
        return 0;
    }
    make_line(0,0,0);
    if(answer == 4){
        answer = -1;
    }
    cout << answer << endl;

    return 0;
}
