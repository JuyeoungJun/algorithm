#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

class node{
    public:
        deque<int> ne;
        node(){};
};

int N;
int people[11];
node block[11];
deque<int> gett;
deque<int> now_connected;
int visited[11];
int result = 987654321;
int sumofpeople;

int check_connect(){
    deque<int> others;
    int temp_visited[11] = {};
    int ccheck = 0;
    for(int i = 0; i<N ; i++){
        temp_visited[i] = visited[i];
        ccheck += visited[i];
    }
    if(ccheck == N){
        return -1;
    }

    for(int i = 0; i<N; i++){
        if(temp_visited[i] == 0){
            others.push_back(i);
            break;
        }
    }
    int where;
    temp_visited[others[0]] = 1;
    while(1){
        if(others.empty() == 1){
            break;
        }
        where = others.front();
        for(int i = 0; i<block[where].ne.size(); i++){
            if(temp_visited[block[where].ne[i]] == 0){
                others.push_back(block[where].ne[i]);
                temp_visited[block[where].ne[i]] = 1;
            }
        }
        others.pop_front();
    }
    for(int i = 0; i<N ;i++){
        if(temp_visited[i] == 0){
            return -1;
        }
    }

    return 1;
}

int find_sol(){
    if(check_connect() == 1){
        int temp = 0;
        for(int i = 0; i<gett.size(); i++){
            temp += people[gett[i]];
        }
        int gettemp = 0;
        gettemp = sumofpeople - temp;
        gettemp = abs(gettemp - temp);
        result = min(gettemp,result);
    }

    for(int i = 0 ; i<now_connected.size();i++){
        if(visited[now_connected[i]] == 0){
            int count = 0;
            deque<int> tq;
            visited[now_connected[i]] = 1;
            gett.push_back(now_connected[i]);
            for(int j = 0; j<block[now_connected[i]].ne.size(); j++){
                if(visited[block[now_connected[i]].ne[j]] == 1){
                    continue;
                }
                if(find(now_connected.begin(),now_connected.end(),block[now_connected[i]].ne[j]) == now_connected.end()){
                    now_connected.push_back(block[now_connected[i]].ne[j]);
                    count++;
                }
            }
            find_sol();
            for(int j = 0; j<count; j++){
                now_connected.pop_back();
            }
            visited[now_connected[i]] = 0;
            gett.pop_back();
        }
    }
    return 0;
}

int main(){
    cin >> N ;
    for(int i = 0; i<N ; i++){
        cin >> people[i];
        sumofpeople += people[i];
    }

    int n, temp;
    for(int i = 0; i<N ; i++){
        cin >> n;
        for(int j= 0 ; j<n ; j++){
            cin >> temp;
            block[i].ne.push_back(temp-1);
        }
    }
    visited[0] = 1;
    gett.push_back(0);
    for(int j = 0;j<block[0].ne.size();j++){
        now_connected.push_back(block[0].ne[j]);
    }
    find_sol();

    if(result == 987654321){
        cout << -1 << endl;
    }
    else{
        cout << result << endl;
    }
    
    return 0;
}