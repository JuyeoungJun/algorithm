#include <iostream>
#include <algorithm>
#include <deque>
#include <map>
#include <set>

using namespace std;

int N, M;
map<int, int> who;
deque<deque<int> > whoCome;

struct person{
    int know;
    set<int> connect;
};

person P[52];

void makeConnect(deque<int> pers){
    for(int i = 0; i<pers.size(); i++){
        int now = pers[i];
        for(int j = 0; j<pers.size(); j++){
            if(now == pers[j]) continue;
            P[now].connect.insert(pers[j]);
        }
    }
}

int main(){
    int numPerson;
    int answer = 0;
    cin >> N >> M;
    cin >> numPerson;
    deque<int> knowPerson;
    for(int i = 0; i<numPerson; i++){
        int temp;
        cin >> temp;
        P[temp].know = 1;
        knowPerson.push_back(temp);
    }

    deque<deque<int> > party;

    for(int i = 0; i<M; i++){
        int commingPerson;
        cin >> commingPerson;
        deque<int> q;
        for(int j = 0; j<commingPerson; j++){
            int temp;
            cin >> temp;
            q.push_back(temp);
        }
        makeConnect(q);
        party.push_back(q);
    }

    int visited[52] = {0};

    while(!knowPerson.empty()){
        int now = knowPerson.front();
        knowPerson.pop_front();
        
        for(auto iter = P[now].connect.begin(); iter!= P[now].connect.end(); iter++){
            if(visited[*iter] == 0){
                visited[*iter] = 1;
                knowPerson.push_back(*iter);
                P[*iter].know = 1;
            }
        }
        
    }

    for(int i = 0 ; i<party.size();i++){
        int flag = 0;
        for(int j = 0; j<party[i].size(); j++){
            if(P[party[i][j]].know == 1) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) answer ++;
    }

    cout << answer << endl;
    return 0;
}