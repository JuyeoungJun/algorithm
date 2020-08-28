#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

long long ca[10000001];
int n;
int main(){
    ca[0] = 0;
    ca[1] = 1;
    ca[2] = 2;
    ca[3] = 4;
    int T;
    cin >> T;
    for(int j = 0; j<T; j++){
        cin >> n;
        for(int i = 4; i<=n; i++){
            ca[i] = ca[i-1]%1000000009+ ca[i-2]%1000000009 + ca[i-3]%1000000009;
            ca[i] %= 1000000009;
        }
        cout << ca[n] << endl;
    }

    return 0;
}