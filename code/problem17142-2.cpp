#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N,M;
deque<pair<int,int> > where;
deque<int> wh;
int coun;
int answer = 987654321;
int spread(int board[51][51]){
    int result = 0;
    deque<pair<int,int> > q;
    deque<int> tim;
    int tempboard[51][51];
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            tempboard[i][j] = board[i][j];
        }
    }
    for(int i = 0; i<wh.size(); i++){
        q.push_back(where[wh[i]]);
        tempboard[where[wh[i]].first][where[wh[i]].second] = -1;
        tim.push_back(0);
    }

    int cnt = 0;
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        //위
        /*
        cout << cnt << " "<< tim.front() << endl;
        //cout << a << " " << b << endl;
        
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                cout << tempboard[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;*/
        if(a-1 >= 0){
            if(tempboard[a-1][b] == 0 || tempboard[a-1][b] == 2){
                q.push_back(make_pair(a-1,b));
                if(tempboard[a-1][b] == 0){
                    cnt++;
                }
                tempboard[a-1][b] = -1;
                tim.push_back(tim.front()+1);

                if(cnt == coun){
                    return tim.front()+1;
                }
            }
        }
        //아래
        if(a+1 < N){
            if(tempboard[a+1][b] == 0 || tempboard[a+1][b] == 2){
                q.push_back(make_pair(a+1,b));
                if(tempboard[a+1][b] == 0){
                    cnt++;
                }
                tempboard[a+1][b] = -1;
                tim.push_back(tim.front()+1);
                
                if(cnt == coun){
                    return tim.front()+1;
                }
            
            }
        }
        //오
        if(b+1 < N ){
            if(tempboard[a][b+1] == 0 || tempboard[a][b+1] == 2){
                q.push_back(make_pair(a,b+1));
                if(tempboard[a][b+1] == 0){
                    cnt++;
                }
                tempboard[a][b+1] = -1;
                tim.push_back(tim.front()+1);
                
                if(cnt == coun){
                    return tim.front()+1;
                }
            
            }
        }
        //왼
        if(b-1 >= 0){
            if(tempboard[a][b-1] == 0 || tempboard[a][b-1] == 2){
                q.push_back(make_pair(a,b-1));
                if(tempboard[a][b-1] == 0){
                    cnt++;
                }
                tempboard[a][b-1] = -1;
                tim.push_back(tim.front()+1);
                
                if(cnt == coun){
                    return tim.front()+1;
                }
            }
        }
        tim.pop_front();
        q.pop_front();
    }

    return -1;
}

int make_comb(int board[51][51],int w){
    if(wh.size() == M){
        /*
        for(int i = 0; i<wh.size(); i++){
            cout << wh[i] << " ";
        }
        cout << endl;*/
        int temp = spread(board);
        //cout << temp << endl;
        if(temp != -1){
            answer = min(answer,temp);
        }
        return 0;
    }
    for(int i = w; i<where.size(); i++){
        wh.push_back(i);
        make_comb(board,i+1);
        wh.pop_back();
    }

    return 0;
}

int main(){
    cin >> N >> M;
    int board[51][51];
    coun = 0;
    for(int i = 0 ; i<N; i++){
        for(int j = 0; j<N ; j++){
            cin >> board[i][j];
            if(board[i][j] == 2){
                where.push_back(make_pair(i,j));
            }
            if(board[i][j] == 0){
                coun++;
            }
        }
    }
    if(coun == 0){
        cout << 0 << endl;
        return 0;
    }
    make_comb(board,0);
    if(answer == 987654321){
        answer = -1;
    }
    cout << answer << endl;
    return 0;
}