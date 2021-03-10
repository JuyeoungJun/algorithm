#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

deque<int> na;
deque<int> res;
int flag = 0;
int s;

int getScore(){
    int r = s;
    for(int i = 0; i<res.size(); i++){
        r -= res[i];
    }
    return r;
}

int makeComb(int depth, int who){
    if(depth == 2){
        if(getScore() == 100){
            flag = 1;
            for(int i = 0; i<na.size(); i++){
                if(na[i] != res[0] && na[i] != res[1]){
                    cout << na[i] << endl;
                }
            }            
        }
        return 0;
    }
    for(int i = who; i<9; i++){
        res.push_back(na[i]);
        makeComb(depth+1,who+1);
        if(flag == 1){
            return 0;
        }
        res.pop_back();
    }
    return 0;
}

int main(){
    int temp;
    for(int i = 0; i<9; i++){
        cin >> temp;
        na.push_back(temp);
        s += temp;
    }

    makeComb(0,0);


    return 0;
}