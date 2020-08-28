#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int R,C;
int map[51][51];
deque<pair<int,int> > q;
deque<int> m;
deque<pair<int,int> > water;

int move_water(){
    int siz = water.size();
    int tempa,tempb;
    for(int i = 0 ; i<siz ; i++){
        tempa = water[i].first;
        tempb = water[i].second;

        //위
        if(tempa-1 >=0 && map[tempa-1][tempb] == 0){
            map[tempa-1][tempb] = 3;
            water.push_back(make_pair(tempa-1,tempb));
        }
        //아래
        if(tempa+1 < R && map[tempa+1][tempb] == 0){
            map[tempa+1][tempb] = 3;
            water.push_back(make_pair(tempa+1,tempb));
        }
        //오
        if(tempb+1 < C && map[tempa][tempb+1] == 0){
            map[tempa][tempb+1] = 3;
            water.push_back(make_pair(tempa,tempb+1));
        }
        //왼
        if(tempb-1 >=0 && map[tempa][tempb-1] == 0){
            map[tempa][tempb-1] = 3;
            water.push_back(make_pair(tempa,tempb-1));
        }
        
    }
    return 0;
}

int main(){
    char temp;
    cin >> R >> C;
    for(int i = 0 ; i<R ; i++){
        for(int j = 0; j<C ; j++){
            cin >> temp;
            if(temp == 'D'){
                map[i][j] = 2;
            }
            else if(temp == 'S'){
                map[i][j] = 3;
                q.push_back(make_pair(i,j));
                m.push_back(0);
            }
            else if(temp == '.'){
                map[i][j] = 0;
            }
            else if(temp == '*'){
                map[i][j] = 3;
                water.push_back(make_pair(i,j));
            }
            else if(temp == 'X'){
                map[i][j] = 4;
            }
        }
    }
    move_water();
    int now = 1;
    int tempa, tempb;
    while(1){
        /*
        cout << m.front() << endl;
        cout << now << endl;
        for(int i = 0 ; i<R ; i++){
            for(int j = 0; j<C; j++){
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
*/
        if(q.empty()){
            cout << "KAKTUS" << endl;
            return 0;
        }
        if(m.front() == now){
            now++;
            move_water();
        }
        tempa = q.front().first;
        tempb = q.front().second;
        if(map[tempa-1][tempb] == 2 || map[tempa+1][tempb] == 2 || map[tempa][tempb-1] == 2 || map[tempa][tempb+1] == 2){
            break;
        }
        //위
        if(tempa-1 >=0 && map[tempa-1][tempb] == 0){
            map[tempa-1][tempb] = 3;
            q.push_back(make_pair(tempa-1,tempb));
            m.push_back(m.front()+1);
        }
        //아래
        if(tempa+1 < R && map[tempa+1][tempb] == 0){
            map[tempa+1][tempb] = 3;
            q.push_back(make_pair(tempa+1,tempb));
            m.push_back(m.front()+1);
        }
        //오
        if(tempb+1 < C && map[tempa][tempb+1] == 0){
            map[tempa][tempb+1] = 3;
            q.push_back(make_pair(tempa,tempb+1));
            m.push_back(m.front()+1);
        }
        //왼
        if(tempb-1 >=0 && map[tempa][tempb-1] == 0){
            map[tempa][tempb-1] = 3;
            q.push_back(make_pair(tempa,tempb-1));
            m.push_back(m.front()+1);
        }
        q.pop_front();
        m.pop_front();
    }
    cout << now << endl;
    return 0;
}