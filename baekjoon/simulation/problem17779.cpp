#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
int N;
int board[21][21];
int answer = 987654321;
int s = 0;
int cal(int x, int y, int d_one,int d_two){
    cout << "======================" << endl;
    cout << x << " " << y << " " << d_one << " " << d_two << endl;
    deque<int> result;
    int temp_map[21][21];
    for(int i = 0; i<5; i++){
        result.push_back(0);
    }

    for(int i = 0; i<N;i++){
        for(int j = 0; j<N; j++){
            temp_map[i][j] = 0;
        }
    }

    for(int r = 0; r<N; r++){
        for(int c = 0; c<N; c++){
            if(temp_map[r][c] == 5) continue;
            if(r<(x+d_one) && c<=y){
                result[0] += board[r][c];
                temp_map[r][c] = 1;
            }
            else if(r<=(x+d_two) && y<c){
                result[1] += board[r][c];
                temp_map[r][c] = 2;
            }
            else if(x+d_one<=r && c<(y-d_one+d_two)){
                result[2] += board[r][c];
                temp_map[r][c] = 3;
            }
            else if(x+d_two<r && (y-d_one+d_two) <= c ){
                result[3] += board[r][c];
                temp_map[r][c] = 4;
            }
            else{
                result[4] += board[r][c];
                temp_map[r][c] = 5;
            }
        }
    }

    for(int i = 0; i<N;i++){
        for(int j = 0; j<N; j++){
            cout << temp_map[i][j] << " ";
        }
        cout << endl;
    }

    return *max_element(result.begin(),result.end())-*min_element(result.begin(),result.end());

}
int sol(){
    for(int i = 0; i<N-2; i++){
        for(int j = 1; j<N-1; j++){
            for(int k = 1; k<N-2 ;k++){
                for(int z = 1; ; z++){
                    if(i+k+z >= N) break;
                    if(j+k >= N) break;
                    if(j-z < 0) break;
                    answer = min(answer,cal(i,j,k,z));
                }
            }

        }
    }
    return 0;
}

int main(){
    cin >> N;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> board[i][j];
            s+= board[i][j];
        }
    }
    
    sol();
    cout << answer << endl;
    return 0;
}