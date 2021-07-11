#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

priority_queue<int> M_q;
priority_queue<int,vector<int>,greater<int>> m_q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int inp;
    int mid = 0;
    for(int i = 0; i<N; i++){
        cin >> inp;

        if(m_q.size() == M_q.size()){
            M_q.push(inp);
        }
        else{
            m_q.push(inp);
        }

        if(!m_q.empty() && !M_q.empty() && m_q.top() < M_q.top()){
            int a = M_q.top();
            int b = m_q.top();
            M_q.pop();
            m_q.pop();
            M_q.push(b);
            m_q.push(a);
        }

        cout << M_q.top() << '\n';
    }
    return 0;
}