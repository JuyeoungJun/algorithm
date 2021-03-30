#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;



int main(){
    int T,N,M;
    cin >> T;
    int left,right,mid;
    bool answer;
    for(int i = 0; i<T; i++){
        cin >> N;
        vector<int> noteo,notet;
        int temp;
        for(int j = 0; j<N; j++){
            cin >> temp;
            noteo.push_back(temp);
        }
        sort(noteo.begin(),noteo.end());

        cin >> M;
        for(int j = 0; j<M; j++){
            cin >> temp;
            notet.push_back(temp);
        }


        for(int j = 0; j<notet.size(); j++){
            left = 0;
            right = N-1;
            answer = false;

            while(left<=right){
                mid = (left+right)/2;
                if(noteo[mid] == notet[j]){
                    answer =true;
                    break;
                }
                if(noteo[mid] < notet[j]){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
            printf("%d\n",answer);
            //cout << answer << endl;
        }
    }
    return 0;
}