#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N,M,T;

deque<int> circle[50];

void rotation(int x,int d,int k){
    deque<int> who;
    for(int i = 0; i<N; i++){
        if((i+1)%x == 0){
            who.push_back(i);
        }
    }
    int howmuch = k;
    howmuch = howmuch%M;
    if(d == 0){
        //시계 방향(뒤에꺼를 앞으로)
        for(int i = 0 ; i<who.size(); i++){
            for(int j = 0; j<howmuch ; j++){
                circle[who[i]].push_front(circle[who[i]].back());
                circle[who[i]].pop_back();
            }
        }
    }
    else{
        //반시계 방향(앞에꺼를 뒤로)
        for(int i = 0 ; i<who.size(); i++){
            for(int j = 0; j<howmuch ; j++){
                circle[who[i]].push_back(circle[who[i]].front());
                circle[who[i]].pop_front();
            }
        }
    }

}

int find_same(int val, int x, int y){
    deque<pair<int,int> > q;
    int a,b;
    q.push_back(make_pair(x,y));
    circle[x][y] = 0;
    int flag = 0;
    while(!q.empty()){
        //위
        a = q.front().first;
        b = q.front().second;
        if(a-1 >= 0 && circle[a-1][b] == val){
            q.push_back(make_pair(a-1,b));
            circle[a-1][b] = 0;
            flag = 1;
        }
        
        //아래
        if(a+1 < N && circle[a+1][b] == val){
            q.push_back(make_pair(a+1,b));
            circle[a+1][b] = 0;
            flag = 1;
        }
        
        int tempb = (b+1)%M;
        //오
        if(circle[a][tempb] == val){
            q.push_back(make_pair(a,tempb));
            circle[a][tempb] = 0;
            flag = 1;
        }
        tempb = b-1;
        if( tempb == -1){
            tempb = M-1;
        }
        //왼
        if(circle[a][tempb] == val){
            q.push_back(make_pair(a,tempb));
            circle[a][tempb] = 0;
            flag = 1;
        }
        q.pop_front();
    }
    if(flag == 0){
        circle[x][y] = val;
    }

    return flag;
}

float sum_circle(){
    float result = 0;
    for(int i = 0; i<N;i++){
        for(int j = 0; j<M; j++){
            result += circle[i][j];
        }
    }
    return result;
}

void erase_mem(){
    int value;
    int flag = 0;
    float count = N*M;
    for(int i = 0 ; i<N; i++){
        for(int j = 0; j<M ; j++){
            if(circle[i][j] == 0){
                count--;
                continue;
            }
            flag += find_same(circle[i][j],i,j);
        }
    }

    if(flag == 0){
        float mean = sum_circle();
        mean /= count;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                if(circle[i][j] == 0){
                    continue;
                }
                if(circle[i][j] > mean){
                    circle[i][j]--;
                }
                else if(circle[i][j] < mean){
                    circle[i][j]++;
                }
            }
        }
    }
}

int main(){
    cin >> N >> M >> T;
    int temp;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> temp;
            circle[i].push_back(temp);
        }
    }
    int x,d,k;
    int flag = 0;
    for(int i = 0 ; i<T ; i++){
        cin >> x >> d >> k;
        rotation(x,d,k);
        erase_mem();
    }

   int result = 0;
   result = sum_circle();
    cout << result << endl;
    return 0;
}