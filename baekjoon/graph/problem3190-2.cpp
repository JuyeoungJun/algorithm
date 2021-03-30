#include <iostream>
#include <deque>
#include <algorithm>
#include <queue>
#include <string>
#include <map>

using namespace std;

int N,K,L;
int board[101][101];
int dir[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

struct snake{
    int direction;
    deque<pair<int,int> > body;
};

snake s;

bool meet(int a, int b){
        if( a >= N || a<0){
            return false;
        }
        if(b >= N || b <0){
            return false;
        }
        
        pair<int,int> cmp = make_pair(a,b);
        if(find(s.body.begin(),s.body.end(),cmp) != s.body.end()){
            return false;
        }
        return true;
}
int main(){
    cin >> N ;
    cin >> K;
    for(int i = 0; i<K; i++){
        int a,b;
        cin >> a >> b;
        board[a-1][b-1] = 1;
    }

    s.direction = 0;
    s.body.push_back(make_pair(0,0));

    cin >> L;

    map<int, string> m;

    for(int i = 0 ; i<L ; i++){
        int a;
        string b;
        cin >> a >> b;
        m[a] = b;
    }
    int answer = 0;
    for(;; answer++){
        /*
        cout << "==================" << endl;
        cout << answer << endl;
        //cout << s.body.size() << endl;
        for(int i = 0 ;i<s.body.size(); i++){
            cout << s.body[i].first << " " << s.body[i].second << " ||  ";
        }
        cout << endl;*/
        if(m[answer] == "D"){
            s.direction += 1;
            s.direction %= 4;
        }
        else if(m[answer] == "L"){
            s.direction -= 1;
            if(s.direction == -1) s.direction = 3;            
        }

        int a,b;
        a = s.body.front().first + dir[s.direction][0];
        b = s.body.front().second + dir[s.direction][1];
        if(!meet(a,b)){
            break;
        }
        s.body.push_front(make_pair(a,b));
        if(board[a][b] == 0){
            s.body.pop_back();
        }
        else{
            board[a][b] = 0;
        }
    }
    cout << answer+1 << endl;
    return 0;
}