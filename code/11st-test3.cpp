#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    int answer = 0;
    sort(A.begin(),A.end());
    for(int i = 0; i<A.size(); i++){
        if(A[i] == (i+1)) continue;
        else{
            answer += abs(A[i]-(i+1));
        }

    }
    return answer;
}

int main(){
    vector<int> A;
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);

    int answer = solution(A);

    cout << answer;

    return 0;
}