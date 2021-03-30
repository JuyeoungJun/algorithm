/*
    다익스트라 알고리즘
*/
#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

int N, M;

deque<pair<int, int> > bus[1001];
int cost[1001];

bool operator<(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

int dijkstra(int start, int end){
    priority_queue<pair<int, int> > q;
    q.push({start,0});
    for(int i = 1; i<=N; i++){
        cost[i] = 987654321;
    }

    cost[start] = 0;

    while(!q.empty()){
        int now = q.top().first;
        int dis = q.top().second;
        q.pop();
        // for(int i = 1; i<=N; i++) cout << cost[i] << " ";
        // cout << endl;
        if(dis > cost[now]) continue;
        for(int i = 0; i<bus[now].size(); i++){
            int next = bus[now][i].first;
            int nextdis = dis + bus[now][i].second;
            if(nextdis < cost[next]){
                cost[next] = nextdis;
                q.push({next,nextdis});
            }
        }

    }
    return cost[end];
}

int main(){
    cin >> N >> M;
    int a, b, c;
    for(int i = 0; i<M ; i++){
        cin >> a >> b >> c;
        bus[a].push_back( {b, c} );
    }
    int start, end;
    cin >> start >> end;
    cout << dijkstra(start, end) << endl;
    return 0;
}