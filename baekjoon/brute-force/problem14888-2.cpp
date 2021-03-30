#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

int N;
int A[12];
int sign[4] = {0,0,0,0};
deque<int> order;
int M_answer = -987654321;
int m_answer = 987654321;
int cal(){
    int result = A[0];
    int where = 1;
    for(int i = 0; i<order.size(); i++){
        if(order[i] == 0){
            result += A[where];
            where++;
        }
        else if(order[i] == 1){
            result -= A[where];
            where++;
        }
        else if(order[i] == 2){
            result *= A[where];
            where++;
        }
        else if(order[i] == 3){
            result /= A[where];
            where++;
        }
    }

    return result;
}

int sol(int depth){
    if(depth == N-1){
        int cmp = cal();
        M_answer = max(M_answer,cmp);
        m_answer = min(m_answer,cmp);
        return 0;
    }
    for(int i = 0; i<4; i++){
        if(sign[i] > 0){
            sign[i]--;
            order.push_back(i);
            sol(depth+1);
            sign[i]++;
            order.pop_back();
        }
    }
    return 0;
}


int main(){
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> A[i];
    }

    for(int i = 0; i<4; i++){
        cin >> sign[i];
    }


    sol(0);

    cout << M_answer << endl;
    cout << m_answer << endl;
    return 0;
}