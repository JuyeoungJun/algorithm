#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

deque<pair<int, int> > dir;
pair<int, int> shark;
int d_shark;
int result;
int score;

class node{
    public:
        int alive;
        int a;
        int b;
        int d;
        node(){};
        node(int _alive, int _a, int _b, int _d){
            alive = _alive;
            a = _a;
            b = _b;
            d = _d;
        }
};

node fish[17];

int find_fish(int x, int y){
    for(int i = 0 ; i<17; i++){
        if(fish[i].alive == 1 && fish[i].a == x && fish[i].b == y){
            return i;
        }
    }
    return -1;
}

int move_fish(){
    int tempa, tempb;
    for(int i = 1; i<=16 ; i++){
        if(fish[i].alive == -1){
            continue;
        }
        else{
            while(1){
                tempa = fish[i].a + dir[fish[i].d].first;
                tempb = fish[i].b + dir[fish[i].d].second;
                if(shark.first == tempa && shark.second == tempb){
                    fish[i].d += 1;
                    if(fish[i].d == 9){
                        fish[i].d = 1;
                    } 
                    continue;
                }
                if(tempa < 0 || tempb < 0 || tempa >= 4 || tempb >=4){
                    fish[i].d += 1;
                    if(fish[i].d == 9){
                        fish[i].d = 1;
                    }
                    continue;
                }
                else{
                    int swapfish = find_fish(tempa,tempb);
                    if(swapfish != -1){
                        fish[swapfish].a = fish[i].a;
                        fish[swapfish].b = fish[i].b;
                    }
                    fish[i].a = tempa;
                    fish[i].b = tempb;
                    break;
                }
            }

        }
    }
    return 0;
}

int find_sol(){
    move_fish();
    node tempfish[17];
    for(int i = 0; i<17 ; i++){
        tempfish[i] = fish[i];
    }
    int tempa = shark.first;
    int tempb = shark.second;
    pair<int, int> tempshark;
    tempshark = shark;
    int tempscore = score;
    int tempresult = result;
    int tempdshark = d_shark;
    int flag = 0;
    for(int i = 1; i<=3; i++){
        //cout << "tempab: " << tempa << " " << tempb << endl;
        tempa = shark.first + dir[d_shark].first*i;
        tempb = shark.second + dir[d_shark].second*i;
        if(tempa < 0 || tempb < 0 || tempa >=4 || tempb >= 4){
            break;
        }
        else if(find_fish(tempa,tempb) == -1){
            continue;
        }
        else{
            int temp = find_fish(tempa,tempb);
            if(fish[temp].alive == 1){
                flag = 1;
                shark.first = fish[temp].a;
                shark.second = fish[temp].b;
                d_shark = fish[temp].d;
                fish[temp].alive = -1;
                score += temp;
                //cout << "what fish? "<<temp << endl;
                find_sol();
                score = tempscore;
                shark = tempshark;
                d_shark = tempdshark;
                for(int i = 0; i<17; i++){
                    fish[i] = tempfish[i];
                }
            }
        }

    }
    if(flag == 0){
        result = max(result,score);
        return 0;
    }
    return 0;
}

int main(){
    int num,dtemp;
    for(int i = 0; i<4 ; i++){
        for(int j = 0 ; j<4 ; j++){
            cin >> num >> dtemp;
            fish[num] = node(1,i,j,dtemp);
        }
    }
    shark = make_pair(0,0);
    result = find_fish(0,0);
    score = result;
    fish[result].alive = -1;
    d_shark = fish[result].d;
    dir.push_back(make_pair(-100,-100));
    dir.push_back(make_pair(-1,0));
    dir.push_back(make_pair(-1,-1));
    dir.push_back(make_pair(0,-1));
    dir.push_back(make_pair(1,-1));
    dir.push_back(make_pair(1,0));
    dir.push_back(make_pair(1,1));
    dir.push_back(make_pair(0,1));
    dir.push_back(make_pair(-1,1));
    find_sol();
    cout <<result << endl;
    return 0;
}