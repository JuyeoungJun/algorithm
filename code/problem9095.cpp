#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int result = 0;

void findSol(int n){
    if(n == 0){
        result ++;
        return;
    }
    if(n < 0){
        return;
    }
    for(int i = 1; i<=3 ; i++ ){
        findSol(n-i);
    }
}

int main(){
    int T, n;
    vector <int> temp;
    cin >> T;
    for(int i = 0; i<T ; i++){
        cin >> n;
        result = 0;
        findSol(n);
        cout << result << endl;
    }
    return 0;
}