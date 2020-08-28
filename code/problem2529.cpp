#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int k;
vector<int> max_num;
vector<int> min_num;
vector<int> real_max;
vector<int> real_min;
int max_check[10];
int min_check[10];
vector<int> sign;
int maxflag = 0;
int minflag = 0;

int max_find_sol(int n){
    if(maxflag == 1){
        return 0;
    }
    if(n == k+1){
        maxflag = 1;
        return 1;
    }
    for(int i = 9; i>=0 ; i--){
        if(maxflag == 1){
            break;
        }
        if(max_check[i] != 0){
            continue;
        }
        if(n == 0){
            max_num.push_back(i);
            max_check[i] = 1;
            max_find_sol(n+1);
            if(maxflag == 1){
                break;
            }
            max_check[i] = 0;
            max_num.pop_back();
        }
        else if(sign[n-1] == 1){
            if(max_num.back() < i){
                max_num.push_back(i);
                max_check[i] = 1;
                max_find_sol(n+1);
                if(maxflag == 1){
                    break;  
                }
                max_check[i] = 0;
                max_num.pop_back();
            }
        }
        else if(sign[n-1] == 0){
            if(max_num.back() > i){
                max_num.push_back(i);
                max_check[i] = 1;
                max_find_sol(n+1);
                if(maxflag == 1){
                    break;  
                }
                max_check[i] = 0;
                max_num.pop_back();
            }
        }
    }
    return 0;
}

int min_find_sol(int n){
    if(minflag == 1){
        return 0;
    }
    if(n == k+1){
        minflag = 1;
        return 1;
    }
    for(int i = 0; i<=9 ; i++){
        if(minflag == 1){
            break;
        }
        if(min_check[i] != 0){
            continue;
        }
        if(n == 0){
            min_num.push_back(i);
            min_check[i] = 1;
            min_find_sol(n+1);
            if(minflag == 1){
                break;
            }
            min_check[i] = 0;
            min_num.pop_back();
        }
        else if(sign[n-1] == 1){
            if(min_num.back() < i){
                min_num.push_back(i);
                min_check[i] = 1;
                min_find_sol(n+1);
                if(minflag == 1){
                    break;  
                }
                min_check[i] = 0;
                min_num.pop_back();
            }
        }
        else if(sign[n-1] == 0){
            if(min_num.back() > i){
                min_num.push_back(i);
                min_check[i] = 1;
                min_find_sol(n+1);
                if(minflag == 1){
                    break;  
                }
                min_check[i] = 0;
                min_num.pop_back();
            }
        }
    }
    return 0;
}

int main(){
    cin >> k;
    char temp;
    for(int i = 0; i<k ;i++){
        cin >> temp;
        if(temp == '<'){
            sign.push_back(1);
        }
        else{
            sign.push_back(0);
        }
    }

    max_find_sol(0);
    min_find_sol(0);

    for(int i = 0; i<k+1;i++){
        printf("%d",max_num[i]);
    }
    printf("\n");
    for(int i = 0; i<k+1;i++){
        printf("%d",min_num[i]);
    }

    return 0;
}
