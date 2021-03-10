#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int solution(string &S){
    int answer = 0;

    int cnt = 0;
    for(int i = 0; i<S.size(); i++){
        
        if(S[i] != 'a'){
            if(cnt == 1){
                answer += 1;
            }
            else if(cnt == 0){
                answer += 2;
            }
            cnt = 0;
        }
        else if(S[i] == 'a'){
            if(cnt == 2 ) return -1;
            cnt++;
        }
    }
    answer += 2-cnt;

    return answer;
}

int main(){
    string S;
    cin >> S;
    string St = "baaa";
    int a = solution(S);
    cout << a << endl;
    return 0;

}