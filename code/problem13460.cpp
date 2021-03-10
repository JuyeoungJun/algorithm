#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

struct balls{
    int mov;
    int ra, rb, ba, bb;
};
int answer = -1;
int N,M;
char map[10][10];
int dir[4][2] = { {-1,0}, {1,0}, {0,1}, {0,-1} };
int visited[10][10][10][10];
int ha,hb;

void move(int &a, int &b, int d){
    while(1){
        a+= dir[d][0];
        b+= dir[d][1];
        if(map[a][b] == '#'){
            a -= dir[d][0];
            b -= dir[d][1];
            break;
        }
        else if(map[a][b] == 'O'){
            break;
        }
    }

}

int main(){
    cin >> N >> M;
    char temp;

    int ira, irb, iba, ibb;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M ; j++){
            cin >> map[i][j];
            if(map[i][j] == 'R'){
                ira = i;
                irb = j;
            }
            else if(map[i][j] == 'B'){
                iba = i; 
                ibb = j;
            }
            else if(map[i][j] == 'O'){
                ha = i;
                hb = j;
            }

        }
    }
    deque<balls> q;
    balls tempp = {0,ira,irb,iba,ibb};
    q.push_back(tempp);
    visited[ira][irb][iba][ibb] = 1;

    while(!q.empty()){
        tempp = q.front();
        visited[tempp.ra][tempp.rb][tempp.ba][tempp.bb] = 1;
        if(tempp.mov > 10){
            break;
        }
        if(tempp.ra == ha && tempp.rb == hb){
            answer = tempp.mov;
            break;
        }
        for(int i = 0; i<4; i++){
            int tra = tempp.ra;
            int trb = tempp.rb;
            int tba = tempp.ba;
            int tbb = tempp.bb;
            move(tra,trb,i);
            move(tba,tbb,i);
            if(tba == ha && tbb == hb) {
                continue;
            }
            if(tra == tba && trb == tbb){
                if(i == 0){
                    if(tempp.ra > tempp.ba){
                        tra +=1;
                    }
                    else{
                        tba +=1;
                    }
                }
                else if( i == 1){
                    if(tempp.ra > tempp.ba){
                        tba -=1;
                    }
                    else
                    {
                        tra -=1;
                    }
                    
                }
                else if( i == 2){
                    if(tempp.rb > tempp.bb){
                        tbb -=1;
                    }
                    else{
                        trb -=1;
                    }
                }
                else if( i == 3){
                    if(tempp.rb > tempp.bb){
                        trb += 1;
                    }
                    else{
                        tbb += 1;
                    }
                }

            }
            if(!visited[tra][trb][tba][tbb]){
                balls next = { tempp.mov+1, tra,trb,tba,tbb};
                q.push_back(next);
                visited[tra][trb][tba][tbb] = 1;
            }
        }
        q.pop_front();
    }
    cout << answer << endl;
    return 0;
}