/*
    BFS
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

vector<vector<int> > grap;

int main(){
    int N,M,V;
    int a,b;
    cin >> N >> M >> V;
    vector<int> temp;
    for(int i = 0 ; i<N ; i++){
        grap.push_back(temp);
    }
    for(int i = 0; i< M ; i++){
        cin >> a >> b;
        grap[a-1].push_back(b-1);
        grap[b-1].push_back(a-1);
    }
    int check[1001];
    int p;
    int sum = 0;
    vector<int> dfs;
    for(int i = 0; i<N ; i++){
        sort(grap[i].begin(),grap[i].end(),greater<int>());
    }
    for(int i = 0; i<1001 ; i++){
        check[i] = 0 ;
    }
    dfs.push_back(V-1);
    
    while(1){
        if(dfs.empty()){
            cout << "\n";
            break;
        }
        p = dfs.back();
        dfs.pop_back();
        if(check[p] != 1){
            cout << p+1 << ' ';
            sum ++;
            check[p] = 1;
        }

        if(sum == N){
            cout << "\n";
            break;
        }
        for(int i = 0; i<grap[p].size(); i++){
            if(check[grap[p][i]] != 1){
                dfs.push_back(grap[p][i]);
            }
        }
    }

    //bfs
    queue<int> bfs;
    
    for(int i = 0; i<1001 ; i++){
        check[i] = 0 ;
    }
    for(int i = 0; i<N ; i++){
        sort(grap[i].begin(),grap[i].end());
    }
    bfs.push(V-1);
    sum = 0;
    check[V-1] = 1;
    while(1){
        if(bfs.empty()){
            cout << "\n";
            return 0;
        }
        p = bfs.front();
        cout << p+1 << ' ';
        bfs.pop();
        sum ++;
        if(sum == N){
            cout << "\n";
            return 0;
        }
        for(int i = 0; i<grap[p].size(); i++){
            if(check[grap[p][i]] != 1){
                bfs.push(grap[p][i]);
                check[grap[p][i]] = 1;
            }
        }
    }
    
    return 0;
}

