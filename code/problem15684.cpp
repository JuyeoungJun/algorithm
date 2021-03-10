#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int N,M,H;
int mi = 987654321;

int check_result(int arr[32][32]){
    int where;
    for(int i = 0; i<N; i++){
        where = i;
        for(int j = 0; j<H ;j++){
            
            where += arr[j][where];
        }
        if(where == i){
            continue;
        }
        else{
            return -1;
        }
    }
    return 1;
}

int find_Sol(int mline,int arr[32][32]){

    for(int i = 0; i<H; i++ ){
        for(int j = 0; j<N-1; j++){
            if(arr[i][j] == 0 && arr[i][j+1] == 0 ){
                arr[i][j] = 1;
                arr[i][j+1] = -1;
               
                if(check_result(arr) == 1){
                    mi = min(mi,mline+1);
                    
                    arr[i][j] = 0;
                    arr[i][j+1] = 0;
                    return mi;
                }
                if(mline <= 1) {
                    find_Sol(mline+1,arr);
                }
                arr[i][j] = 0;
                arr[i][j+1] = 0;
            }
        }
    }

    return mi;
}
int main(){
    int a,b;
    scanf("%d %d %d",&N,&M,&H);
    int arr[32][32];
    for(int i = 0; i<30; i++){
        for(int j = 0; j<30 ;j++){
            arr[i][j] = 0;
        }
    }
    for(int i = 0 ; i<M ; i++){
        cin >> a >> b;
        arr[a-1][b-1] = 1;
        arr[a-1][b] = -1;
    }
    if(M == 0){
        cout << "0" << endl;
        return 0;
    }
    if(check_result(arr) == 1){
        cout << "0" << endl;
        return 0;
    }
    mi = find_Sol(0,arr);
    if(mi == 987654321){
        cout << "-1" << endl;
    }
    else{
        cout << mi << endl;
    }
    return 0;
}