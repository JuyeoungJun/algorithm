#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int mapp[101][101];
int N,L;

int check_hori(int a){
    int where = 0;
    int slope_c[101];
    for(int i = 0; i<101 ; i++){
        slope_c[i] = 0;
    }
    while(1){
        if(where == N-1){
            return 1;
        }
        if(mapp[a][where]+1 == mapp[a][where+1]){
            if(slope_c[where] == 1){
                return 0;
            }
            slope_c[where] = 1;
            for(int i = 1; i<L;i++){
                if(mapp[a][where] != mapp[a][where-i]){
                    return 0;
                }
                else if(slope_c[where-i] == 1){
                    return 0;
                }
            }
            where += 1;
        }
        else if(mapp[a][where]-1 == mapp[a][where+1]){
            slope_c[where+1] = 1;
            for(int i = 1; i<L; i++){
                if(mapp[a][where+1] != mapp[a][where+1+i]){
                    return 0;
                }
                else{
                    slope_c[where+1+i] = 1;
                }
            }
            where+=L;
        }
        else if(abs(mapp[a][where]-mapp[a][where+1])>=2){
            return 0;
        }
        else if(mapp[a][where] == mapp[a][where+1]){
            where += 1;
        }
    }
}

int check_verti(int a){
    int where = 0;
    int slope_c[101];
    for(int i = 0; i<101 ; i++){
        slope_c[i] = 0;
    }
    while(1){
        if(where == N-1){
            return 1;
        }
        if(mapp[where][a]+1 == mapp[where+1][a]){
            if(slope_c[where] == 1){
                return 0;
            }
            slope_c[where] = 1;
            for(int i = 1; i<L;i++){
                if(mapp[where][a] != mapp[where-i][a]){
                    return 0;
                }
                else if(slope_c[where-i] == 1){
                    return 0;
                }
            }
            where += 1;
        }
        else if(mapp[where][a]-1 == mapp[where+1][a]){
            slope_c[where+1] = 1;
            for(int i = 1; i<L; i++){
                if(mapp[where+1][a] != mapp[where+1+i][a]){
                    return 0;
                }
                else{
                    slope_c[where+1+i] = 1;
                }
            }
            where+=L;
        }
        else if(abs(mapp[where][a]-mapp[where+1][a])>=2){
            return 0;
        }
        else if(mapp[where][a] == mapp[where+1][a]){
            where += 1;
        }
    }
}

int main(){
    int result = 0;
    cin >> N >> L;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> mapp[i][j];
        }
    }

    for(int i = 0; i<N ; i++){
        //cout << "i: " << i << endl;
        result += check_hori(i);
        //cout << "hori: "<< " result: " << result << endl;
        result += check_verti(i);
        //cout << "verti: "<< " result: " << result << endl;
    }
    cout << result << endl;
    return 0;
}