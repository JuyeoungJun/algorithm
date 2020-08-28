#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

deque<int> test(deque<int> a){
    a.push_back(0);
    a.push_back(1);
    return a;
}

int main(){
    deque<int> b;
    b = test(b);
    cout << b.size();
    return 0;
}