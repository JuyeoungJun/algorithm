#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> smallPerson;
    int s,k,stemp,l;
    vector<int> temp;
    vector<int> remember;
    for(int i = 0; i<9 ; i++){
        cin >> k;
        smallPerson.push_back(k);
        s += k;
    }
    sort(smallPerson.begin(),smallPerson.end());
    temp.push_back(0);
    temp.push_back(0);
    for(int i = 0 ; i < 7 ; i++){
        temp.push_back(1);
    }
    sort(temp.begin(),temp.end());
    sort(smallPerson.begin(),smallPerson.end());
    do{
        s = 0;
        for(int i = 0 ; i<9 ; i++){
            if(temp[i] == 1){
                s += smallPerson[i];
                remember.push_back(smallPerson[i]);
            }
        }
        if(s == 100){
            for(int i = 0 ; i<7 ; i++){
                cout << remember[i] << "\n";
            }
            return 0;
        }
        else{
            l = remember.size();
            for(int i = 0 ; i<l ; i++){
                remember.pop_back();
            }
            
        }
    }while(next_permutation(temp.begin(),temp.end()));

    return 0;
}