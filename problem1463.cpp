#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int memory[1000000];
/*
int findSol(int N){
    int temp;
    int result;
    vector <int> wh;
    wh.push_back(N-1);
    if(N%3 == 0){
        wh.push_back(N/3);
    }
    if(N%2 == 0){
        wh.push_back(N/2);
    }
    result = 987654321;
    for(int i = 0; i<wh.size(); i++){
        if(memory[wh[i]] != 987654321){
            temp = memory[wh[i]];
        }
        else{
            temp = findSol(wh[i]);
        }
        result = min(result,temp);
    }
    result = result + 1;
    return result;
}
*/
int main(){
    int N,fin;
    cin >> N;
    for(int i = 0; i<1000000; i++){
        memory[i] = 987654321;
    }
    memory[1] = 0;
    memory[2] = 1;
    memory[3] = 1;
    for(int i = 4 ; i<=N ; i++){
        memory[i] = memory[i-1] + 1;
        if(i % 3 == 0){
            memory[i] = min(memory[i],memory[i/3]+1);
        }
        if(i % 2 == 0){
            memory[i] = min(memory[i],memory[i/2]+1);
        }
    }
    cout << memory[N];
    return 0;
}

