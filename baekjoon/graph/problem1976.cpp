#include <iostream>
#include <deque>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int N, M;
int connect[201][201];
int visited[201] = {0};

int main(){
    cin >> N;
    cin >> M;

    for(int i = 0 ; i<N; i++){
        for(int j = 0; j<N ; j++){
            cin >> connect[i][j];
        }
    }

    map<int,int> checker;
    queue<int> q;
    deque<int> city;
    int temp = 0;
    for(int i = 0; i<M; i++){
        cin >> temp;
        if(i == 0){
            q.push(temp-1);
            visited[temp-1] = 1;
            checker[temp-1] = 1;
        }
        city.push_back(temp-1);
        //checker[temp-1] = 0;
    }
    
    while(!q.empty()){
        int where = q.front();

        for(int i = 0; i<N; i++){
            if(connect[where][i] == 1 && visited[i] == 0){
                q.push(i);
                visited[i] = 1;
                checker[i] = 1;
            }
        }
        q.pop();
    }
   
   for(int i = 0; i<city.size(); i++){
       if(checker[city[i]] == 0){
           cout << "NO" << endl;
           return 0;
       }
   }
   

    cout << "YES" << endl;
    return 0;
}