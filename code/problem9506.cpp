#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int main(){
    int n;
    deque<int> result;
    int answer;
    while(1){
        cin >> n;
        if(n == -1) break;
        result.clear();
        answer = 0;
        for(int i = 1; i<(n/2)+1; i++){
            if(n%i == 0){
                result.push_back(i);
                answer += i;
            }
        }
        if(answer == n) {
            cout << n << " = ";
            for(int i = 0; i<result.size(); i++){
                cout << result[i] << " ";
                if(i != result.size()-1){
                    cout << "+ ";
                }
                else{
                    cout << endl;
                }
            }
        }
        else{
            cout << n << " is NOT perfect." << endl;
        }
    }
    return 0;
}