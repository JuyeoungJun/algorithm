#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,M;
void find_sol(vector<int> solu, int check[], int count ){
    
    if(count == M){
        for(int i = 0; i < M; i++){
            printf("%d ",solu[i]);
        }
            printf("\n");
        return ;
    }

    for(int i = 0; i < N; i++){
        if(check[i] == 0){
            solu.push_back(i+1);
            check[i] = 1;
            count ++;
            find_sol(solu, check, count);
            solu.pop_back();
            check[i] = 0;
            count --;
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    vector<int> solu;
    int check[N];
    
    for(int i = 0; i<N; i++){
        check[i] = 0;
    }
    
    int count = 0;
    find_sol(solu,check,count);
    return 0;
}