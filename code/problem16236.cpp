#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N;
int map[21][21];
int size = 2;
int eat = 0;
deque<pair<int,int> > q;
pair<int, int> where;
int result = 0;

int find_smallone(){
    deque<pair<int,int> > qu;
    deque<int> dist;
    int visited[21][21];
    qu.push_back(make_pair(where.first,where.second));
    dist.push_back(0);
    int a,b;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            visited[i][j] = 0;
        }
    }
    int d_result = 0;
    deque<pair<int, int> > cmp_w; 
    visited[where.first][where.second] = 1;
    int flag = 0;
    while(!qu.empty()){
        //cout << cmp_w.size() << endl;
        if(flag == 1 && d_result < dist.front()){
            where.first = cmp_w.front().first;
            where.second = cmp_w.front().second;
            cmp_w.pop_front();
            while(!cmp_w.empty()){
                if(where.first > cmp_w.front().first){
                    where.first = cmp_w.front().first;
                    where.second = cmp_w.front().second;
                }
                else if(where.first == cmp_w.front().first){
                    if(where.second > cmp_w.front().second){
                        where.second = cmp_w.front().second;
                    }
                }
                cmp_w.pop_front();
            }
            map[where.first][where.second] = 0;
            return d_result+1;
        }
        a = qu.front().first;
        b = qu.front().second;
        //cout << "a: " << a << "b: " << b << endl;

        if(a-1 >=0 && visited[a-1][b] == 0 && map[a-1][b] <= size){
            if(map[a-1][b] < size && map[a-1][b] > 0){
                //where.first = a-1;
                //where.second = b;
                //map[a-1][b] = 0;
                d_result = dist.front();
                cmp_w.push_back(make_pair(a-1,b));
                flag = 1;
                //return dist.front()+1;
            }
            visited[a-1][b] = 1;
            qu.push_back(make_pair(a-1,b));
            dist.push_back(dist.front()+1);
        }
        if(b-1 >= 0 && visited[a][b-1] == 0 && map[a][b-1] <= size){
            if(map[a][b-1] < size && map[a][b-1] > 0){
                //where.first = a;
                //where.second = b-1;
                //map[a][b-1] = 0;
                d_result = dist.front();
                cmp_w.push_back(make_pair(a,b-1));
                flag = 1;
                //return dist.front()+1;
            }
            visited[a][b-1] = 1;
            qu.push_back(make_pair(a,b-1));
            dist.push_back(dist.front()+1);
        }
        if(b+1 < N && visited[a][b+1] == 0 && map[a][b+1] <= size){
            if(map[a][b+1] < size && map[a][b+1] > 0){
                //where.first = a;
                //where.second = b+1;
                //map[a][b+1] = 0;
                d_result = dist.front();
                cmp_w.push_back(make_pair(a,b+1));
                flag = 1;
                //return dist.front()+1;
            }
            visited[a][b+1] = 1;
            qu.push_back(make_pair(a,b+1));
            dist.push_back(dist.front()+1);
        }
        if(a+1 < N && visited[a+1][b] == 0 && map[a+1][b] <= size){
            if(map[a+1][b] < size && map[a+1][b] > 0){
                //where.first = a+1;
                //where.second = b;
                //map[a+1][b] = 0;
                d_result = dist.front();
                cmp_w.push_back(make_pair(a+1,b));
                flag = 1;
                //return dist.front()+1;
            }
            visited[a+1][b] = 1;
            qu.push_back(make_pair(a+1,b));
            dist.push_back(dist.front()+1);
        }
        qu.pop_front();
        dist.pop_front();
    }
    return -1;
}

int main(){
    cin >> N;
    for(int i = 0; i<N ;i++){
        for(int j = 0; j<N; j++){
            cin >> map[i][j];
            if(map[i][j] == 9){
                //q.push_back(make_pair(i,j));
                where = make_pair(i,j);
                map[i][j] = 0;
            } 
        }
    }
    int temp;
    while(1){
        //cout << "where: " << where.first << " " << where.second << endl;
        //cout << "size: " << size << endl;
        temp = find_smallone();
        if(temp == -1){
            cout << result << endl;
            break;
        }
        result += temp;
        eat+=1;
        if(eat == size){
            size+=1;
            eat = 0;
        }
    }
    return 0;
}