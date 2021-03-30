#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int mapp[9][9];
int N,M;
deque<pair<int,int> > cctv_where;
deque<int> cctv;
deque<int> direction;
deque<int> dire;
int result = 987654321;

deque<deque<int> > solve_check(deque<deque<int> > check,int di,int which, pair<int,int> point){
  
    check[point.first][point.second] = 1;
    if(which == 1){
        if(di == 0){
            //오른쪽
            for(int i = 1; i<M-point.second; i++){
                if(check[point.first][point.second+i] == 0){
                    check[point.first][point.second+i] = 1;
                }
                else if(check[point.first][point.second+i] == 6){
                    break;
                }
            }
        }
        else if(di == 1){
            //아래
            for(int i = 1; i<N-point.first; i++){
                if(check[point.first+i][point.second] == 0){
                    check[point.first+i][point.second] = 1;
                }
                else if(check[point.first+i][point.second] == 6){
                    break;
                }
            }
        }
        else if(di == 2){
            //왼쪽
            for(int i = 1; i<=point.second; i++){
                if(check[point.first][point.second-i] == 0){
                    check[point.first][point.second-i] = 1;
                }
                else if(check[point.first][point.second-i] == 6){
                    break;
                }
            }
            
        }
        else if(di == 3){
            //위
            for(int i = 1; i<=point.first; i++){
                if(check[point.first-i][point.second] == 0){
                    check[point.first-i][point.second] = 1;
                }
                else if(check[point.first-i][point.second] == 6){
                    break;
                }
            }
        }
    }
    else if(which == 2){
        if(di == 0){
            //가로
            for(int i = 1; i<M-point.second; i++){
                if(check[point.first][point.second+i] == 0){
                    check[point.first][point.second+i] = 1;
                }
                else if(check[point.first][point.second+i] == 6){
                    break;
                }
            }
            for(int i = 1; i<=point.second; i++){
                if(check[point.first][point.second-i] == 0){
                    check[point.first][point.second-i] = 1;
                }
                else if(check[point.first][point.second-i] == 6){
                    break;
                }
            }
        }
        else if(di ==1){
            //세로
            for(int i = 1; i<N-point.first; i++){
                if(check[point.first+i][point.second] == 0){
                    check[point.first+i][point.second] = 1;
                }
                else if(check[point.first+i][point.second] == 6){
                    break;
                }
            }
            for(int i = 1; i<=point.first; i++){
                if(check[point.first-i][point.second] == 0){
                    check[point.first-i][point.second] = 1;
                }
                else if(check[point.first-i][point.second] == 6){
                    break;
                }
            }
        }
    }
    else if(which == 3){
        if(di == 0){
            for(int i = 1; i<M-point.second; i++){
                if(check[point.first][point.second+i] == 0){
                    check[point.first][point.second+i] = 1;
                }
                else if(check[point.first][point.second+i] == 6){
                    break;
                }
            }
            for(int i = 1; i<N-point.first; i++){
                if(check[point.first+i][point.second] == 0){
                    check[point.first+i][point.second] = 1;
                }
                else if(check[point.first+i][point.second] == 6){
                    break;
                }
            }
        }
        else if(di == 1){
            for(int i = 1; i<N-point.first; i++){
                if(check[point.first+i][point.second] == 0){
                    check[point.first+i][point.second] = 1;
                }
                else if(check[point.first+i][point.second] == 6){
                    break;
                }
            }
            for(int i = 1; i<=point.second; i++){
                if(check[point.first][point.second-i] == 0){
                    check[point.first][point.second-i] = 1;
                }
                else if(check[point.first][point.second-i] == 6){
                    break;
                }
            }
        }
        else if(di == 2){
            for(int i = 1; i<=point.second; i++){
                if(check[point.first][point.second-i] == 0){
                    check[point.first][point.second-i] = 1;
                }
                else if(check[point.first][point.second-i] == 6){
                    break;
                }
            }
            for(int i = 1; i<=point.first; i++){
                if(check[point.first-i][point.second] == 0){
                    check[point.first-i][point.second] = 1;
                }
                else if(check[point.first-i][point.second] == 6){
                    break;
                }
            }
        }
        else if(di == 3){
            for(int i = 1; i<=point.first; i++){
                if(check[point.first-i][point.second] == 0){
                    check[point.first-i][point.second] = 1;
                }
                else if(check[point.first-i][point.second] == 6){
                    break;
                }
            }
            for(int i = 1; i<M-point.second; i++){
                if(check[point.first][point.second+i] == 0){
                    check[point.first][point.second+i] = 1;
                }
                else if(check[point.first][point.second+i] == 6){
                    break;
                }
            }
        }        
    }
    else if(which == 4){
        if(di == 0){
            for(int i = 1; i<M-point.second; i++){
                if(check[point.first][point.second+i] == 0){
                    check[point.first][point.second+i] = 1;
                }
                else if(check[point.first][point.second+i] == 6){
                    break;
                }
            }
            for(int i = 1; i<=point.second; i++){
                if(check[point.first][point.second-i] == 0){
                    check[point.first][point.second-i] = 1;
                }
                else if(check[point.first][point.second-i] == 6){
                    break;
                }
            }
            for(int i = 1; i<N-point.first; i++){
                if(check[point.first+i][point.second] == 0){
                    check[point.first+i][point.second] = 1;
                }
                else if(check[point.first+i][point.second] == 6){
                    break;
                }
            }
        }
        
        else if(di == 1){
            for(int i = 1; i<N-point.first; i++){
                if(check[point.first+i][point.second] == 0){
                    check[point.first+i][point.second] = 1;
                }
                else if(check[point.first+i][point.second] == 6){
                    break;
                }
            }
            for(int i = 1; i<=point.first; i++){
                if(check[point.first-i][point.second] == 0){
                    check[point.first-i][point.second] = 1;
                }
                else if(check[point.first-i][point.second] == 6){
                    break;
                }
            }
            for(int i = 1; i<M-point.second; i++){
                if(check[point.first][point.second+i] == 0){
                    check[point.first][point.second+i] = 1;
                }
                else if(check[point.first][point.second+i] == 6){
                    break;
                }
            }
            
        }
        else if(di == 2){
            for(int i = 1; i<M-point.second; i++){
                if(check[point.first][point.second+i] == 0){
                    check[point.first][point.second+i] = 1;
                }
                else if(check[point.first][point.second+i] == 6){
                    break;
                }
            }
            for(int i = 1; i<=point.second; i++){
                if(check[point.first][point.second-i] == 0){
                    check[point.first][point.second-i] = 1;
                }
                else if(check[point.first][point.second-i] == 6){
                    break;
                }
            }
            for(int i = 1; i<=point.first; i++){
                if(check[point.first-i][point.second] == 0){
                    check[point.first-i][point.second] = 1;
                }
                else if(check[point.first-i][point.second] == 6){
                    break;
                }
            }     
        }
        else if(di == 3){
            for(int i = 1; i<N-point.first; i++){
                if(check[point.first+i][point.second] == 0){
                    check[point.first+i][point.second] = 1;
                }
                else if(check[point.first+i][point.second] == 6){
                    break;
                }
            }
            for(int i = 1; i<=point.first; i++){
                if(check[point.first-i][point.second] == 0){
                    check[point.first-i][point.second] = 1;
                }
                else if(check[point.first-i][point.second] == 6){
                    break;
                }
            }
            for(int i = 1; i<=point.second; i++){
                if(check[point.first][point.second-i] == 0){
                    check[point.first][point.second-i] = 1;
                }
                else if(check[point.first][point.second-i] == 6){
                    break;
                }
            }  
        }
    }
    else if(which == 5){
        for(int i = 1; i<N-point.first; i++){
            if(check[point.first+i][point.second] == 0){
                check[point.first+i][point.second] = 1;
            }
            else if(check[point.first+i][point.second] == 6){
                    break;
            }
        }
        for(int i = 1; i<=point.first; i++){
            if(check[point.first-i][point.second] == 0){
                check[point.first-i][point.second] = 1;
            }
            else if(check[point.first-i][point.second] == 6){
                    break;
            }
        }
        for(int i = 1; i<=point.second; i++){
            if(check[point.first][point.second-i] == 0){
                check[point.first][point.second-i] = 1;
            }
            else if(check[point.first][point.second-i] == 6){
                    break;
            }
        }
        for(int i = 1; i<M-point.second; i++){
            if(check[point.first][point.second+i] == 0){
                check[point.first][point.second+i] = 1;
            }
            else if(check[point.first][point.second+i] == 6){
                break;
            }
        }
    }

    return check;
}

