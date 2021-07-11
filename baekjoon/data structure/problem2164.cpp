#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main(){
    int N;
    cin >> N;

    deque<int> result;

    for(int i = 0; i<N; i++){
        result.push_back(i+1);
    }

    while(1){
        if(result.size() == 1) {
            break;
        }

        result.pop_front();
        int second = result.front();
        result.pop_front();
        result.push_back(second);
    }

    cout << result.front() << endl;
    return 0;
}