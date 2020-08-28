#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int M,N,H;
int box[101][101][101];
int MM,NN,HH;
deque<vector<int> > q;
deque<int> tim;
int result;


int check_box(){

    for(int i = 0; i<H; i++){
        for(int j = 0; j<N; j++){
            for(int k = 0; k<M; k++){
                if(box[i][j][k] == 0){
                    return -1;
                }
            }
        }
    }
    return 1;
}



int main(){
    cin >> M >> N >> H;
    int temp;
    for(int i = 0; i<H; i++){
        for(int j = 0; j<N; j++){
            for(int k = 0; k<M; k++){
                cin >> box[i][j][k];
                if(box[i][j][k] == 1){
                    vector<int> t;
                    t.push_back(i);
                    t.push_back(j);
                    t.push_back(k);
                    q.push_back(t);
                    tim.push_back(0);
                }
            }
        }
    }
    
    while(!q.empty()){
        HH = q.front()[0];
        NN = q.front()[1];
        MM = q.front()[2];
        result = tim.front();
        //cout << HH << " " << NN << " " << MM << " " << endl;
        if(HH+1 < H && box[HH+1][NN][MM] == 0){
            //위
            box[HH+1][NN][MM] = 1;
            vector<int> t;
            t.push_back(HH+1);
            t.push_back(NN);
            t.push_back(MM);
            q.push_back(t);
            tim.push_back(tim.front()+1);
        }

        if(HH-1 >= 0 && box[HH-1][NN][MM] == 0){
            //아래
            box[HH-1][NN][MM] = 1;
            vector<int> t;
            t.push_back(HH-1);
            t.push_back(NN);
            t.push_back(MM);
            q.push_back(t);
            tim.push_back(tim.front()+1);
        }
        if(NN+1 < N && box[HH][NN+1][MM] == 0){
            //오
            box[HH][NN+1][MM] = 1;
            vector<int> t;
            t.push_back(HH);
            t.push_back(NN+1);
            t.push_back(MM);
            q.push_back(t);
            tim.push_back(tim.front()+1);

        }
        if(NN-1 >= 0 && box[HH][NN-1][MM] == 0){
            //왼
            box[HH][NN-1][MM] = 1;
            vector<int> t;
            t.push_back(HH);
            t.push_back(NN-1);
            t.push_back(MM);
            q.push_back(t);
            tim.push_back(tim.front()+1);
        }
        if(MM+1 < M && box[HH][NN][MM+1] == 0){
            //앞
            box[HH][NN][MM+1] = 1;
            vector<int> t;
            t.push_back(HH);
            t.push_back(NN);
            t.push_back(MM+1);
            q.push_back(t);
            tim.push_back(tim.front()+1);
        }
        if(MM-1 >= 0 && box[HH][NN][MM-1] == 0){
            //뒤
            box[HH][NN][MM-1] = 1;
            vector<int> t;
            t.push_back(HH);
            t.push_back(NN);
            t.push_back(MM-1);
            q.push_back(t);
            tim.push_back(tim.front()+1);
        }
        q.pop_front();
        tim.pop_front();
    }
    
    if(check_box() == 1){
        cout << result << endl;
    }
    else{
        cout << -1 << endl;
    }
    //cout << result << endl;
    return 0;
}