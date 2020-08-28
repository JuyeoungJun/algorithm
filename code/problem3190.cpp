#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

int main(){
    int N,K,L;
    cin >> N;
    int mapp[N][N];
    cin >> K;
    int tempa,tempb;
    for(int i = 0; i<N ; i++){
        for(int j = 0; j<N ; j++){
            mapp[i][j] = 0;
        }
    }
    for(int i = 0; i<K; i++){
        cin >> tempa >> tempb;
        mapp[tempa-1][tempb-1] = 1;
    }
    /*
    for(int i = 0; i<N ; i++){
        for(int j = 0; j<N ; j++){
            cout << mapp[i][j] << " ";
        }
        cout << endl;
    }
    */
    cin >> L;
    deque<pair<int,int> > change;
    char tempc;
    for(int i = 0; i<L; i++){
        cin >> tempa >> tempc;
        if(tempc == 'D'){
            change.push_back(make_pair(tempa,0));
        }
        else if(tempc == 'L'){
            change.push_back(make_pair(tempa,1));
        }
    }
    deque<pair<int, int> > snake;
    snake.push_back(make_pair(0,0));
    int time = 0;
    pair<int, int> direction;
    direction = make_pair(0,1);
    while(1){
        /*
        cout << "time: " << time << endl;
        cout << "head: " << snake.front().first << " " << snake.front().second << endl;
        cout << "len: " << snake.size() << endl;
        */
        if(change.front().first == time){
            if(change.front().second == 0){
                if(direction.second == 1){
                    direction.first = 1;
                    direction.second = 0;
                }
                else if(direction.first == 1){
                    direction.first = 0;
                    direction.second = -1;
                }
                else if(direction.second == -1){
                    direction.first = -1;
                    direction.second = 0;
                }
                else if(direction.first == -1){
                    direction.first = 0;
                    direction.second = 1;
                }
            }
            else{
                if(direction.second == 1){
                    direction.first = -1;
                    direction.second = 0;
                }
                else if(direction.first == 1){
                    direction.first = 0;
                    direction.second = 1;
                }
                else if(direction.second == -1){
                    direction.first = 1;
                    direction.second = 0;
                }
                else if(direction.first == -1){
                    direction.first = 0;
                    direction.second = -1;
                }
            }
            change.pop_front();
        }
        if(snake.front().first+direction.first == N || snake.front().second+direction.second == N || snake.front().first+direction.first == -1 || snake.front().second+direction.second == -1 ){
            time ++;
            break;
        }
        int flag = 0;
        for(int i = 0; i<snake.size(); i++){
            if(snake[i].first == snake.front().first+direction.first && snake[i].second == snake.front().second+direction.second){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            time ++;
            break;
        }
        snake.push_front(make_pair(snake.front().first+direction.first,snake.front().second+direction.second));
        if(mapp[snake.front().first][snake.front().second] != 1){
            snake.pop_back();
        }
        else{
            mapp[snake.front().first][snake.front().second] = 0;
        }
        time ++;
    }
    cout << time << endl;
    return 0;
}