#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N,M;
int mapp[100][100];
int visited[100][100];
struct a
{
    int x;
    int y;
    int cost;
    a(int x, int y ,int cost) : x(x),y(y),cost(cost){

    }
};

struct cmp
{
    /* data */
    bool operator()(a t, a u){
        return t.cost > u.cost;
    }
};


priority_queue<a,vector<a>,cmp > q;


int main(){
    int result[100][100];
    scanf("%d %d", &N,&M);
    string t;
    for(int i = 0; i<M ; i++){
        cin >> t;
        for(int j = 0; j< N ; j++){
            mapp[i][j] = t[j] - '0';
        }
    }
    q.push(a(0,0,0));
    a temp(0,0,0);    
    for(int i = 0; i<100 ; i++){
        for(int j = 0; j<100 ; j++){
            visited[i][j] = 0;
        }
    }
    visited[0][0] = 1;
    while(1){
        if(q.empty()){
            break;
        }
        if(q.top().x == M-1 && q.top().y == N-1){
            cout << q.top().cost;
            break;
        }
        temp = q.top();
        q.pop();
        if(temp.x+1 < M){
            if(visited[temp.x+1][temp.y] != 1){
                if(mapp[temp.x+1][temp.y]== 1){
                    q.push(a(temp.x+1,temp.y,temp.cost+1));
                }
                else{
                    q.push(a(temp.x+1,temp.y, temp.cost));
                }
                visited[temp.x+1][temp.y] = 1;
            }

        }
        if(temp.x-1 >= 0){
            if(visited[temp.x-1][temp.y] != 1){
                if(mapp[temp.x-1][temp.y]== 1){
                    q.push(a(temp.x-1,temp.y,temp.cost+1));
                }
                else{
                    q.push(a(temp.x-1,temp.y, temp.cost));
                }
                visited[temp.x-1][temp.y] = 1;
            }
        }
        if(temp.y+1 < N){
            if(visited[temp.x][temp.y+1] != 1){
                if(mapp[temp.x][temp.y+1]== 1){
                    q.push(a(temp.x,temp.y+1,temp.cost+1));
                }
                else{
                    q.push(a(temp.x,temp.y+1,temp.cost));
                }
                visited[temp.x][temp.y+1] = 1;
            }

        }
        if(temp.y-1 >= 0 ){
            if(visited[temp.x][temp.y-1] != 1){
                if(mapp[temp.x][temp.y-1]== 1){
                    q.push(a(temp.x,temp.y-1,temp.cost+1));
                }
                else{
                    q.push(a(temp.x,temp.y-1,temp.cost));
                }
                visited[temp.x][temp.y-1] = 1;
            }
        }
    }

    return 0;
}