#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

int N,M;
int map[101][101];
queue<pair<int,int> > q;
vector<pair<int,int> > direction;
queue<int> val;

int main(){
    string temp;
    int m = 0;
    char ch;
    char ttemp[100];
    cin >> N >> M;
    for(int i = 0; i<N;i++){
        cin >> temp;
        for(int j = 0; j<M;j++){
            m = temp[j] - '0';
            map[i][j] = m;
        }
    }
    q.push(make_pair(0,0));
    val.push(1);
    direction.push_back(make_pair(1,0));
    direction.push_back(make_pair(-1,0));
    direction.push_back(make_pair(0,1));
    direction.push_back(make_pair(0,-1));
    while(1){
        if(q.empty()){
            cout << "No answer!" << endl;
            break;
        }
        if(q.front().first == N-1 && q.front().second == M-1){
            cout << val.front() << endl;
            break;
        }
        for(int i = 0; i<4 ; i++){
            if(q.front().first+direction[i].first < 0){
                continue;
            }
            if(q.front().second+direction[i].second < 0){
                continue;
            }
            if(q.front().first+direction[i].first >= N){
                continue;
            }
            if(q.front().second+direction[i].second >= M){
                continue;
            }
            if(map[q.front().first+direction[i].first][q.front().second+direction[i].second] == 1){
                q.push(make_pair(q.front().first+direction[i].first,q.front().second+direction[i].second));
                val.push(val.front()+1);
                map[q.front().first+direction[i].first][q.front().second+direction[i].second] = -1;
            }
        }
        q.pop();
        val.pop();
    }
    return 0;
}