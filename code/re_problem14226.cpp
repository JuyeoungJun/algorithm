#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

int result = 987654321;
int S;
int visited[1001];

int find_sol(int where, int clipboard,int t){
    if(where > 1000){
        result = min(result,visited[S]);
        visited[S] = result;
        return 0;
    }
    if(where+clipboard < 1001 && visited[where+clipboard] > t+1){
        visited[where+clipboard] = t+1;
        find_sol(where+clipboard,clipboard,t+1);
    }
    if(where-1 > 1 && visited[where-1] > t+1){
        visited[where-1] = t+1;
        find_sol(where-1,clipboard,t+1);
    }
    if(where != clipboard){
        
        find_sol(where,where,t+1);
    }
    
    return 0;
}


int main(){
    cin >> S;
    for(int i = 0; i<1001 ; i++){
        visited[i] = 987654321;
    }
    find_sol(1,1,1);
    cout << visited[S] << endl;
    return 0;
}
