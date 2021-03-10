#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

int N;
deque<int> superviser;
deque<int> person;


int main(){
    cin >> N;
    int temp;
    for(int i = 0; i<N; i++){
        cin >> temp;
        person.push_back(temp);
    }

    cin >> temp;
    superviser.push_back(temp);
    cin >> temp;
    superviser.push_back(temp);

    long long result = 0;

    for(int i = 0 ; i <person.size(); i++){
        int k = person[i];
        if(k > 0){
            result+=1;
        }
        k-=superviser[0];
        if(k <= 0) continue;
        result += (k/superviser[1]);
        k%=superviser[1];
        if(k != 0) result++;
    }
    cout << result << endl;
    return 0;
}