#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

deque<pair<int, int> > dir;
int result;
//pair<int, int> shark;
//int d_shark;
deque<pair<int, int> > fish;
deque<int> d_fish;
int alive[17];
int map[4][4];

int find_sol(int score,pair<int,int> shark,int d_shark,int depth){
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4 ;j++){
            cout <<map[i][j] << " ";
        }
        cout << endl;
    }
    cout <<endl;
    cout << "where: " << shark.first << shark.second << endl;
    cout << "direction: " << d_shark << endl;
    cout<<score << endl;
    deque<pair<int, int> > q;
    deque<int> d_q;
    int tempx = shark.first;
    int tempy = shark.second;
    //물고기 이동
    int temp;
    int a,b;
    //cout << 2 << endl;
    
    for(int i = 1; i<=16; i++){
        if(alive[i] == 1){
            while(1){
                if(fish[i].first + dir[d_fish[i]].first < 0 || fish[i].second + dir[d_fish[i]].second < 0|| fish[i].first + dir[d_fish[i]].first >= 4 || fish[i].second + dir[d_fish[i]].second >= 4 || map[fish[i].first + dir[d_fish[i]].first][fish[i].second + dir[d_fish[i]].second] == -1){
                    d_fish[i] += 1;
                    if(d_fish[i] == 9){
                        d_fish[i] = 1;
                    }
                }
                else{
                    break;
                }
            }
            a=map[fish[i].first + dir[d_fish[i]].first][fish[i].second + dir[d_fish[i]].second];
            swap(fish[i],fish[map[fish[i].first + dir[d_fish[i]].first][fish[i].second + dir[d_fish[i]].second]]);
            swap(map[fish[i].first][fish[i].second],map[fish[a].first][fish[a].second]);
        }
    }
    while(1){
        tempx += dir[d_shark].first;
        tempy += dir[d_shark].second;
        //cout <<"shark: "<< shark.first << " " << shark.second << endl;
        if(tempx< 4 && tempy< 4 && tempx >=0 && tempy >= 0){
            if(map[tempx][tempy] == 0 || map[tempx][tempy] == -1){
                continue;
            }
            else{
                q.push_back(make_pair(tempx,tempy));
                d_q.push_back(d_fish[map[tempx][tempy]]);
            }
        }
        else{
            break;
        }
    }
    if(q.size() == 0){

        result = max(result, score);
        return 0;
    }
    pair<int,int> origin_shark;
    origin_shark = make_pair(shark.first,shark.second);
    map[shark.first][shark.second] = 0;
    temp = 0;
    int dtemp = d_shark;
    for(int i = 0; i<q.size(); i++){
        temp = map[q[i].first][q[i].second];
        alive[map[q[i].first][q[i].second]] = -1;
        map[q[i].first][q[i].second] = -1;
        for(int i = 0; i<4; i++){
            for(int j = 0; j<4 ;j++){
                cout <<map[i][j] << " ";
            }
            cout << endl;
        }
        cout <<endl;
        cout << fish[1].first << " " << fish[1].second << endl;
        find_sol(score+temp,make_pair(q[i].first,q[i].second),d_fish[temp],depth+1);
        cout << "???" << endl;
        map[q[i].first][q[i].second] = temp;
        alive[map[q[i].first][q[i].second]] = 1;
        
        //map[shark.first][shark.second] = temp;
        //alive[map[shark.first][shark.second]] = 1;
    }
    map[shark.first][shark.second] = -1;
    q.clear();
    return 0;
}

int main(){
    int temp,dtemp;
    int d_map[4][4];
    int d_shark;
    for(int i = 0; i<17; i++){
        fish.push_back(make_pair(0,0));
        d_fish.push_back(0);
        alive[i] = 1;
    }
    for(int i = 0; i<4 ; i++){
        for(int j = 0 ; j<4 ; j++){
            cin >> map[i][j] >> dtemp;
            fish[map[i][j]].first = i;
            fish[map[i][j]].second = j;
            d_fish[map[i][j]] = dtemp;
        }
    }
    result = map[0][0];
    d_shark = d_fish[map[0][0]];
    alive[map[0][0]] = -1;
    map[0][0] = -1;
    dir.push_back(make_pair(-100,-100));
    dir.push_back(make_pair(-1,0));
    dir.push_back(make_pair(-1,-1));
    dir.push_back(make_pair(0,-1));
    dir.push_back(make_pair(1,-1));
    dir.push_back(make_pair(1,0));
    dir.push_back(make_pair(1,1));
    dir.push_back(make_pair(0,1));
    dir.push_back(make_pair(-1,1));
    int k = find_sol(result,make_pair(0,0),d_shark,0);
    cout <<result << endl;
    return 0;
}