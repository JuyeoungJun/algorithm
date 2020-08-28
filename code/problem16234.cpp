#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N,L,R;
int mapp[51][51];
int check_mapp[51][51];
//int yeonhap[51][51];
deque<deque<pair<int, int> > > yeonhap;
deque<int> s;

int find_yeonhap(int a, int b, int k){
    int result = mapp[a][b];
    deque<pair<int, int> > q;
    deque<pair<int, int> > temp;
    q.push_back(make_pair(a,b));
    temp.push_back(make_pair(a,b));
    check_mapp[a][b] = 1;
    while(1){
        //cout << q.size() << endl;
        if(q.empty()){
            yeonhap.push_back(temp);
            return result;
        }
        //오른쪽
        if(abs(mapp[q.front().first][q.front().second+1]-mapp[q.front().first][q.front().second]) <=R && abs(mapp[q.front().first][q.front().second+1]-mapp[q.front().first][q.front().second]) >= L && q.front().second+1 < N && check_mapp[q.front().first][q.front().second+1] == 0){
            temp.push_back(make_pair(q.front().first,q.front().second+1));
            q.push_back(make_pair(q.front().first,q.front().second+1));
            check_mapp[q.front().first][q.front().second+1] = 1;
            result += mapp[q.front().first][q.front().second+1];
        }
        //아래
        if(abs(mapp[q.front().first+1][q.front().second]-mapp[q.front().first][q.front().second]) <=R && abs(mapp[q.front().first+1][q.front().second]-mapp[q.front().first][q.front().second]) >= L && q.front().first+1 < N&& check_mapp[q.front().first+1][q.front().second] == 0){
            temp.push_back(make_pair(q.front().first+1,q.front().second));
            q.push_back(make_pair(q.front().first+1,q.front().second));
            check_mapp[q.front().first+1][q.front().second] = 1;
            result += mapp[q.front().first+1][q.front().second];
        }
        //왼
        if(abs(mapp[q.front().first][q.front().second-1]-mapp[q.front().first][q.front().second]) <=R && abs(mapp[q.front().first][q.front().second-1]-mapp[q.front().first][q.front().second]) >= L && q.front().second-1 >= 0&& check_mapp[q.front().first][q.front().second-1] == 0){
            temp.push_back(make_pair(q.front().first,q.front().second-1));
            q.push_back(make_pair(q.front().first,q.front().second-1));
            check_mapp[q.front().first][q.front().second-1] = 1;
            result += mapp[q.front().first][q.front().second-1];
        }
        //위
        if(abs(mapp[q.front().first-1][q.front().second]-mapp[q.front().first][q.front().second]) <=R && abs(mapp[q.front().first-1][q.front().second]-mapp[q.front().first][q.front().second]) >= L && q.front().first-1 >= 0&& check_mapp[q.front().first-1][q.front().second] == 0){
            temp.push_back(make_pair(q.front().first-1,q.front().second));
            q.push_back(make_pair(q.front().first-1,q.front().second));
            check_mapp[q.front().first-1][q.front().second] = 1;
            result += mapp[q.front().first-1][q.front().second];
        }
        q.pop_front();                
    }
    return result;
}
int main(){
    cin >> N >> L >> R;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N ; j++){
            cin >> mapp[i][j];
        }
    }
    int y = 1;
    int temp;
    int result = 0;
    while(1){
        /*
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                cout << mapp[i][j] << " ";
            }
            cout << endl;
        }*/
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                check_mapp[i][j] = 0;
            }
        }
        s.clear();
        yeonhap.clear();
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N ; j++){
                if(check_mapp[i][j] == 0){
                    temp = find_yeonhap(i,j,y);
                    s.push_back(temp);
                }
                
            }
        }
        //cout << yeonhap.size() << endl;
        if(yeonhap.size() == N*N){
            cout <<result << endl;
            break;
        }
        for(int i = 0; i<yeonhap.size(); i++){
            //cout << "1" << endl;
            //cout << "result = " << s[i] << endl;
            for(int j = 0; j<yeonhap[i].size(); j++){
                /*
                cout << "s[" << i << "]: "<< s[i] << endl;
                cout << yeonhap[i].size()<< endl;
                cout << s[i]/yeonhap[i].size() << endl;
*/
                mapp[yeonhap[i][j].first][yeonhap[i][j].second] = s[i]/yeonhap[i].size();
            }
        }
        result+=1;
    }
    return 0;
}