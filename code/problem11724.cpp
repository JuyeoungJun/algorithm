#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int isConnected[1001][1001];
int N,M;
int connectInfo[1001];
int visited[1001];
deque<int> q;
int result = 0;

int find_connect(){
    int temp;
    while(!q.empty()){
        temp = q.front();
        for(int i = 0 ; i<N ; i++){
            if(visited[i] == 1){
                continue;
            }
            if(isConnected[temp][i] == 1){
                visited[i] = 1;
                connectInfo[i] = result;
                q.push_back(i);
            }
        }
        q.pop_front();
    }
    return 0;
}

int main(){
    cin >> N >> M;
    int tempa, tempb;
    for(int i = 0; i<M ; i++){
        cin >> tempa >> tempb;
        isConnected[tempa-1][tempb-1] = 1;
        isConnected[tempb-1][tempa-1] = 1;
    }

    for(int i = 0 ; i < N; i++){
        if(connectInfo[i] != 0){
            continue;
        }
        else{
            q.clear();
            q.push_back(i);
            visited[i] = 1;
            result++;
            find_connect();
        }
    }
    cout << result << endl;
    return 0;
}