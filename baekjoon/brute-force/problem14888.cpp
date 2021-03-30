#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    int num[N];
    int sig[4];
    int temp;
    vector<int> sol;
    for(int i = 0 ; i< N ; i++){
        scanf("%d",&num[i]);
    }
    for(int i = 0; i<4; i++){
        scanf("%d",&temp);
        for(int j = 0; j<temp ; j++){
            sol.push_back(i);
        }
    }
    int ma = -987654321;
    int mi = 987654321;
    do{
        temp = num[0];
        for(int i = 0; i<sol.size();i++){
            if(sol[i] == 0){
                temp += num[i+1];
            }
            else if(sol[i] == 1){
                temp -= num[i+1];
            }
            else if(sol[i] == 2){
                temp *= num[i+1];
            }
            else{
                if(temp < 0 ){
                    temp = -temp;
                    temp /= num[i+1];
                    temp = -temp;
                    continue;
                }
                temp /= num[i+1];
            }
        }
        if(ma < temp) ma=temp;
        if(mi > temp) mi=temp;
    }while(next_permutation(sol.begin(),sol.end()));
    printf("%d\n%d\n",ma,mi);
    return 0;
}