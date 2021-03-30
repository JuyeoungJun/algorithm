#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int N, M;

struct home{
    int a;
    int b;
};

struct chick{
    int a;
    int b;
};

deque<home> h;
deque<chick> c;
deque<int> what;
int answer = 987654321;

int cal(){
    
    int result = 0;
    for(int i = 0; i<h.size(); i++){
        int m = 987654321;
        for(int j = 0; j<what.size(); j++){
            m = min(abs(h[i].a-c[what[j]].a)+abs(h[i].b-c[what[j]].b),m);
        }
        result+= m;
    }
    answer = min(answer,result);
    return result;
}

int sol(int where){
    if(what.size() != 0) cal();

    if(what.size() == M){
        return 0;
    }

    for(int i = where; i<c.size(); i++){
        what.push_back(i);
        sol(i+1);
        what.pop_back();
    }

    return 0;
}

int main(){
    cin >> N >> M;
    int temp;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> temp;
            if(temp ==  1){
                home ht;
                ht.a = i;
                ht.b = j;
                h.push_back(ht);
            }
            else if(temp == 2){
                chick tc;
                tc.a = i;
                tc.b = j;
                c.push_back(tc);
            }
        }
    }

    sol(0);

    cout<<answer<<endl;
    return 0;
}