#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cmath>

using namespace std;

int mapp[17][17];
int N;
int result = 0;
pair<int, int> where;

int find_sol(int direction){
    //cout << "where : " << where.first << " " << where.second << endl;
    if(where.first == N-1 && where.second == N-1){
        result ++;
        return 0;
    }

    if(direction == 0){
        if(where.second+1 < N && mapp[where.first][where.second+1] != 1){
            where.second = where.second+1;
            find_sol(0);
            where.second = where.second-1;
        }
        if(where.first+1 < N && where.second+1 < N && mapp[where.first+1][where.second+1] != 1 && mapp[where.first][where.second+1] != 1 && mapp[where.first+1][where.second] != 1){
            where.first +=1;
            where.second +=1;
            find_sol(1);
            where.first -= 1;
            where.second -= 1;
        }
    }
    else if(direction == 1){
        if(where.second+1 < N && mapp[where.first][where.second+1] != 1){
            where.second = where.second+1;
            find_sol(0);
            where.second = where.second-1;
        }
        if(where.first+1 < N && where.second+1 < N && mapp[where.first+1][where.second+1] != 1 && mapp[where.first][where.second+1] != 1 && mapp[where.first+1][where.second] != 1){
            where.first +=1;
            where.second +=1;
            find_sol(1);
            where.first -= 1;
            where.second -= 1;
        }
        if(where.first+1 < N && mapp[where.first+1][where.second] != 1){
            where.first += 1;
            find_sol(2);
            where.first -= 1;
        }
    }
    else if(direction == 2){
        if(where.first+1 < N && where.second+1 < N && mapp[where.first+1][where.second+1] != 1 && mapp[where.first][where.second+1] != 1 && mapp[where.first+1][where.second] != 1){
            where.first +=1;
            where.second +=1;
            find_sol(1);
            where.first -= 1;
            where.second -= 1;
        }
        if(where.first+1 < N && mapp[where.first+1][where.second] != 1){
            where.first += 1;
            find_sol(2);
            where.first -= 1;
        }
    }

    return 0;
}

int main(){
    cin >> N;
    for(int i = 0; i<N ; i++){
        for(int j = 0; j<N ; j++){
            cin >> mapp[i][j];
        }
    }

    where = make_pair(0,1);

    find_sol(0);
    
    cout << result << endl;
    return 0;
}