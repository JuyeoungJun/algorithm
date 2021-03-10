#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N,M;
int fina = 0;
vector<vector<int> > grap;
bool visitedCheck(vector<int> visted,int person)
{
    for(int i = 0; i<visted.size(); i++){
        if(person == visted[i]){
            return false;
        }
    }
    return true;
}

int findSol(vector<int> visited, int person){

    if(visited.size() == 5){
        fina = 1;
        return 0;
    }
    for(int i = 0; i<grap[person].size(); i++){
        if(visitedCheck(visited,grap[person][i]) == true){
            visited.push_back(grap[person][i]);
            findSol(visited,grap[person][i]);
            visited.pop_back();
        }
    }
    return 0;
}

int main(){
    int a,b;
    cin >> N >> M;
    vector<int> temp;
    vector<int> visited;
    for(int i = 0; i<N ; i++){
        grap.push_back(temp);
    }
    for(int i = 0; i< M ; i++){
        cin >> a >> b;
        grap[a].push_back(b);
        grap[b].push_back(a);
    }
    for(int i = 0; i<N ; i++){
        if(grap[i].size() == 0){
            continue;
        }
        visited.push_back(i);
        findSol(visited,i);
        if(fina == 1){
            cout << 1 ;
            return 0;
        }
        visited.pop_back();
    }
    cout << 0;
    return 0;
}