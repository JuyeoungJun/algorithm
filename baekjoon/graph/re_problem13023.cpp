#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;

deque<int> friends[2001];
int visited[2001];
deque<int> relations;
int result = 0;

int find_sol(int who){
    if(relations.size() == 5){
        result = 1;
        return 1;
    }

    for(int i = 0 ; i<friends[who].size(); i++){
        if(visited[friends[who][i]] == 0){
            relations.push_back(friends[who][i]);
            visited[friends[who][i]] = 1;
            find_sol(friends[who][i]);
            relations.pop_back();
            visited[friends[who][i]] = 0;
        }
    }

    return 0;
}


int main(){
    cin >> N >> M;
    int a,b;
    for(int i = 0; i<M ; i++){
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    for(int i = 0 ; i<N ; i++){
        if(result == 1) break;
        relations.push_back(i);
        visited[i] = 1;
        find_sol(i);
        visited[i] = 0;
        relations.pop_back();
    }
    cout << result << endl;
    return 0;
}