#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

deque<pair<int, int> > home;
deque<pair<int, int> > chick;
deque<pair<int, int> > choose;
int N,M;
int chick_h = 0;
int cost = 987654321;
//int mapp[51][51];

int find_distance(int where){
    int result = 987654321;
    int ftemp;
    int stemp;
    for(int i = 0; i<M ; i++){
        result = min(result,abs(home[where].first-choose[i].first)+abs(home[where].second-choose[i].second));
    }
    //cout << result << endl;
    return result;
}

void find_Chick(int howmuch,int where){
    //cout << choose.size() << endl;
    if(howmuch == M){
        int temp = 0;
        for(int i = 0; i<home.size(); i++){
            temp += find_distance(i);
        }
        cost = min(cost,temp);
    }
    for(int i = where; i<chick_h ; i++){
        choose.push_back(chick[i]);
        find_Chick(howmuch+1,i+1);
        choose.pop_back();
    }
}

int main(){
    
    cin >> N >> M;
    int temp;
    for(int i = 0; i <N; i++){
        for(int j = 0; j < N ; j++){
            cin >> temp;
            if(temp == 1){
                //cout << "home: " << i << j << endl; 
                home.push_back(make_pair(i,j));
            }
            else if(temp == 2){
                //cout << "chick: " << i << j << endl;
                chick.push_back(make_pair(i,j));
                chick_h++;
            }
        }
    }
    find_Chick(0,0);
    cout << cost << endl;
    return 0;
}