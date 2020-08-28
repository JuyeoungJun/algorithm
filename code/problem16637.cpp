#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

int N;
int num[11];
char cal[10];
int check[10];
int max_n = -987654321;
int l = 0;

int calcul(){
    int n_idx=0;
    int flag = 0;
    vector<int> result_n;
    vector<char> result_c;
    for(int i = 0; i<l i++){
        if(flag == 1){
            if(n_idx < l+1){
                result_c
            }
            flag = 0;
            continue;
        }
        if(check[i] == 1){
            int temp;
            if(cal[i] == '+'){
                temp = num[n_idx] + num[n_idx+1];
            }
            else if(cal[i] == '-'){
                temp = num[n_idx] - num[n_idx+1];
            }
            else{
                temp = num[n_idx] * num[n_idx+1];
            }
            flag = 1;
            n_idx+=2;
            result_n.push_back(temp);
        }
        else{
            result_n.push_back(num[n_idx]);
            result_c.push_back(cal[i]);
            n_idx++;
        }
    }
}

int find_sol(int le){
    
    if(le == l){
        for(int i = 0; i<le ; i++){
            cout << check[i] << " ";
        }
        cout << endl;
        return 0;
    }
    if(le == 0){
        check[le] = 1;
        find_sol(le+1);
        check[le] = 0;
        find_sol(le+1);
    }
    else{
        
        if(check[le-1] == 1){
            check[le] = 0;
            find_sol(le+1);
        }
        else{
            check[le] = 1;
            find_sol(le+1);
            check[le] = 0;
            find_sol(le+1);
        }
    }
    return 0;
}

int main(){
    char temp[20];
    cin >> N;
    cin >> temp ;
    for(int i = 0 ; i<N ; i++){
        if(i%2 == 0){
            num[i/2] = temp[i] - '0';
        }
        else{
            cal[i/2+1] = temp[i];
            l++;
        }
    }
    find_sol(0);
    return 0;
}