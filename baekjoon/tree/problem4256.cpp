#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int preOrder[1001];
int inOrder[1001];

void PostOrder(int s, int e, int root){
    for(int i = s; i<e; i++){
        if(inOrder[i] == preOrder[root]){
            PostOrder(s,i,root+1);
            PostOrder(i+1,e,root+i+1-s);
            cout << preOrder[root] << " ";
        }
    }
}

int main(){
    int T;
    int n;
    cin >> T;
    for(int t = 0; t<T; t++){
        cin >> n;
        for(int i = 0; i<n; i++){
            cin >> preOrder[i];
        } 

        for(int i = 0; i<n; i++){
            cin >> inOrder[i];
        }

        PostOrder(0,n,0);
        cout << endl;

    }

    return 0;
}