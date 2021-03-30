#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int temp;
    vector<int> result;
    scanf("%d",&n);
    for(int i = 0; i<n ; i++){
        if(i == 0){
            scanf("%d",&temp);
            result.push_back(temp);
            continue;
        }
        scanf("%d",&temp);
        if(result.back() >= 0){
            temp += result.back();
            result.push_back(temp);
        }
        else{
            result.push_back(temp);
        }
    }
    int max = -987654321;
    for(int i = 0; i<result.size(); i++){
        if(result[i] > max){
            max = result[i];
        }
    }
    printf("%d\n",max);
    return 0;
}