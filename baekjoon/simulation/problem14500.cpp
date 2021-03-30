#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N,M;
int mapp[500][500];
deque<deque<pair<int,int> > > techno;
deque<pair<int,int> > direction;
int rresult = 0;
int check_map[500][500];

int check_hori(int x, int y, int s){
    int result = 0;
    result = s;
    if(y + 3 < M){
        result = max(result,s+mapp[x][y+3]);
    }
    if(x - 1 >= 0){
        for(int i = 0 ; i<3 ; i++){
            result = max(result, s+mapp[x-1][y+i]);
        }
    }
    if(x + 1 < N){
        for(int i = 0 ; i<3 ; i++){
            result = max(result, s+mapp[x+1][y+i]);
        }
    }
    return result;
}

int check_verti(int x,int y,int s){
    int result = 0;
    result = s;
    if(x + 3 < N){
        result = max(result,s+mapp[x+3][y]);
    }
    if(y - 1 >= 0){
        for(int i = 0 ; i<3 ; i++){
            result = max(result, s+mapp[x+i][y-1]);
        }
    }
    if(y + 1 < M){
        for(int i = 0 ; i<3 ; i++){
            result = max(result, s+mapp[x+i][y+1]);
        }
    }
    return result;
}

int check_square(int x,int y){
    int result = 0;
    result += mapp[x][y];
    result += mapp[x+1][y];
    result += mapp[x][y+1];
    result += mapp[x+1][y+1];
    return result;
}

int check_zig(int x,int y){
    int result = 0;
    
    result += mapp[x][y];
    int temp = result;
    if(x+2 < N){
        temp += mapp[x+1][y];
        if(y+1 < M){
           
            temp += mapp[x+1][y+1];
            temp += mapp[x+2][y+1];
            result = max(result,temp);
            temp -= mapp[x+1][y+1];
            temp -= mapp[x+2][y+1];
        }

        if(y-1 >= 0){
           
            temp += mapp[x+1][y-1];
            temp += mapp[x+2][y-1];
            result = max(result,temp);
            temp -= mapp[x+1][y-1];
            temp -= mapp[x+2][y-1];
        }
        temp-=mapp[x+1][y];
    }
    if(y+2<M){
        
        temp += mapp[x][y+1];
        if(x+1 < N){
            
            temp += mapp[x+1][y+1];
            temp += mapp[x+1][y+2];
            result = max(result,temp);
            temp -= mapp[x+1][y+1];
            temp -= mapp[x+1][y+2];
        }
        if(x-1 >= 0){
           
            temp += mapp[x-1][y+1];
            temp += mapp[x-1][y+2];
            result = max(result,temp);
            temp += mapp[x-1][y+1];
            temp += mapp[x-1][y+2];
        }
        temp -= mapp[x][y+1];
    }
    return result;
    
}

int main(){
    cin >> N >> M;
    direction.push_back(make_pair(0,1));
    direction.push_back(make_pair(1,0));
    direction.push_back(make_pair(-1,0));
    direction.push_back(make_pair(0,-1));
    for(int i = 0; i<N; i++){
        for(int j = 0 ; j<M; j++){
            cin >> mapp[i][j];
            check_map[i][j] = 0;
        }
    }
    for(int i = 0; i<N ; i++){
        for(int j = 0; j<M; j++){
            if((j+2) < M){
                rresult = max(rresult,check_hori(i,j,mapp[i][j]+mapp[i][j+1]+mapp[i][j+2]));
            }
            if((i+2) < N){
                rresult = max(rresult,check_verti(i,j,mapp[i][j]+mapp[i+1][j]+mapp[i+2][j]));
            }
            if((i+1) < N && (j+1) < M){
                rresult = max(rresult,check_square(i,j));
            }
            rresult = max(rresult,check_zig(i,j));
        }
    }
    cout << rresult << endl;
    return 0;
}