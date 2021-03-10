#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int temp;
vector<int> num;
vector<vector<int> > pre;
int ind;
int Sol(int depth,vector<int> result){
    if(depth == M){
        for(int i = 0; i<ind;i++){
            if(pre[i] == result){
                return 0;
            }
        }
        for(int i = 0; i<M ; i++){
            printf("%d ",result[i]);
        }
        printf("\n");
        pre.push_back(result);
        ind++;
        return 0;
    }
    for(int i = 0;i<N;i++){
        if(num[i] >= result.back()){
            result.push_back(num[i]);
            Sol(depth+1,result);
            result.pop_back();
        }
    }
    return 0;
}

int main(){
    vector<int> result;
    scanf("%d %d",&N,&M);
    
    for(int i = 0; i<N ;i++){
        scanf("%d",&temp);
        num.push_back(temp);
    }
    sort(num.begin(),num.end());
    for(int i = 0; i<N;i++){
        result.push_back(num[i]);
        Sol(1,result);
        result.pop_back();
    }
    
    return 0;
}