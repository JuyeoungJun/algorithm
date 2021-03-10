#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    int visited[100001];
    int route[100001];
    queue<pair<int,int> > q;
    q.push(make_pair(N,0));
    visited[q.front().first] = 1;
    int chase;
    vector<int> pree;
    while(1){
        if(q.front().first == K){
            cout << q.front().second << endl;
            chase = q.front().first;
            pree.push_back(chase);
            while(1){
                chase = route[chase];
                if(chase == 0){
                    for(int i = pree.size()-1; i>=0;i--){
                        cout << pree[i] << " ";
                    }
                    cout << endl;
                    break;
                }
                pree.push_back(chase);
            }
            break;
        }
        if(visited[q.front().first*2] == 0){
            visited[q.front().first*2] = 1;
            route[q.front().first*2] = q.front().first;
            q.push(make_pair(q.front().first*2,q.front().second+1));
        }
        if(visited[q.front().first-1] == 0){
            visited[q.front().first-1] = 1;
            route[q.front().first-1] = q.front().first;
            q.push(make_pair(q.front().first-1,q.front().second+1));
        }
        if(visited[q.front().first+1] == 0){
            visited[q.front().first+1] = 1;
            route[q.front().first+1] = q.front().first;
            q.push(make_pair(q.front().first+1,q.front().second+1));
        }
        q.pop();
    }
    return 0;
}