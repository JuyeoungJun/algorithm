#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<int> result;
vector<vector<int> > check;
vector<int> usecheck;
int N,M;
vector<int> temp;
vector<vector<int> > fina;

int findResult(int depth){
    int flag = 0;
    if(depth == M){/*
        for(int i = 0 ; i<check.size(); i++){
            flag = 0;
            for(int j = 0; j<M;j++){
                if(check[i][j] == result[j]) {
                    flag++;
                }
            }
            if(flag == M){
                flag = 0;
                return 0;
            }
        }
        for(int i = 0; i< M ;i++){
            printf("%d ",result[i]);
        }
        printf("\n");
        */
        for(int i = 0; i<M ;i++){
            temp.push_back(result[i]);
        }
        check.push_back(temp);
        for(int i = 0; i<M; i++){
            temp.pop_back();
        }
        
        return 0;
    }
    for(int i = 0; i<N ; i++){
        if(usecheck[i] == 0){
            result.push_back(arr[i]);
            usecheck[i] = 1;
            findResult(depth+1);
            result.pop_back();
            usecheck[i] = 0;
        }
    }
    return 0;
}

int main(){
    int temp;
    cin >> N >> M;
    for(int i = 0 ; i<N ; i++){
        scanf("%d",&temp);
        arr.push_back(temp);
        usecheck.push_back(0);
    }
    sort(arr.begin(),arr.end());
    findResult(0);
    sort(check.begin(),check.end());
    fina.push_back(check[0]);
    for(int i = 0; i<M ; i++){
        printf("%d ",fina[0][i]);
    }
    printf("\n");
    int fl = 0;
    for(int i = 1; i<check.size();i++){
        fl = 0;
        for(int j = 0; j<M;j++){
            if(fina[fina.size()-1][j] == check[i][j]){
                fl ++;
            }
        }
        //cout << fl << endl;
        if(fl == M){
            continue;
        }
        for(int j = 0; j<M ; j++){
            printf("%d ",check[i][j]);
        }
        printf("\n");
        fina.push_back(check[i]);
    }
    return 0;
}