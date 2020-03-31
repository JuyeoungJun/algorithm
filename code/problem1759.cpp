#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L,C;
vector<char> key;
vector<char> mo;
vector<char> st;
int checkMo(char c){
    for(int i = 0; i<5 ; i++){
        if(mo[i] == c){
            return 1;
        }
    }
    return 0;
}

int findKey(int turn, int mo, int ja){
    if(st.size() == L){
        if(mo >= 1 && ja >= 2){
            for(int i = 0; i<L; i++){
                cout<<st[i];
            }
            cout << endl;
            return 0;
        }
    }
    for(int i = turn; i<C; i++){
        st.push_back(key[i]);
        if(checkMo(key[i]) == 1){
            findKey(i+1,mo+1,ja);
        }
        else{
            findKey(i+1,mo,ja+1);
        }
        st.pop_back();
    }
    return 0;
}

int main(){
    //
    cin >> L >> C;
    char temp;
    for(int i = 0 ; i<C ; i++){
        cin >> temp;
        key.push_back(temp);
    }
    mo.push_back('a');
    mo.push_back('e');
    mo.push_back('i');
    mo.push_back('o');
    mo.push_back('u');
    sort(key.begin(),key.end());
    for(int i = 0; i<C-L+1; i++){
        st.push_back(key[i]);
        if(checkMo(key[i]) == 1){
            findKey(i+1,1,0);
        }
        else{
            findKey(i+1,0,1);
        }
        st.pop_back();
    }  
    return 0;
}