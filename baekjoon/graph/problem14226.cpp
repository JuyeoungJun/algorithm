#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int result = 1;
int S;
deque<int> howmuch;
deque<int> t;
deque<int> clipboard;
int visited[2001];

int find_sol(){
    int temph, tempt, tempc;
    while(!howmuch.empty()){
        if(howmuch.front() == S){
            result = t.front();
            return 0;
        }
        temph = howmuch.front();
        tempt = t.front();
        tempc = clipboard.front();
        //클립보드 붙여넣기
        if(temph+tempc < 1001 && visited[temph+tempc] > tempt+1){
            howmuch.push_back(temph+tempc);
            t.push_back(tempt+1);
            clipboard.push_back(tempc);
            visited[temph+tempc] = tempt+1;
        }
        //하나 빼기
        if(temph-1 >= 1 && visited[temph-1] > tempt+1){
            howmuch.push_back(temph-1);
            t.push_back(tempt+1);
            clipboard.push_back(tempc);
            visited[temph-1] = tempt+1;
        }
        //클립 보드 추가
        if(temph != tempc){
            howmuch.push_back(temph);
            t.push_back(tempt+1);
            clipboard.push_back(temph);
        }
        howmuch.pop_front();
        t.pop_front();
        clipboard.pop_front();
    }
    

    return 0;
}


int main(){
    scanf("%d",&S);
    for(int i = 0; i<2001; i++){
        visited[i] = 987654321;
    }
    howmuch.push_back(1);
    t.push_back(0);
    clipboard.push_back(0);
    visited[1] = 0;
    find_sol();
    cout << result <<endl;
    return 0;
}