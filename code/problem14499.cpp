#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int N, M, x, y, K, temp;
int mapp[20][20];
deque<int> verti;
deque<int> hori;
deque<int> where;

int main(){
    
    cin >> N >> M >> x >> y >> K;
    
    for(int i = 0; i<4; i++){
        verti.push_back(0);
    }
    for(int i = 0 ; i<3 ; i++){
        hori.push_back(0);
    }
    for(int i = 0; i <N ; i++){
        for(int j = 0; j<M; j++){
            cin >> mapp[i][j];
        }
    }
    for(int i = 0; i<K; i++){
        cin >> temp;
        where.push_back(temp);
    }
    for(int i = 0; i<K; i++){
        //cout <<"where:"<< where.front() << " " << x << " " << y << endl;
        /*
        cout << "check" <<i<< endl;
        for(int j = 0 ; j<3 ; j++){
            cout << hori[j] << " ";
        }
        cout << endl;
        for(int j = 0; j < 4; j++){
            cout << verti[j] << " ";
        }
        cout << endl;*/
        if(where.front() == 1){
            if(y < (M-1)){
                y = y+1;
            }
            else{
                where.pop_front();
                continue;
            }
            temp = hori.front();
            hori.pop_front();
            hori.push_back(verti.back());
            verti.pop_back();
            verti.push_back(temp);
            verti[1] = hori[1];
        }
        else if(where.front() == 2){
            if(y > 0){
                y = y-1;
            }
            else{
                where.pop_front();
                continue;
            }
            temp = hori.back();
            hori.pop_back();
            hori.push_front(verti.back());
            verti.pop_back();
            verti.push_back(temp);
            verti[1] = hori[1];
        }
        else if(where.front() == 3){
            if(x > 0){
                x = x-1;
            }
            else{
                where.pop_front();
                continue;
            }
            temp = verti.back();
            verti.pop_back();
            verti.push_front(temp);
            hori[1] = verti[1];
        }
        else if(where.front() == 4){
            if(x < (N-1)){
                x = x+1;
            }
            else{
                where.pop_front();
                continue;
            }
            temp = verti.front();
            verti.pop_front();
            verti.push_back(temp);
            hori[1] = verti[1];
        }
        where.pop_front();/*
        cout << "check" <<i<< endl;
        for(int j = 0 ; j<3 ; j++){
            cout << hori[j] << " ";
        }
        cout << endl;
        for(int j = 0; j < 4; j++){
            cout << verti[j] << " ";
        }
        cout << endl;*/
        if(mapp[x][y] == 0){
            mapp[x][y] = verti[1];
        }
        else{
            //cout << "Why?"<<hori[1] << " " << verti[1] << " "<<mapp[x][y]  << endl;
            verti[1] = mapp[x][y];
            /*for(int i = 0; i<4; i++){
                cout << verti[i] << " ";
            }
            cout << endl;
*/
            hori[1] = mapp[x][y];
            mapp[x][y] = 0;
 /*           for(int i = 0; i<3; i++){
                cout << hori[i] << " ";
            }
            cout << endl;*/
        }
        cout << verti[3] << endl;
    }
    return 0;
}