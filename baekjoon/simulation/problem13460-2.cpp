#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int N,M;
char map[12][12];
int direction[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int ra,rb,ba,bb;
int min_result = 987654321;
int check[12][12][12][12];

int move_ball(int direc){
    int r_mov = 0;
    int b_mov = 0;
    int tra = ra;
    int trb = rb;
    int tba = ba;
    int tbb = bb;
    int r_flag = 0;
    int b_flag = 0;
    while(1){
        if(map[tra + direction[direc][0]][trb + direction[direc][1]] == '#'){
            break;
        } 
        else if(map[tra + direction[direc][0]][trb + direction[direc][1]] == 'O'){
            r_flag = 1;
            break;
        }
        tra += direction[direc][0];
        trb += direction[direc][1];
        r_mov += 1;
    }
    while(1){
        if(map[tba + direction[direc][0]][tbb + direction[direc][1]] == '#'){
            break;
        } 
        else if(map[tba + direction[direc][0]][tbb + direction[direc][1]] == 'O'){
            b_flag = 1;
            break;
        }
        tba += direction[direc][0];
        tbb += direction[direc][1];
        b_mov += 1;
    }

    if(r_flag == 1){
        if(b_flag == 1){
            return -1;
        }
        else if(b_flag == 0){
            return 1;
        }
    }

    if(b_flag == 1 && r_flag == 0){
        return -1;
    }

    if(tra == tba && trb == tbb){
        if(r_mov > b_mov){
            tra -= direction[direc][0];
            trb -= direction[direc][1];
        }
        else{
            tba -= direction[direc][0];
            tbb -= direction[direc][1];
        }
    }

    if(check[tra][trb][tba][tbb] == 0){
        ra = tra;
        rb = trb;
        ba = tba;
        bb = tbb;
        check[tra][trb][tba][tbb] = 1;
    }
    else{
        return -1;
    }

    return 0;
}

int make_comb(int depth){
    if(depth > 10){
        return 0;
    }
    int result = 0;
    int temp_ra = ra; 
    int temp_rb = rb; 
    int temp_ba = ba; 
    int temp_bb = bb;
    for(int i = 0 ; i<4; i++){
        result = move_ball(i);
        if(result == 1){
            min_result = min(depth,min_result);
            continue;
        }
        else if(result == -1){
            continue;
        }
        else{
            make_comb(depth+1);
        }
        check[ra][rb][ba][bb] = 0;
        ra = temp_ra;
        rb = temp_rb;
        ba = temp_ba;
        bb = temp_bb;
    }
    return 0;
}


int main(){
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> map[i][j];
            if(map[i][j] == 'R'){
                ra = i;
                rb = j;
            }
            else if(map[i][j] == 'B'){
                ba = i;
                bb = j;
            }
        }
    }
    make_comb(1);
    if(min_result == 987654321){
        cout << "-1" << endl;
        return 0;
    }
    cout << min_result << endl;
    return 0;
}