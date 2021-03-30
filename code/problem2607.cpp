/*
    브루드포스
*/
#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <map>

using namespace std;

int main(){
    int alphabet[30] = {0};
    int N;
    int answer = 0;
    cin >> N;
    string first;
    cin >> first;

    for(int i = 0; i<first.size(); i++){
        alphabet[first[i]-'A']++;
    }

    int a = first.size();
    int cmp[30] = {0};
    for(int i = 0; i<N-1; i++){
        string s;
        cin >> s;
        for(int j = 0; j<30; j++){
            cmp[j] = 0;
        }

        for(int j = 0; j<s.size(); j++){
            cmp[s[j]-'A']++;
        }
        int flag = 0;
        int cnt = 0;
        int recnt = 0;
        for(int j = 0; j<30; j++){
            if(alphabet[j] == cmp[j]) continue;
            if(abs(alphabet[j]-cmp[j]) > 1){
                flag = 1;
                break;
            }
            else if(alphabet[j] < cmp[j]) {
                cnt++;
            }
            else if(alphabet[j] > cmp[j]) {
                recnt++;
            }
            if(cnt > 1 || recnt > 1){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            continue;
        }
        answer++;
    }

    cout << answer << endl;
    return 0;
}