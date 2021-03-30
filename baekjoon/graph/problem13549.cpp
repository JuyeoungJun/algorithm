#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main(){
    int N,K;
    deque<int> q;
    int t[200000];
    int visited[200000];
    cin >> N >> K;
    q.push_back(N);
    int qtemp,ttemp;
    
    for(int i = 0; i<200000;i++){
        visited[i] = 0;
    }
    visited[N] = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop_front();
        if(2*now <= 200000){
            if(visited[2*now] == 0){
                q.push_front(2*now);
                t[2*now] = t[now];
                visited[2*now] = 1;
            }
        }
        if((now+1) <= 200000){
            if(visited[now+1] == 0){
                q.push_back(now+1);
                t[now+1] = t[now]+1;
                visited[now+1] = 1;
            }
        }
        if((now-1) >= 0){
            if(visited[now-1] == 0 ){
                q.push_back(now-1);
                t[now-1] = t[now] + 1;
                visited[now-1] = 1;
            }
        }
    }
    cout << t[K] << endl;
    return 0;
}