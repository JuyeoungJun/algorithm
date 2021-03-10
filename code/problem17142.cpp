#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int N,M;
int map[51][51];
int blank;
deque<pair<int,int> > birus;
deque<pair<int,int> > who;
int visited[11];
int result = 987654321;


int bfs(){
    int tempmap[51][51];
    int tempblank = blank;
    deque<int> tim;
    deque<pair<int, int> > q;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            tempmap[i][j] = map[i][j];
        }
    }
    for(int i = 0; i<who.size(); i++){
        tempmap[who[i].first][who[i].second] = 1;
        tim.push_back(0);
        q.push_back(who[i]);
    }
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        if(a-1 >= 0 && tempmap[a-1][b] == 0){
            q.push_back(make_pair(a-1,b));
            tim.push_back(tim.front()+1);
            tempmap[a-1][b] = tim.front()+1;
            tempblank -= 1;
        }
        if(a+1 < N && tempmap[a+1][b] == 0){
            q.push_back(make_pair(a+1,b));
            tim.push_back(tim.front()+1);
            tempmap[a+1][b] = tim.front()+1;
            tempblank -=1;
        }
        if(b-1 >= 0 && tempmap[a][b-1] == 0){
            q.push_back(make_pair(a,b-1));
            tim.push_back(tim.front()+1);
            tempmap[a][b-1] = tim.front()+1;
            tempblank -= 1;
        }
        if(b+1 < N && tempmap[a][b+1] == 0){
            q.push_back(make_pair(a,b+1));
            tim.push_back(tim.front()+1);
            tempmap[a][b+1] = tim.front()+1;
            tempblank -= 1;
        }
        if(a-1 >= 0 && tempmap[a-1][b] == -1){
            q.push_back(make_pair(a-1,b));
            tim.push_back(tim.front()+1);
            tempmap[a-1][b] = tim.front()+1;
        }
        if(a+1 < N && tempmap[a+1][b] == -1){
            q.push_back(make_pair(a+1,b));
            tim.push_back(tim.front()+1);
            tempmap[a+1][b] = tim.front()+1;
        }
        if(b-1 >= 0 && tempmap[a][b-1] == -1){
            q.push_back(make_pair(a,b-1));
            tim.push_back(tim.front()+1);
            tempmap[a][b-1] = tim.front()+1;
        }
        if(b+1 < N && tempmap[a][b+1] == -1){
            q.push_back(make_pair(a,b+1));
            tim.push_back(tim.front()+1);
            tempmap[a][b+1] = tim.front()+1;
        }
        if(tempblank == 0){
            return tim.front()+1;
        }
        q.pop_front();
        tim.pop_front();

    }
    return 987654321;
}

int make_p(int start_point, int depth){
    if(depth == M){
        result = min(result,bfs());
        return 0;
    }
    for(int i = start_point; i<birus.size(); i++){
        if(visited[i] == 0){
            visited[i] = 1;
            who.push_back(make_pair(birus[i].first,birus[i].second));
            make_p(i+1,depth+1);
            who.pop_back();
            visited[i] = 0;
        }
    }
    return 0;
}   

int main(){
    cin >> N >> M;
    blank = N*N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >>map[i][j];
            if(map[i][j] == 1){
                blank -=1;
            }
            if(map[i][j] == 2){
                map[i][j] = -1;
                blank -= 1;
                birus.push_back(make_pair(i,j));
            }
        }
    }
    if(blank == 0){
        cout << "0" << endl;
        return 0;
    }
    make_p(0,0);
    if(result == 987654321){
        cout << "-1" << endl;
        return 0;
    }
    cout << result << endl;
    return 0;
}