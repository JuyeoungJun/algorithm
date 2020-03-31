#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int w,h;
int map[51][51];
vector<pair<int,int> > direction;
int result = 0;
int makeRelated(int a, int b){
    queue<pair<int,int> > q;
    q.push(make_pair(a,b));
    //cout << "a:" << a << "b:" << b << endl;
    //cout << map[1][1] << endl;
    while(1){
        if(q.empty()){
            break;
        }
        //cout << "qsize" << q.size() << endl;
        for(int i = 0; i<8 ; i++){
            if(q.front().first+direction[i].first >= h || q.front().second+direction[i].second >= w){
                continue;
            }
            if(q.front().first+direction[i].first < 0 || q.front().second+direction[i].second < 0){
                continue;
            }
            if(map[q.front().first+direction[i].first][q.front().second+direction[i].second] == 1){
                //cout << "x:" << q.front().first+direction[i].first << "y:" <<q.front().second+direction[i].second << endl;
                q.push(make_pair(q.front().first+direction[i].first,q.front().second+direction[i].second));
                map[q.front().first+direction[i].first][q.front().second+direction[i].second] = -1;
            }
            //cout << "0,1:"<< map[0][1] << endl;
        }
        q.pop();
    }
    return 0;
}

int findSol(){
    for(int i = 0 ; i<h ; i++){
        for(int j = 0; j<w ; j++){
            if(map[i][j] == 1){
                makeRelated(i,j);
                result ++;    
            }
            
        }
    }
    return 0;
}

int main(){
    direction.push_back(make_pair(1,0));
    direction.push_back(make_pair(-1,0));
    direction.push_back(make_pair(0,1));
    direction.push_back(make_pair(0,-1));
    direction.push_back(make_pair(1,1));
    direction.push_back(make_pair(1,-1));
    direction.push_back(make_pair(-1,1));
    direction.push_back(make_pair(-1,-1));
    
    while(1){
        cin >> w >> h;
        if(w == 0 && h == 0){
            break;
        }
        result = 0;
        for(int i = 0; i<51 ; i++){
            for(int j = 0; j<51 ; j++){
                map[i][j] = -1;
            }
        }
        for(int i = 0; i<h ; i++){
            for(int j = 0; j<w ; j++){
                cin >> map[i][j];
            }
        }
       /*
        for(int i = 0; i<h ; i++){
            for(int j = 0; j<w ; j++){
                cout << map[i][j];
            }
            cout << endl;
        }
        */
        findSol();
        cout << result << endl;
    }
    


    return 0;
}