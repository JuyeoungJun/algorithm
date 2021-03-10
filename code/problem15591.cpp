#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string.h>

using namespace std;

int N,Q;
deque<int> checker[5002];
int dis[5002][5002] = {0};
int visited[5002] = {0};
int result = 0;
int k,v;

int main(){
    cin >> N >> Q;
    int a,b,c;
    for(int i = 0; i<N-1 ; i++){
        cin >> a >> b >> c;
        checker[a].push_back(b);
        checker[b].push_back(a);
        dis[a][b] = c;
        dis[b][a] = c;
    }

    for(int i = 0; i<Q; i++){
        cin >> k >> v;
        result = 0;
        for(int j = 0; j<5002; j++) visited[j] = 0;
        visited[v] = 1;
        queue<int> q;
        q.push(v);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int j = 0; j<checker[cur].size(); j++){
                if(visited[checker[cur][j]] == 0){
                    if(dis[cur][checker[cur][j]] >= k){
                        result ++;
                        visited[checker[cur][j]] = 1;
                        q.push(checker[cur][j]);
                    }
                }
            }
        }

        cout << result << endl;
    }
    return 0;
}