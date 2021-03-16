#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <map>

using namespace std;

deque<char> num;
deque<char> oper;
map<char, int> prior;

void popOper(){
    while(!oper.empty()){
        char what = oper.back();
        oper.pop_back();
        if(what == '(') break;
        cout << what;
    }
}

void popLowPriorOper(char what){
    while(!oper.empty()){
        char temp = oper.back();
        if(prior[what] <= prior[temp]){
            cout << temp ; 
        }
        else{
            break;
        }
        oper.pop_back();
    }
}

void popAll(){
    while(!oper.empty()){
        cout << oper.back();
        oper.pop_back();
    }
}

int main(){

    string input;
    cin >> input;
    prior['*'] = 3;
    prior['/'] = 3;
    prior['+'] = 2;
    prior['-'] = 2;
    prior['('] = 1;

    int index = 0;
    while(1){
        if(index == input.size()) break;
        if(input[index] >= 'A' && input[index] <= 'Z'){
            cout << input[index];
        }
        else{
            if(input[index] == ')'){
                popOper();
                index++;
                continue;
            }
            else if(input[index] == '('){
                oper.push_back(input[index]);
            }
            else{
                popLowPriorOper(input[index]);
                oper.push_back(input[index]);
            }
        }
        index++;
    }
    popAll();
    return 0;
}