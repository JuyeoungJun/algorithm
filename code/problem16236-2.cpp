#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

struct shark{
    int a;
    int b;
    int siz;
    int eat;
};

shark s;
int N;
int board[21][21];

bool cmp(deque<int> a, deque<int> b){
    if(a[2] != b[2]) return a[2] < b[2];
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

bool cmp2(deque<int> a, deque<int> b){
    return a[2] < b[2];
}
int find_min(){
    deque<deque<int> > q;
    int check[21][21];
    for(int i = 0; i<21; i++){
        for(int j = 0; j<21; j++){
            check[i][j] = 0;
        }
    }
    deque<int> temp;
    temp.push_back(s.a);
    temp.push_back(s.b);
    temp.push_back(0);
    q.push_back(temp);
    check[s.a][s.b] = 1;
    while(!q.empty()){
        sort(q.begin(),q.end(),cmp);
        //sort(q.begin(),q.end(),cmp2);
        int x = q.front()[0];
        int y = q.front()[1];
        if(board[x][y] > 0 && board[x][y] < s.siz){
                s.a = x;
                s.b = y;
                s.eat++;
                if(s.eat == s.siz){
                    s.siz++;
                    s.eat = 0;
                }
                board[x][y] = 0;
                return q.front()[2];
        }
        //cout << x << " " << y << " " << tim.front() <<endl;
        //위
        if(x-1 >= 0 && check[x-1][y] == 0){
            if(board[x-1][y] >= 0 && board[x-1][y] <= s.siz){
                deque<int> tt;
                tt.push_back(x-1);
                tt.push_back(y);
                tt.push_back(q.front()[2]+1);
                q.push_back(tt);
                check[x-1][y] = 1;
            }
        }
        //왼
        if(y-1>=0 && check[x][y-1] == 0){
            if(board[x][y-1] >= 0 && board[x][y-1] <= s.siz){
                deque<int> tt;
                tt.push_back(x);
                tt.push_back(y-1);
                tt.push_back(q.front()[2]+1);
                q.push_back(tt);
                check[x][y-1] = 1;
            }
        }
        //오
        if(y+1<N && check[x][y+1] == 0){
            if(board[x][y+1] >= 0 && board[x][y+1] <= s.siz){
                deque<int> tt;
                tt.push_back(x);
                tt.push_back(y+1);
                tt.push_back(q.front()[2]+1);
                q.push_back(tt);
                check[x][y+1] = 1;
            }
        }
        //아래
        if(x+1 < N && check[x+1][y] == 0){
            if(board[x+1][y] >= 0 && board[x+1][y] <= s.siz){
                deque<int> tt;
                tt.push_back(x+1);
                tt.push_back(y);
                tt.push_back(q.front()[2]+1);
                q.push_back(tt);
                check[x+1][y] = 1;
            }
        }
        q.pop_front();
        
    }
    return 0;
}

int main(){
    cin >> N;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> board[i][j];
            if(board[i][j] == 9){
                s.a = i;
                s.b = j;
                s.siz = 2;
                s.eat = 0;
                board[i][j] = 0;
            }
        }
    }

    int answer = 0;
    while(1){
        
        int temp = find_min();
        if(temp == 0) break;
        answer += temp;
        

    }
    cout << answer << endl;
    return 0;
}