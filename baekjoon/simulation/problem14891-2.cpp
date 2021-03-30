#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

deque<string> tob;

int rotation(int who, int dir){
    deque<int> q;
    deque<int> d_q;
    q.push_back(who);
    d_q.push_back(dir);
    int check[4] = {0,0,0,0};
    check[who] = 1;
    while(!q.empty()){
        int where = q.front();
        int d = d_q.front();
        if(where >= 1 && check[where-1] == 0 && tob[where-1][2] != tob[where][6]){
            q.push_back(where-1);
            if(d == 1){
                d_q.push_back(-1);
            }
            else if(d == -1){
                d_q.push_back(1);
            }
            check[where-1] = 1;
        }
        if(where < 3 && check[where+1] == 0 && tob[where][2] != tob[where+1][6]){
            q.push_back(where+1);
            if(d == 1){
                d_q.push_back(-1);
            }
            else if(d == -1){
                d_q.push_back(1);
            }
            check[where+1] = 1;
        }
        if(d == 1){
            tob[where] = tob[where].back() + tob[where];
            tob[where].erase(8,1);
        }
        else if(d == -1){
            tob[where] = tob[where] + tob[where].front();
            tob[where].erase(0,1);
        }

        q.pop_front();
        d_q.pop_front();
    }

    return 0;
}


int main(){
    string temp;
    for(int i = 0; i<4; i++){
        cin >> temp;
        tob.push_back(temp);
    }    

    int K;
    cin >> K;
    int dir;
    int who;
    int answer = 0;
    for(int i = 0; i<K; i++){
        cin >> who >> dir;
        who --;
        rotation(who,dir);


    }
    for(int j = 0; j<4; j++){ 
        int score = tob[j][0] - '0';
        answer += score * pow(2,j);
    }
    cout << answer << endl;
    return 0;
}