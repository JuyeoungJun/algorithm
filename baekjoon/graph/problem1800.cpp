/*
    다익스트라(변형)
    이분탐색
*/

#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;


int answer = -1;
int N,P,K;
deque<pair<int,int> > n[1001];
int dist[1001];

bool operator<(pair<int,int> a, pair<int, int> b){
    return a.second > b.second;
}

bool dijkstra(int mid){
    priority_queue<pair<int, int> > q;
    q.push(make_pair(1,0));

    for(int i = 1; i<=N; i++){
        dist[i] = 987654321;
    }
    dist[1] = 0;
    while(!q.empty()){
        int now = q.top().first;
        int dis = q.top().second;
        q.pop();
        if(dist[now] < dis) continue;
        for(int i = 0; i<n[now].size(); i++){
            int next = n[now][i].first;
            int nextdis = dis + (n[now][i].second > mid);
            if( nextdis < dist[next]){
                dist[next] = nextdis;
                q.push(make_pair(next, nextdis));
            }
        }

    }
    return dist[N] <= K;
}

int main(){
    cin >> N >> P >> K;
    int l = 0, r = 0;
    int a,b,c;
    for(int i = 0; i<P; i++){
        cin >> a >> b >> c;
        n[a].push_back({b,c});
        n[b].push_back({a,c});
        r = max(r,c);
    }
    int mid;
    while(l <= r){
        mid = l + (r-l)/2;
        if(dijkstra(mid)) {
            r = mid - 1;
            answer = mid;
        }
        else{
            l = mid+1;
        }

    }

    cout << answer << endl;
    return 0;
}