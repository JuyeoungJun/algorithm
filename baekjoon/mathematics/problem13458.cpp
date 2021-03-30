#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cmath>
#include <typeinfo>

using namespace std;

int main(){
    int N,B,C;
    cin >> N;
    vector<long long> A;
    int temp;
    for(int i = 0 ; i<N ; i++){
        cin >> temp;
        A.push_back(temp);        
    } 
    cin >> B >> C;
    long long result = N;
    for(int i = 0; i<N ; i++){
        if(A[i] == 0){
            result --;
            continue;
        }
        A[i] -= B;
    }
   
    for(int i = 0; i<N ; i++){
        if(A[i] <= 0 ){
            continue;
        }
        if((A[i]%C) == 0){
            result += A[i] / C;
        }
        else{
            result += A[i]/C + 1;
        }
        A[i] = 0;
    }
    printf("%lld",result);
    return 0;
}