#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

float meanprice[1001];
int price[1001];
int N;
int result[1001];

int main(){
    cin >> N;
    for(int i = 1; i<=N ; i++){
        cin >> price[i];
    }
    /*
    for(int i = 0; i<1001 ; i++){
        meanprice[i] = price[i]/(i+1);
    }
    meanprice[0] = */
    for(int i = 1; i<1001;i++){
        result[i] = 0;
    }
    result[1] = price[1];
    for(int i = 2;i<=N;i++){
        result[i] = price[i];
        for(int j = 1; j<=i/2;j++){
            //cout << j << endl;
            result[i] = max(result[i],result[j]+result[i-j]);
        }
    }
    cout << result[N] << endl;
    return 0;
}
/*
5
1 6 8 12 10*/