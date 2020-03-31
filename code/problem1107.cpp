#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int result;
int N,M;
vector<int> nob;
vector<int> cmp;
int l;
int flag = 0;
int temp;

int findSol(int depth, int endD){
    //printf("%d\n",endD);
    if(depth == endD){
        int change = 0;
        //cout <<"1:" <<cmp[0] << endl;
        for(int i = 0 ; i<cmp.size(); i++){
            //cout<< "cmp" << i << ": " << cmp[i] << " ";
            change = change*10+cmp[i];
        }
        //cout << endl;
        //printf("change: %d\n",change);
        if(result > abs(N-change)+endD){
            result = abs(N-change)+endD;
        }
        
        //printf("%d\n",result);
        return 0;
    }
    for(int i = 0 ; i < nob.size(); i++){
        cmp.push_back(nob[i]);
        findSol(depth+1,endD);
        cmp.pop_back();
    }
    return 0;
}

int main(){
    
    int arr[10] = {0};
    scanf("%d",&N);
    scanf("%d",&M);
    int temp;
    if(M != 0){
        for(int i = 0 ; i<M; i++){
            scanf("%d",&temp);
            arr[temp] = 1;
        }
    }
    //printf("%d\n",arr[9]);
    for(int i = 0; i<10 ; i++){
        if(arr[i] == 0){
            nob.push_back(i);
        }
    }
    temp = N;
    //printf("%d\n",nob.back());
    while(1){
        if(l == 0 && temp == 0){
            l ++;
            break;
        }
        if(temp == 0){
            break;
        }
        temp/=10;
        l++;
    }
    //printf("l: %d\n",l);

    result = abs(100-N);
    if(nob.empty()){
        printf("%d\n",result);
        return 0;
    }
    findSol(0,l);
    if(l > 1){
        findSol(0,l-1);
    }
    findSol(0,l+1);
    /*
    if(flag == 1){
        result += l;
    }*/
    printf("%d\n",result);
    return 0;
}