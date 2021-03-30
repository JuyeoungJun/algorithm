#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int M,N,k,a,b;
    cin >> a >> b;
    k = min(a,b);
    for(int i = 1; i<=k ; i++){
        if(a%i == 0 && b%i == 0){
            M = i;
        }
    }
    N = (a/M)*(b/M)*M;
    cout << M << endl;
    cout << N << endl;
    return 0;
}