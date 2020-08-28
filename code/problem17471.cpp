#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N;
int people[11];
int result = 987654321;
int sumofpeople = 0;
int map[11][11];

int sol(){

    return 0;
}

int main(){
    cin >> N ;
    for(int i = 0; i<N ; i++){
        cin >> people[i];
        sumofpeople += people[i];
    }

    int n, temp;
    for(int i = 0; i<N ; i++){
        cin >> n;
        for(int j= 0 ; j<n ; j++){
            cin >> temp;
            map[i][temp-1] = 1;
            map[temp-1][i] = 1;
        }
    }

    for(int i = 0 ; i<N ; i++){
        for(int j = 0; j<N; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    
    return 0;
}