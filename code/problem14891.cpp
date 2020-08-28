#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

deque<deque<int> > tob;

void rotation(int where,int direction){
    if(direction == 1){
        tob[where].push_front(tob[where].back());
        tob[where].pop_back();
    }
    else if(direction == -1){
        tob[where].push_back(tob[where].front());
        tob[where].pop_front();
    }

}

void mov(int where,int direction){
    int d[9];
    for(int i = 0 ; i<8 ; i++){
        d[i] = 0;
    }
    d[where] = direction;
    for(int i = where ; i>= 0 ; i--){
        if(i == where){
            continue;
        }
        if(tob[i][2] != tob[i+1][6]){
            d[i] = d[i+1] * -1;
        }
    }   
    for(int i = where+1 ; i<4;i++){
        if(tob[i][6] != tob[i-1][2]){
            d[i] = d[i-1] * -1;
        }
    }
    for(int i = 0; i <8 ; i++){
        rotation(i,d[i]);
    }
}

int main(){
    deque<int> temp;
    int itemp;   
    temp.assign(8,0);
    for(int i = 0; i<4; i++){
        tob.push_back(temp);
    }
    for(int i = 0; i<4; i++){
        cin >> itemp;
        for(int j = 7; j>=0; j--){
            tob[i][j] = itemp%10;
            itemp /=10;
        }
    }
    int K,a,b;
    cin >> K;
    for(int i = 0; i<K; i++){
        cin >> a >> b;
        mov(a-1,b);
        
    }
    int result = 0;
    /*
    for(int i = 0; i<4; i++){
        result += tob[i][0]*pow(2,i);
    }
    cout << result << endl;*/
    if(tob[0][0] == 1) result += 1;
    if(tob[1][0] == 1) result += 2;
    if(tob[2][0] == 1) result += 4;
    if(tob[3][0] == 1) result += 8;
    cout <<result <<endl;
    return 0;
}