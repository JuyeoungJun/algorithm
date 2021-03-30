#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int N;
int V,E;
vector<int> isConnected[20001];
int connect_info[20001];
int result;

int make_graph(int t){
    deque<int> q;
    connect_info[t] = 1;
    q.push_front(t);
    while(!q.empty()){
        int a = q.front();
        q.pop_front();
        for(int i = 0; i<isConnected[a].size(); i++){
            if(connect_info[isConnected[a][i]] == 0){
                q.push_back(isConnected[a][i]);
                connect_info[isConnected[a][i]] = -connect_info[a];
            }
            else{
                if(connect_info[isConnected[a][i]] == connect_info[a]){
                    result = -1;
                    return 0;
                }
            }
        }
    }
    return 0;
}

int main(){
    cin >> N;
    int start = 0;
    for(int i = 0;i<N ; i++){
        for(int j = 0; j<=V; j++){
            isConnected[j].clear();
            connect_info[j] = 0;
        }
        cin >> V >> E;
        int tempa,tempb;
        for(int j = 0 ; j<E; j++){
            cin >> tempa >> tempb;
            if(j == 0){
                start = tempa;
            }
            isConnected[tempa-1].push_back(tempb-1);
            isConnected[tempb-1].push_back(tempa-1);
        }
        result = 1;
        for(int j = 0 ; j<V; j++){
            if(result == -1){
                break;
            }
            if(connect_info[j] == 0){
                make_graph(j);
            }
        }
        if(result == -1){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}