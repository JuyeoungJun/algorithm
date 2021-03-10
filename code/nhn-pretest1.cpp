#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

int N;
int board[11][11];
int count;
deque<int> answer;

int sol(int a, int b){
    int result = 0;

    deque<pair<int,int> > q;
    q.push_back(make_pair(a,b));

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;

        if( (i+1) < N && board[i+1][j] == 1){
            q.push_back(make_pair(i+1,j));
            board[i+1][j] = 0;
            result++;
        }
        if( (i-1) >= 0 && board[i-1][j] == 1){
            q.push_back(make_pair(i-1,j));
            board[i-1][j] = 0;
            result++;
        }
        if( (j+1) < N && board[i][j+1] == 1){
            q.push_back(make_pair(i,j+1));
            board[i][j+1] = 0;
            result++;
        }
        if( (j-1) >= 0 && board[i][j-1] == 1){
            q.push_back(make_pair(i,j-1));
            board[i][j-1] = 0;
            result++;
        }


        q.pop_front();

    }
    return result;
}

int main(){
    int count = 0;
    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(board[i][j] == 1){
                int temp = sol(i,j);
                count++;
                answer.push_back(temp);
            }
        }
    }

    sort(answer.begin(),answer.end());
    cout << count << endl;
    for(int i = 0; i<answer.size(); i++){
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}

