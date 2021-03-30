#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

struct where{
    int x;
    int y;
    int flag;
};

int N,M;
int visited[1001][1001];
int map[1001][1001];
deque<where> q;
deque<int> dist;
int result =987654321;

void find_sol(){
    int a,b,c;
    where temp;
    while(!q.empty()){
        a = q.front().x;
        b = q.front().y;
        c = q.front().flag;
        cout << "a: " << a <<" b: " << b << " flag: " << c << " distance: " <<dist.front() <<endl;
        if(a == N-1 && b == M-1){
            cout << "result: " << dist.front() << endl;
            result = min(result, dist.front());
            q.pop_front();
            dist.pop_front();
            continue;
        }
        if(c == 0){
            //위
            if(a-1 >= 0){
                if(visited[a-1][b] == 0){
                    temp.x = a-1;
                    temp.y = b;
                    if(map[a-1][b] == 1){
                        temp.flag = 1;
                    }
                    else{
                        temp.flag = 0;
                    }
                    visited[a-1][b] = 1;
                    q.push_back(temp);
                    dist.push_back(dist.front()+1);
                }
            }
            //아래
            if(a+1 < N){
                if(visited[a+1][b] == 0){
                    temp.x = a+1;
                    temp.y = b;
                    
                    if(map[a+1][b] == 1){
                        temp.flag = 1;
                    }
                    else{
                        temp.flag = 0;
                    }
                    visited[a+1][b] = 1;
                    q.push_back(temp);
                    dist.push_back(dist.front()+1);
                }

            }
            //오
            if(b+1 < M){
                if(visited[a][b+1] == 0){
                    temp.x = a;
                    temp.y = b+1;
                    if(map[a][b+1] == 1){
                        temp.flag = 1;
                    }
                    else{
                        temp.flag = 0;
                    }
                    visited[a][b+1] = 1;
                    q.push_back(temp);
                    dist.push_back(dist.front()+1);
                }

            }
            //왼
            if(b-1 >= 0){
                if(visited[a][b-1] == 0){
                    temp.x = a;
                    temp.y = b-1;
                    if(map[a][b-1] == 1){
                        temp.flag = 1;
                    }
                    else{
                        temp.flag = 0;
                    }
                    visited[a][b-1] = 1;
                    q.push_back(temp);
                    dist.push_back(dist.front()+1);
                }

            }
        }
        else{
            //위
            if(a-1 >= 0){
                if(map[a-1][b] == 0){
                    if(visited[a-1][b] == 0){
                        temp.x = a-1;
                        temp.y = b;
                        temp.flag = 1;
                        visited[a-1][b] = 1;
                        q.push_back(temp);
                        dist.push_back(dist.front()+1);
                    }
                }
            }
            //아래
            if(a+1 < N){
                if(map[a+1][b] == 0){
                    if(visited[a+1][b] == 0){
                        temp.x = a+1;
                        temp.y = b;
                        temp.flag = 1;
                        visited[a+1][b] = 1;
                        q.push_back(temp);
                        dist.push_back(dist.front()+1);
                    }
                }

            }
            //오
            if(b+1 < M){
                if(map[a][b+1] == 0){
                    if(visited[a][b+1] == 0){
                        temp.x = a;
                        temp.y = b+1;
                        temp.flag = 1;
                        visited[a][b+1] = 1;
                        q.push_back(temp);
                        dist.push_back(dist.front()+1);
                    }
                }

            }
            //왼
            if(b-1 >= 0){
                if(map[a][b-1] == 0){
                    if(visited[a][b-1] == 0){
                        temp.x = a;
                        temp.y = b-1;
                        temp.flag = 1;
                        visited[a][b-1] = 1;
                        q.push_back(temp);
                        dist.push_back(dist.front()+1);
                    }
                }

            }
        }
        q.pop_front();
        dist.pop_front();
    }

}

int main(){
    cin >> N >> M;
    string temp;
    for(int i = 0; i<N; i++){
        cin >> temp;
        for(int j = 0; j<M; j++){
            map[i][j] = temp[j] - '0';
            visited[i][j] = 0;
        }
    }
    
    where t;
    t.flag = 0;
    t.x = 0;
    t.y = 0;
    q.push_back(t);
    dist.push_back(1);
    visited[0][0] = 1;
    find_sol();
    
    if(result == 987654321){
        cout << "-1" << endl;
    }
    else{
        cout << result << endl;
    }
    return 0;
}