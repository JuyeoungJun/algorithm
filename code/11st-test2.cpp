#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <vector>

using namespace std;

vector<int> solution(vector<string> &S) {
    vector<int> answer;
    for(int i = 0; i<S.size()-1; i++){
        for(int j = i+1; j<S.size(); j++){
            int l = min(S[i].size(),S[j].size());
            for(int k = 0; k<l; k++){
                if(S[i][k] == S[j][k]){
                    answer.push_back(i);
                    answer.push_back(j);
                    answer.push_back(k);
                    return answer;
                }
            }
        }
    }

    return answer;
}

int main(){
    vector<string> S;
    S.push_back("bdafg");
    S.push_back("ceagi");
    //S.push_back("rg");
    //S.push_back("fgtd");
    vector<int> answer;
    answer = solution(S);

    for(int i = 0; i<answer.size(); i++){
        cout << answer[i] << " ";
    }
    return 0;
}