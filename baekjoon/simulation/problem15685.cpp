#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N;
int x,y,d,g;
int map[101][101];
deque<pair<int,int> > go;

int check_square(int a, int b){
    int result = 0;
    if(map[a+1][b] == 1){
        result += 1;
    }
    if(map[a][b+1] == 1){
        result += 1;
    }
    if(map[a+1][b+1] == 1){
        result += 1;
    }

    if(result == 3){
        return 1;
    }
    else{
        return -1;
    }
}
int make_dragon(int age, deque<int> direct){
    if(age == g){
        return 1;
    }
    int l = direct.size();
    for(int i = l-1; i>=0; i--){
        if(direct[i] == 0){
            y += go[1].first;
            x += go[1].second;
            direct.push_back(1);
        }
        else if(direct[i] == 1){
            y += go[2].first;
            x += go[2].second;
            direct.push_back(2);
        }
        else if(direct[i] == 2){
            y+=go[3].first;
            x+=go[3].second;
            direct.push_back(3);
        }
        else{
            y+=go[0].first;
            x+=go[0].second;
            direct.push_back(0);
        }
        map[y][x] = 1;
    }
    make_dragon(age+1,direct);
    return 0;
}

int main(){
    int result = 0;
    cin >> N;
    go.push_back(make_pair(0,1));
    go.push_back(make_pair(-1,0));
    go.push_back(make_pair(0,-1));
    go.push_back(make_pair(1,0));
    for(int i = 0; i<N; i++){
        cin >> x >> y >> d >> g;
        deque<int> direct;
        direct.push_back(d);
        map[y][x] = 1;
        map[y+go[d].first][x+go[d].second] = 1;
        y += go[d].first;
        x += go[d].second;
        make_dragon(0,direct);
    }
    for(int i = 0; i<100; i++){
        for(int j = 0; j<100; j++){
            if(map[i][j] == 1){
                if(check_square(i,j) == 1){
                    result += 1;
                }
            }
        }
    }
    cout << result << endl;
    return 0;
}