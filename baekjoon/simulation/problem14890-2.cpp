#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N,L;
int board[101][101];

bool check_v(int i){
    int where = 1;
    int prev = board[0][i];
    int cnt = 1;
    while(1){
        //cout << where << endl;
        if(where >= N) return true;
        if(board[where][i] == prev){
            //cout << "check1" << endl;
            cnt++;
            where++;
        }
        else if(board[where][i] == (prev+1)){
            //cout << "check2" << endl;
            if(cnt >= L){
                cnt = 1;
                prev = board[where][i];
                where++;
            }
            else{
                return false;
            }

        }
        else if(board[where][i] == (prev-1)){
            //cout << "check3" << endl;
            for(int j = 1; j<L; j++){
                if((where+j) > N) return false;
                if(board[where][i] == board[where+j][i]) {
                    cnt = 0;
                }
                else {
                    return false;
                }
            }
            prev = board[where][i];
            where+=L;
            cnt = 0;
            
        }
        else{
            //cout << "check4" << endl;
            return false;
        }
    }
    return true;

}

bool check_h(int i){
    int where = 1;
    int prev = board[i][0];
    int cnt = 1;
    while(1){
        //cout << where << endl;
        //cout << "prev: " << prev << endl;
        if(where >= N) return true;
        if(board[i][where] == prev){
            //cout << "check1" << endl;
            cnt++;
            where++;
        }
        else if(board[i][where] == (prev+1)){
            //cout << "check2" << endl;
            if(cnt >= L){
                cnt = 1;
                prev = board[i][where];
                where++;
            }
            else{
                return false;
            }

        }
        else if(board[i][where] == (prev-1)){
            //cout << "check3" << endl;
            for(int j = 1; j<L; j++){
                if(board[i][where] == board[i][where+j]) {
                    cnt = 0;
                }
                else {
                    return false;
                }
            }
            prev = board[i][where];
            //cout << "prev check: " << prev << endl;
            where+=L;
            cnt = 0;
        }
        else{
            //cout << "check4" << endl;
            return false;
        }
    }
    return true;
}


int main(){
    cin >> N >> L;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> board[i][j];
        }
    }
    int answer = 0;
    for(int i = 0; i<N; i++){
        //cout << "this is " << i << "=======" << endl;
        if(check_v(i)) {
            //cout << "v_right" << endl;
            answer++;
        }
        if(check_h(i)) {
            //cout << "h_right" << endl;
            answer++;
        }

    }
    cout <<answer << endl;
    return 0;
}