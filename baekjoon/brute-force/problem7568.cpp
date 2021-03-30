#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N,x,y;
    cin >> N;
    vector<pair<int,int> > people;
    int arr[N];
    for(int i = 0; i < N; i++){
        arr[i] = 1;
    }

    for(int i = 0; i<N ; i++){
        cin >> x >> y;
        people.push_back(make_pair(x,y));
    }
    for(int i = 0; i<N ; i++){
        for(int j = 0; j< N; j++){
            if(i == j) continue;
            if(people[i].first < people[j].first ){
                if(people[i].second < people[j].second){
                    arr[i] ++;
                }
            }
            else if(people[i].first < people[j].first){
                if(people[i].second < people[j].second){
                    arr[i]++;
                }
            }

        }
        cout << arr[i] << " ";
    }
    return 0;
}