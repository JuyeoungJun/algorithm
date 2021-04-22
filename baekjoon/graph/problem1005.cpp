#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, K, T;

struct cities{
    int useTime;
    deque<int> next;
    int prevCnt;
};

deque<int> costTime;
deque<cities> city;

int getSolve(deque<int> start){
    queue<int> q;
    for(int i = 0; i<start.size(); i++){
        
        q.push(start[i]);
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int i = 0; i<city[now].next.size(); i++){
            if(costTime[city[now].next[i]] + city[now].useTime > city[city[now].next[i]].useTime){
                city[city[now].next[i]].useTime = costTime[city[now].next[i]] + city[now].useTime;
            }
            city[city[now].next[i]].prevCnt --;
            if(city[city[now].next[i]].prevCnt == 0){
                q.push(city[now].next[i]);
            }
        }
    }

    return 0;
}


int main(){
    cin >> T;

    for(int t = 0; t<T; t++){
        int temp;
        city.clear();
        costTime.clear();
        cin >> N >> K;

        for(int i = 0; i<N; i++){
            cin >> temp;
            cities c;
            c.next.clear();
            c.prevCnt = 0;
            c.useTime = temp;
            city.push_back(c);
            costTime.push_back(temp);
        }

        int tempb;

        for(int i = 0; i<K; i++){
            cin >> temp >> tempb;
            city[temp-1].next.push_back(tempb-1);
            city[tempb-1].prevCnt++;
        }
        int D;
        cin >> D;

        // int start = 0;
        deque<int> start;
        for(int i = 0; i<N; i++){
            if(city[i].prevCnt == 0){
                start.push_back(i);
            }
        }
        getSolve(start);

        cout << city[D-1].useTime << endl;

    }

    return 0;
}
