#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int S[21][21];
int N;
//vector<int> team;
int team[21];
int mi = 987654321;
int check[21];

int make_team(int many,int who){
    if(many == N/2){
        
        int temp = 0;
        int other_temp = 0;
        /*
        int Sum = 0;
        int flag = 0;
        vector<int> other_team;
        for(int i = 0; i<N;i++){
            flag = 0;
            for(int j = 0; j<many; j++){
                if(team[j] == i){
                    flag = 1;
                }
            }
            if(flag == 0){
                other_team.push_back(i);
            }
        }
        for(int i = 0; i<many;i++){
            for(int j = 0; j<many;j++){
                temp += S[team[i]][team[j]];
                other_temp += S[other_team[i]][other_team[j]];
            }
        }
        mi = min(mi,abs(other_temp-temp));
        return mi;*/
        for(int i = 0 ;i < N ; i++){
            for(int j = 0; j< N; j++){
                if(team[i] == team[j]){
                    if(team[i] == 1){
                        temp += S[i][j];
                    }
                    else{
                        other_temp += S[i][j];
                    }
                }
            }
        }
        mi = min(mi,abs(other_temp-temp));
        return mi;       
    }
    
    for(int i = who; i < N ; i++){
        if(check[i] == 0){
            //team.push_back(i);
            team[i] = 1;
            check[i] = 1;
            make_team(many+1,i);
            //team.pop_back();
            check[i] = 0;
            team[i] = 0;
        }

    }
    return mi;
}

int main(){
    cin >> N;
    int result;
    for(int i = 0; i<N ; i++){
        for(int j = 0; j<N; j++){
            cin >> S[i][j];
        }
    }
    for(int i = 0; i<21 ; i++){
        check[i] = 0;
    }
    /*
    for(int i = 0; i<N ; i++){
        for(int j = 0; j<N; j++){
            cout << S[i][j] << " ";
        }
        cout << endl;
    }*/
    make_team(0,0);
    cout << mi << endl;
    return 0;
}