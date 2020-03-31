#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
void findSolution(vector<int> result, int M, int count){
    for(int i = 0 ; i<N ; i++){
        result.push_back(i+1);
        count++;
        if(count == M){
            for(int j = 0; j< M ; j++){
                cout << result[j] << " ";
            }
            cout << "\n";
        }
        else{
            findSolution(result,M,count);
        }        
        count--;
        result.pop_back();
    }
}

int main(){
    int M;
    cin >> N >> M;
    vector<int> per;
    vector<int> result;
    findSolution(result,M,0);

    return 0;
}