int count_result(deque<deque<int> > check){
    int temp = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(check[i][j] == 0){
                temp ++;
            }
        }
    }
    return temp;
}
int make_direction(int depth,deque<deque<int> > check){
    if(depth == cctv.size()){
        result = min(result, count_result(check));
    }
    for(int i = 0; i<dire[depth]; i++){
        direction.push_back(i);
        make_direction(depth+1, solve_check(check,i,cctv[depth],cctv_where[depth]));
        direction.pop_back();
    }
    return 0;
}

int main(){
    deque<deque<int> > check;
    deque<int> temp;
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        temp.clear();
        for(int j = 0; j<M; j++){
            temp.push_back(0);
        }
        check.push_back(temp);
    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> mapp[i][j];
            if(mapp[i][j] == 6){
                check[i][j] = 6;
            }
            else if(mapp[i][j] >= 1 && mapp[i][j] <= 5){
                cctv.push_back(mapp[i][j]);
                cctv_where.push_back(make_pair(i,j));
                if(mapp[i][j] == 1 || mapp[i][j] == 3 || mapp[i][j] ==4){
                    dire.push_back(4);
                }
                else if(mapp[i][j] == 2){
                    dire.push_back(2);
                }
                else if(mapp[i][j] ==5){
                    dire.push_back(1);
                }
            }
        }
    }
    make_direction(0, check);
    cout << result << endl;
    return 0;
}