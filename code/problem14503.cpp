#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

int N,M;
int r,c,d;
int map[51][51];
int result = 2;
deque<pair<int, int> > direction;

int find_sol(){
    int flag = 1;
    int tempa,tempb,di;
    while(1){
        /*
        cout << result << endl;
        cout << r << " " << c << " " << d <<endl;
        
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        */
        //4방향 확인
        flag = 1;
        tempa = r;
        tempb = c;
        di = d;
        for(int i = 0; i<4; i++){
            di = di - 1;
            if(di == -1){
                di = 3;
            }
            tempa = r+direction[di].first;
            tempb = c+direction[di].second;
            if(map[tempa][tempb] == 1 || map[tempa][tempb] == 2){
                continue;
            }
            else if(map[tempa][tempb] == 0) {
                flag = 0;
                r = tempa;
                c = tempb;
                d = di;
                map[tempa][tempb] = result;
                result += 1;
                break;
            }
        }
        if(flag == 1){
            di = (d+2)%4;
            tempa = r+direction[di].first;
            tempb = c+direction[di].second;
            //cout << tempa << " " << tempb << endl;
            //후진
            if(map[tempa][tempb] == 1){
                return 0;
            }
            else{
                r = tempa;
                c = tempb;
            }
            //안되면 종료
        }

    }
    return 0;
}

int main(){
    cin >> N >> M;
    cin >> r >> c >> d;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> map[i][j];
        }
    }
    map[r][c] = result;
    result += 1;
    direction.push_back(make_pair(-1,0));
    direction.push_back(make_pair(0,1));
    direction.push_back(make_pair(1,0));
    direction.push_back(make_pair(0,-1));
    find_sol();
    /*
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
*/
    cout << result-2 << endl;
    return 0;
}