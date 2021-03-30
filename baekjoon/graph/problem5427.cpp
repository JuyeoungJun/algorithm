#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int c,w,h;

int main(){
    string temp;
    cin >> c;
    for(int i = 0; i<c ; i++){
        int map[1001][1001];
        deque<pair<int,int> > q;
        deque<int> tim;
        deque<pair<int, int> >f;
        deque<int> ft;
        int result;
        cin >> w >> h;
        for(int j = 0; j<h; j++){
            cin >> temp;
            for(int k = w-1; k>=0 ; k--){
                if(temp.back() == '#'){
                    map[j][k] = -1;
                }
                else if(temp.back() == '*'){
                    map[j][k] = 2;
                    f.push_back(make_pair(j,k));
                    ft.push_back(0);
                }
                else if(temp.back() == '@'){
                    map[j][k] = 1;
                    q.push_back(make_pair(j,k));
                    tim.push_back(0);
                }
                else if(temp.back() == '.'){
                    map[j][k] = 0;
                }
                temp.pop_back();
            }
        }
        int a,b;
        int now = 0;
        int aa,bb;
        result = -1;
        while(!q.empty()){
            a = q.front().first;
            b = q.front().second;
            if(a == 0 || a == h-1 || b == 0 || b == w-1){
                result = tim.front();
                break;
            }

            if(ft.size() != 0 && ft.front() == tim.front()){
                while(!f.empty()){
                    if(ft.front() > tim.front()){
                        break;
                    }
                    aa = f.front().first;
                    bb = f.front().second;
                    if(aa-1 >= 0 && (map[aa-1][bb] == 0 || map[aa-1][bb] == 1)){
                        //위
                        f.push_back(make_pair(aa-1,bb));
                        ft.push_back(tim.front()+1);
                        map[aa-1][bb] = 2;
                    }
                    if(aa+1 < h && (map[aa+1][bb] == 0 || map[aa+1][bb] == 1)){
                        //아래
                        f.push_back(make_pair(aa+1,bb));
                        ft.push_back(tim.front()+1);
                        map[aa+1][bb] = 2;
                    }
                    if(bb-1 >= 0 && (map[aa][bb-1] == 0 || map[aa][bb-1] == 1)){
                        //왼
                        f.push_back(make_pair(aa,bb-1));
                        ft.push_back(tim.front()+1);
                        map[aa][bb-1] = 2;
                    }
                    if(bb+1 < w && (map[aa][bb+1] == 0 || map[aa][bb+1] == 1)){
                        //오
                        f.push_back(make_pair(aa,bb+1));
                        ft.push_back(tim.front()+1);
                        map[aa][bb+1] = 2;
                    }
                    f.pop_front();
                    ft.pop_front();
                }
            }
            if(map[a-1][b] == 0){
                //위
                q.push_back(make_pair(a-1,b));
                tim.push_back(tim.front()+1);
                map[a-1][b] = 1;
            }
            if(map[a+1][b] == 0){
                //아래
                q.push_back(make_pair(a+1,b));
                tim.push_back(tim.front()+1);
                map[a+1][b] = 1;
            }
            if(map[a][b-1] == 0){
                //왼
                q.push_back(make_pair(a,b-1));
                tim.push_back(tim.front()+1);
                map[a][b-1] = 1;
            }
            if(map[a][b+1] == 0){
                //오
                q.push_back(make_pair(a,b+1));
                tim.push_back(tim.front()+1);
                map[a][b+1] = 1;
            }
            q.pop_front();
            tim.pop_front();
        }
        if(result == -1){
            cout << "IMPOSSIBLE" << endl;
        }
        else{
            cout << result+1 << endl;
        }



    }

   
    return 0;
}