#include <iostream>
#include <deque>
#include <algorithm>
#include <map>

using namespace std;

int r,c,k;
int arr[101][101];
int rc,cc;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;

}
int R_oper(){
    map<int,int> check[rc];
    for(int i = 0; i<rc; i++){
        for(int j = 0; j<cc; j++){
            if(arr[i][j] == 0) continue;
            if(check[i].find(arr[i][j]) != check[i].end()){
                check[i][arr[i][j]]+=1;
            }
            else{
                check[i].insert(pair<int,int>(arr[i][j],1));
            }
        }
    }

    int ct = 0;
    for(int i = 0 ; i<rc; i++){
        deque<pair<int,int> > temp;
        for(auto iter = check[i].begin(); iter != check[i].end(); iter++){
            temp.push_back(make_pair(iter->first,iter->second));
        }
        sort(temp.begin(),temp.end(),cmp);
        int l = temp.size();
        ct = max(ct,l*2);
        for(int j = 0 ; j<temp.size();j++){
            arr[i][2*j] = temp[j].first;
            arr[i][2*j+1] = temp[j].second;
        }
    }
    cc = ct;
    for(int i = 0; i<rc; i++){
        int l = check[i].size();
        for(int j = l*2; j<cc; j++){
            arr[i][j] = 0;
        }
    }
    return 0;
}

int C_oper(){
    map<int,int> check[cc];
    for(int i = 0; i<cc; i++){
        for(int j = 0; j<rc; j++){
            if(arr[j][i] == 0) continue;
            if(check[i].find(arr[j][i]) != check[i].end()){
                check[i][arr[j][i]]+=1;
            }
            else{
                check[i].insert(pair<int,int>(arr[j][i],1));
            }
        }
    }
    int rt = 0;
    for(int i = 0 ; i<cc; i++){
        deque<pair<int,int> > temp;
        for(auto iter = check[i].begin(); iter != check[i].end(); iter++){
            temp.push_back(make_pair(iter->first,iter->second));
        }
        sort(temp.begin(),temp.end(),cmp);
        int l = temp.size();
        rt = max(rt,l*2);
        for(int j = 0 ; j<temp.size();j++){
            arr[2*j][i] = temp[j].first;
            arr[2*j+1][i] = temp[j].second;
        }

    }
    rc = rt;
    for(int i = 0; i<cc; i++){
        int l = check[i].size();

        for(int j = l*2; j<rc; j++){
            arr[j][i] = 0;
        }
    }
    return 0;
}

int main(){
    cin >> r >> c >> k;
    for(int i = 0; i<101; i++){
        for(int j = 0; j<101; j++){
            arr[i][j] = 0;
        }
    }

    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cin >> arr[i][j];
        }
    }

    rc = 3;
    cc = 3;
    int t;
    for(t = 0; t<=100; t++){
        if(arr[r-1][c-1] == k) break;
        if(rc >= cc){
            R_oper();
        }
        else{
            C_oper();
        }

    }
    if(t == 101) t = -1;

    cout << t << endl;


    return 0;
}