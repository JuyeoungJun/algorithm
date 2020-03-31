#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    int N,temp;
    vector<int> person;
    cin >> N;
    for(int i = 0; i<N ; i++){
        cin >> temp;
        person.push_back(temp);
    }
    vector<int> sump;
    sort(person.begin(),person.end());
    sump.push_back(person[0]);
    //cout << sump.back();
    
    for(int i = 1; i<N ; i++){
        sump.push_back(sump.back()+person[i]);
    }
    cout << accumulate(sump.begin(),sump.end(),0);
    return 0;
}