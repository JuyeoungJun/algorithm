#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int N;
int integer[9];
int visited[9];
deque<int> result;
int rresult;

int calculate(){
    int s = 0;
    //cout << "-----------------------------------------------"<<endl;
    for(int i = 0; i<result.size()-1;i++){
        s+=abs(result[i]-result[i+1]);
        //cout << result[2*i] << " " << result[2*i+1] << endl;
    }
    //cout << "----------------------------------------------"<<endl;
    /*
    if(result.size()%2 == 1){
        s+=result.back();
    }*/
    //cout << s << endl;
    return s;
}

int find_sol(){
    if(result.size() == N){
        //계산
        int temp = calculate();
        rresult = max(rresult,temp);
        return 0;
    }

    for(int i = 0; i<N; i++){
        if(visited[i] == 0){
            result.push_back(integer[i]);
            visited[i] = 1;
            find_sol();
            result.pop_back();
            visited[i] = 0;
        }
    }
    return 0;
}

int main(){
    cin >> N;
    for(int i = 0; i<N ; i++){
        cin >> integer[i];
    }
    find_sol();
    cout << rresult << endl;
    return 0;
}