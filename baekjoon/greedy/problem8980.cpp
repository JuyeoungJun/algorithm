#include <iostream>
#include <deque>
#include <algorithm>
#include <queue>

using namespace std;

struct city{
    int start;
    int end;
    int box;
};

struct compare{
    bool operator()(city &a, city &b){
        if(a.end == b.end){
            return a.start > b.start;
        }
        return a.end > b.end;
    }
};

int N, C;
priority_queue<city, vector<city>, compare > cities;

int main(){
    cin >> N >> C;

    int M;
    cin >> M;

    int a,b,c;

    for(int i = 0; i<M; i++){
        cin >> a >> b >> c;
        city temp;
        temp.start = a;
        temp.end = b;
        temp.box = c;
        cities.push(temp);
    }
    
    int answer = 0;
    deque<int> howmuch;

    for(int i = 0; i<N; i++){
        howmuch.push_back(0);
    }

    while(!cities.empty()){
        int start = cities.top().start;
        int end = cities.top().end;
        int box = cities.top().box;
        cities.pop();
        int flag = 0;
        for(int i = start; i<end; i++){
            if(howmuch[i] + box > C){
                box = C-howmuch[i];
            }
        }
        answer += box;
        for(int i = start; i<end; i++){
            howmuch[i] += box;
        }
    }
    cout << answer << endl;
    return 0;
}