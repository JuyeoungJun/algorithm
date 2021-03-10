#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int cnt;
int board[10][10];
int answer = 987654321;
int check[5] = {5,5,5,5,5};

deque<pair<int,int> > is_del(int a, int b, int si){
    deque<pair<int,int> > result;
    //cout << "size: " <<si << endl;
    for(int i = 0; i<si; i++){
        for(int j = 0; j<si; j++){
            //cout << i << " " << j << endl;
            if(board[a+i][b+j] == 1){
                result.push_back(make_pair(a+i,b+j));
            }
        }
    }
    return result;
}

int find_sol(int cn,int depth){
    if(depth >= answer) return 0;
    if(cnt == cn){
        answer = min(answer,depth);
        return 0;
    }
    //cout << "=======================" << endl;
    int a,b;
    int t_board[10][10];
    
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            t_board[i][j] = board[i][j];
            //cout << board[i][j] << " ";
        }
        //cout << endl;
    }
    int flag = 0;
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            if(t_board[i][j] == 1){
                a = i;
                b = j;
                flag = 1;        
                break;
            }
        }
        if(flag == 1) break;
    }
    //cout << "abcheck: " <<a <<" "<< b << endl;
    for(int i = 4; i>=0; i--){
        //cout << "i: " << i << endl;
        if(check[i] == 0) continue;
        if(((a+i+1) > 10) || ((b+i+1) > 10)) continue;
        deque<pair<int,int> > t;
        t = is_del(a,b,i+1);
        //cout << t.size() << endl;
        if(t.size() == ((i+1)*(i+1))){
            for(int j = 0; j<t.size(); j++){
                board[t[j].first][t[j].second] = 0;
            }
            check[i]--;
            find_sol(cn+t.size(), depth+1);
            for(int j = 0; j<t.size(); j++){
                board[t[j].first][t[j].second] = 1;
            }
            check[i]++;
        }
        
    }
    return 0;
}


int main(){
    for(int i = 0 ; i<10 ; i++){
        for(int j = 0 ; j<10 ; j++){
            cin >> board[i][j];
            if(board[i][j]) cnt++;
        }
    }

    find_sol(0,0);
    if(answer == 987654321) answer = -1;
    cout << answer << endl;
    return 0;
}