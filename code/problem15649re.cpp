#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N,M;
vector<int> arr;

int checkRe(vector<int> result,int k){
    for(int i = 0; i<result.size(); i++){
        if(result[i] == k){
            return 0;
        }
    }
    return 1;
}

void findSol(vector<int> result,int depth){
    if(depth == M){
        for(int i = 0 ; i<M ; i++){
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i<arr.size(); i++){
        if(checkRe(result,arr[i]) == 0){
            continue;
        }
        result.push_back(arr[i]);
        findSol(result,depth+1);
        result.pop_back();
    }
}

int main(){
    
    
    vector<int> ind;
    cin >> N >> M;
    for(int i = 0 ; i < N ; i ++){
        arr.push_back(i+1);
    }
    findSol(ind,0);
    return 0;
}