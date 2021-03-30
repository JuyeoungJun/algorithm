/*
    set을 이용한 풀이
*/
#include <iostream>
#include <algorithm>
#include <deque>
#include <set>

using namespace std;

int N, M;

struct stuff{
    set<int> heavy;
    set<int> light;
};

stuff stuffs[101];

int main(){
    cin >> N;
    cin >> M;
    int a,b;
    for(int i = 0; i<M; i++){
        cin >> a >> b;
        stuffs[a].light.insert(b);
        stuffs[b].heavy.insert(a);
    }

    for(int i = 1; i<=N ; i++){
        for(auto iter = stuffs[i].heavy.begin(); iter != stuffs[i].heavy.end(); iter++){
            stuffs[*iter].light.insert(stuffs[i].light.begin(),stuffs[i].light.end());
        }
        for(auto iter = stuffs[i].light.begin(); iter != stuffs[i].light.end(); iter++){
            stuffs[*iter].heavy.insert(stuffs[i].heavy.begin(),stuffs[i].heavy.end());
        }
    }

    for(int i = 1; i<=N; i++){
        cout << N-stuffs[i].heavy.size()-stuffs[i].light.size()-1 << endl;
    }

    return 0;
}