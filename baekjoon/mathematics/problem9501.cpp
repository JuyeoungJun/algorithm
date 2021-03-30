#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <map>

using namespace std;

int main(){
    int T;
    cin >> T;
    int N, D;
    float v,f,c;
    for(int t = 0; t<T; t++){
        cin >> N >> D;
        int result = 0;
        for(int i =  0; i<N ; i++){
            cin >> v >> f >> c;
            if(v*(f/c) >= D) result ++;
        }
        cout << result << endl;
    }


    return 0;
}