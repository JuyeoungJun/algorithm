#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    int B[501];
    vector<int> line;
    vector<int> result;
    for(int i = 0; i<501; i++){
        B[i] = 0;
    }
    int a,b;
    for(int i = 0; i<N ; i++){
        cin >> a >> b;
        B[a] = b; 
    }
    for(int i = 0; i < 501 ; i++){
        if(B[i] != 0){
            line.push_back(B[i]);
        }
    }
    result.push_back(line[0]);
    for(int i = 1; i<line.size();i++){
        if(result.back() > line[i]){
            for(int j = 0; j<result.size();j++){
                if(result[j] > line[i]){
                    result[j] = line[i];
                    break;
                }
            }
        }
        else{
            result.push_back(line[i]);
        }
    }
    cout << N-result.size() << endl;
    //cout << result[0] << " " << result[1] << " " << result[2] << endl;
    return 0;
}