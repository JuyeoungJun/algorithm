#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

int main(){
    int S;
    scanf("%d",&S);
    int t = 0;
    int result = 1;
    while(1){
        if(result == S){
            printf("%d\n",t);
            break;
        }
        else if(result < S){
            result *= 2;
            t += 2;
        }
        else{
            t += result-S;
            result = S;
        }
    }
    return 0;
}