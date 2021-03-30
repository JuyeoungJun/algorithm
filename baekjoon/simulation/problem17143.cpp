#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

struct shark{
    int s;
    int d;
    int z;
    int alive;
};

int R,C,M;

shark map[101][101];
deque<pair<int, int> > alive_shark;
int direction[4][2] = { {-1,0}, {1,0}, {0,1}, {0,-1} };
int result = 0;

int get_shark(int where){
    int get = 0;
    for(int i = 0; i<R; i++){
        if(map[i][where].alive == 1){
            get = map[i][where].z;
            map[i][where].alive = 0;
            alive_shark.erase(find(alive_shark.begin(),alive_shark.end(),make_pair(i,where)));
            break;
        }
    }
    return get;
}

void move_shark(){
    shark tempmap[101][101];
    deque<pair<int, int> > talive_shark;
    for(int i =0 ; i<101 ; i++){
        for(int j = 0; j<101; j++){
            tempmap[i][j].s = 0;
            tempmap[i][j].d = 0;
            tempmap[i][j].z = 0;
            tempmap[i][j].alive = 0;
        }
    }
    for(int i = 0; i<alive_shark.size(); i++){
        int a = alive_shark[i].first;
        int b = alive_shark[i].second;
        int nextr, nextc;
        nextr = a; nextc = b;
       
        int ts=0;
        if(map[a][b].d == 0 || map[a][b].d == 1){
            ts = 0;
            ts = map[a][b].s % (2*(R-1));
        }
        else{
            ts = 0;
            ts = map[a][b].s % (2*(C-1));
        }
        
        for(int j = 0 ; j<ts; j++){
            nextr += direction[map[a][b].d][0];
            nextc += direction[map[a][b].d][1];
            if(nextr < 0 || nextc < 0 || nextr >= R || nextc >= C){
                if(map[a][b].d == 0){
                    map[a][b].d = 1;
                }
                else if(map[a][b].d == 1){
                    map[a][b].d = 0;
                }
                else if(map[a][b].d == 2){
                    map[a][b].d = 3;
                }
                else if(map[a][b].d == 3){
                    map[a][b].d = 2;
                }
                nextr += 2*direction[map[a][b].d][0];
                nextc += 2*direction[map[a][b].d][1];
            }
        }
        
        if(tempmap[nextr][nextc].alive == 1){
            if(tempmap[nextr][nextc].z < map[a][b].z){
                tempmap[nextr][nextc].s = map[a][b].s;
                tempmap[nextr][nextc].d = map[a][b].d;
                tempmap[nextr][nextc].z = map[a][b].z;
            }
            tempmap[nextr][nextc].alive = 1;
        }
        else{
            tempmap[nextr][nextc].s = map[a][b].s;
            tempmap[nextr][nextc].d = map[a][b].d;
            tempmap[nextr][nextc].z = map[a][b].z;
            tempmap[nextr][nextc].alive = 1;
            talive_shark.push_back(make_pair(nextr,nextc));
        }
    }

    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            map[i][j] = tempmap[i][j];
        }
    }
    alive_shark.clear();
    for(int i = 0; i<talive_shark.size(); i++){
        alive_shark.push_back(talive_shark[i]);
    }
}

int main(){
    cin >> R >> C >> M;
    int r,c,temps,tempd,tempz;
    for(int i =0 ; i<101 ; i++){
        for(int j = 0; j<101; j++){
            map[i][j].s = 0;
            map[i][j].d = 0;
            map[i][j].z = 0;
            map[i][j].alive = 0;
        }
    }

    for(int i = 0; i<M ; i++){
        cin >> r >> c >> temps >> tempd >> tempz;
        map[r-1][c-1].s = temps;
        map[r-1][c-1].d = tempd-1;
        map[r-1][c-1].z = tempz;
        map[r-1][c-1].alive = 1;
        alive_shark.push_back(make_pair(r-1,c-1));
    }
    
    for(int i = 0; i<C; i++){
        result += get_shark(i);
        move_shark();
    }

    cout << result << endl;
    return 0;
}