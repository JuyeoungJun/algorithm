#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int n, w, L;
deque<int> truck;
deque<int> onBriedge;

int main(){

    cin >> n >> w >> L;
    int temp;
    for(int i = 0; i<n; i++){
        cin >> temp;
        truck.push_back(temp); 
    }

    for(int i = 0; i<w; i++){
        onBriedge.push_back(0);
    }
    int t = 1;
    int s = 0;
    while(!truck.empty()){
        if(onBriedge.front() != 0){
            s -= onBriedge.front();
        }
        onBriedge.pop_front();
        if(truck.front() + s <= L){
            onBriedge.push_back(truck.front());
            s += truck.front();
            truck.pop_front();
        }
        else{
            onBriedge.push_back(0);
        }
        t++;
    }
    cout << t+w-1 << endl;
    return 0;
}