#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int N;
int map[26][26];
int visited[26][26] = {0,};
deque<int> result;

int find_sol(int a, int b){
    deque<pair<int, int> > q;
    q.push_back(make_pair(a,b));
    visited[a][b] = 1;
    int tempa,tempb;
    int resultt = 1;
    while(!q.empty()){
        tempa = q.front().first;
        tempb = q.front().second;
        //위
        if(tempa-1 >= 0 && map[tempa-1][tempb] == 1 && visited[tempa-1][tempb] == 0){
            q.push_back(make_pair(tempa-1,tempb));
            visited[tempa-1][tempb] = 1;
            resultt++;
        }
        //오
        if(tempb+1 < N && map[tempa][tempb+1] == 1 && visited[tempa][tempb+1] == 0){
            q.push_back(make_pair(tempa,tempb+1));
            resultt++;
            visited[tempa][tempb+1] = 1;
        }
        //아래
        if(tempa + 1< N && map[tempa+1][tempb] == 1 && visited[tempa+1][tempb] == 0){
            q.push_back(make_pair(tempa+1,tempb));
            resultt++;
            visited[tempa+1][tempb] = 1;
        }
        //왼
        if(tempb - 1 >= 0 && map[tempa][tempb-1] == 1 && visited[tempa][tempb-1] == 0){
            q.push_back(make_pair(tempa,tempb-1));
            resultt++;
            visited[tempa][tempb-1] = 1;
        }
        q.pop_front();
    }
    return resultt;
}

int main(){
    cin >> N;
    string temp;
    for(int i = 0 ; i<N ; i++){
        cin >> temp;
        for(int j = 0 ; j <N ; j++){
            map[i][j] = temp[j] - '0';
        }
    }
    int tempt;
    for(int i = 0;i<N; i++){
        for(int j = 0; j<N ; j++){
            if(visited[i][j] == 0 && map[i][j] == 1){
                tempt = find_sol(i,j);
                result.push_back(tempt);
            }
        }
    }

    sort(result.begin(),result.end());
    cout << result.size() << endl;
    for(int i = 0; i<result.size(); i++){
        cout << result[i] << endl;
    }

    return 0;
}