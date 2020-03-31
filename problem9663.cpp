#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int result = 0;
int N;
vector<pair<int,int> > position;
bool checkHorse(int depth, int k){
    if(depth == 0) return true;
    for(int i = 0; i<depth ; i++){
        if(position[i].second == k){
            return false;
        }
        if(abs(depth-position[i].first) == abs(k-position[i].second)){
            return false;
        }
    }
    return true;
}

void findMap(int depth){
    if(depth == N-1){
        for(int i = 0; i<N; i++){
            if(checkHorse(depth,i) == true){
                result++;
            }
        }
        return;
    }
    for(int i = 0; i<N ; i++){
        if(checkHorse(depth,i) == true){
            position.push_back(make_pair(depth,i));
            findMap(depth+1);
            position.pop_back();
        }
    }
}

int main(){
    vector<pair<int,int> > position;
    cin >> N;
    if(N == 1){
        cout << 1;
        return 0;
    }
    findMap(0);
    cout << result;
    return 0;
}