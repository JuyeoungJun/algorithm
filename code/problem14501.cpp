#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int> > day;
int N,T,P;
int fina;

int main(){
    pair<int,int> temp;
    cin >> N;
    for(int i = 0; i < N ; i++){
        cin >> T >> P;
        temp = make_pair(T,P);
        day.push_back(temp);
    }
    int resu[N+1000];
    resu[0] = 0;
    int ttemp = 0;
    int bigger = 0;
    for(int i = 0; i<=N ; i++){
        resu[i] = 0;
    }
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < i; j++){
            resu[i] = max(resu[i],resu[j]);
        }
        resu[i+day[i].first] = max(resu[i+day[i].first],resu[i]+day[i].second);
    }
    for(int i = 0; i<=N ; i++){
        fina = max(fina,resu[i]);
    }
    cout << fina << endl;
    return 0;
}