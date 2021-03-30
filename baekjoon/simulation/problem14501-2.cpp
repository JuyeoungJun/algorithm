#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N;
deque<int> T;
deque<int> P;
deque<int> result;
int answer = 0;

int sol(int now,int money){
    int temp = 0;

    answer = max(answer,money);

    for(int i = now; i<T.size(); i++){
        if((T[i]+i) <= N){
            sol(i+T[i],money+P[i]);
        }
    }
    return 0;
}

int main(){
    cin >> N;
    
    for(int i = 0; i<N ; i++){
        int t,p;
        cin >> t >> p;
        T.push_back(t);
        P.push_back(p);
    }

    sol(0,0);
    cout << answer << endl;
    return 0;
}