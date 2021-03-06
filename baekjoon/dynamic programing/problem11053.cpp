#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    int val[1001];
    vector<int> result;
    
    cin >> N;
    for(int i = 0; i<N;i++){
        cin >> val[i];
    }
    result.push_back(val[0]);
    for(int i = 1; i<N; i++){
        if(result.back() < val[i]){
            result.push_back(val[i]);
        }
        else{
            for(int j = result.size()-1; j>=0 ; j--){
                if(result[j] >= val[i] && result[j-1] < val[i]){
                    result[j] = val[i];
                    break;
                }
            }
        }
    }
    cout << result.size();
    return 0;
}

