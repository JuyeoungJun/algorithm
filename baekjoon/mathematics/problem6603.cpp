#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int k;
    int num[13];
    vector <int> ind;
    int temp;
    while(1){
        scanf("%d",&k);
        if( k == 0){
            break;
        }
        for(int i = 0; i<k; i++){
            scanf("%d",&num[i]);
        }
        for(int i = 0; i<6 ;i++){
            ind.push_back(1);
        }
        for(int i = 0; i<k-6;i++){
            ind.push_back(0);
        }
        do{
            for(int i = 0; i<ind.size();i++){
                if(ind[i] == 1){
                    printf("%d ",num[i]);
                }
            }
            printf("\n");
        }while(prev_permutation(ind.begin(),ind.end()));
        temp = ind.size();
        printf("\n");
        for(int i = 0; i<temp;i++){
            ind.pop_back();
        }
    }
    return 0;
}
