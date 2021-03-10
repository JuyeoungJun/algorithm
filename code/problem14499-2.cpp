#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

int N,M,x,y,K;
int board[21][21];
//deque<int> inst;

struct dice{
    int a;
    int b;
    int left;
    int right;
    deque<int> middle;
};

dice d;

int move(int dir){
    //동
    if(dir == 1){
        if((d.b+1) >= M){
            return -1;
        }
        else{
            d.b+=1;
            //swap(d.middle[1],d.right);
            swap(d.left,d.middle[3]);
            swap(d.middle[1],d.right);
            swap(d.right,d.left);

        }
    }
    //서
    else if(dir == 2){
        if((d.b-1) < 0){
            return -1;
        }
        else{
            d.b -= 1;
            //swap(d.middle[1],d.left);
            swap(d.right,d.middle[3]);
            swap(d.middle[1],d.left);
            swap(d.right,d.left);
        }
    }
    //북
    else if(dir == 3){
        if((d.a-1) < 0 ){
            return -1;
        }
        else{
            d.a-=1;
            d.middle.push_front(d.middle.back());
            d.middle.pop_back();
        }
    }
    //남
    else if(dir == 4){
        if((d.a+1) >= N){
            return -1;
        }
        else{
            d.a+=1;
            d.middle.push_back(d.middle.front());
            d.middle.pop_front();
        }
    }
    if(board[d.a][d.b] == 0){
        board[d.a][d.b] = d.middle[1];
    }
    else{
        d.middle[1] = board[d.a][d.b];
        board[d.a][d.b] = 0;
    }
    return d.middle[3];
}

int main(){
    cin >> N >> M >> x >> y >> K;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M ; j++){
            cin >> board[i][j];
        }
    }

    d.a = x;
    d.b = y;
    d.left = 0;
    d.right = 0;
    for(int i = 0; i < 4; i++){
        d.middle.push_back(0);
    }

    int inst;

    for(int i = 0; i<K; i++){
        cin >> inst;
        int tt = move(inst);
        if(tt != -1){
            cout << tt << endl;
        }

    }


    return 0;
}