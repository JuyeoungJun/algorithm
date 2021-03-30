#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;
int N;
int player[21][21];
int all_sum = 0;
int check[21];
deque<int> pl;
int answer = 987654321;

int cal(){
    int result = 0;
    for(int i = 0; i<pl.size()-1; i++){
        for(int j = i+1; j<pl.size(); j++){
            result += player[pl[i]][pl[j]];
            result += player[pl[j]][pl[i]];
        }
    }
    deque<int> other;
    for(int i = 0; i<N; i++){
        if(find(pl.begin(),pl.end(),i) == pl.end()){
            other.push_back(i);
        }
    }
    int other_result = 0;
    for(int i = 0; i<other.size()-1; i++){
        for(int j = i+1; j<other.size(); j++){
            other_result += player[other[i]][other[j]];
            other_result += player[other[j]][other[i]];
        }
    }
    result = abs(result-other_result);
    return result;
}

int sol(int depth, int who){
    if(depth == N/2){
        int temp = cal();
        answer = min(answer,temp);
        return 0;
    }

    for(int i = who ; i<N; i++){
        if(check[i] == 0){
            pl.push_back(i);
            sol(depth+1,i+1);
            pl.pop_back();
        }
    }

    return 0;
}

int main(){
    cin >> N;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> player[i][j];
        }
        check[i] = 0;
    }
    sol(0,0);

    cout << answer << endl;
    return 0;
}