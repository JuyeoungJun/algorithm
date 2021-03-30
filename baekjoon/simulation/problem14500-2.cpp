#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

int N,M;

int board[501][501];

int result = 0;
//-----
int check_a(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M-3; j++){
            int s = 0;
            s += board[i][j];
            s += board[i][j+1];
            s += board[i][j+2];
            s += board[i][j+3];
            result = max(result,s);
        }
    }

    for(int i = 0; i<N-3; i++){
        for(int j = 0; j<M; j++){
            int s = 0;
            s += board[i][j];
            s += board[i+1][j];
            s += board[i+2][j];
            s += board[i+3][j];
            result = max(result,s);
        }
    }

    return result;
}

//ㅁ
int check_b(){
    for(int i = 0; i<N-1; i++){
        for(int j = 0 ; j<M-1; j++){
            int s = 0;
            s += board[i][j];
            s += board[i+1][j];
            s += board[i][j+1];
            s += board[i+1][j+1];
            result = max(result,s);
        }
    }
    return result;
}

//ㄴ
int check_c(){
    for(int i = 0; i<N-2; i++){
        for(int j = 0; j<M-1; j++){
            int s = 0;
            s += board[i][j];
            s += board[i+1][j];
            s += board[i+2][j];
            s += board[i+2][j+1];
            result = max(result,s);
        }
    }
    for(int i = 0; i<N-2; i++){
        for(int j = 1; j<M; j++){
            int s = 0;
            s += board[i][j];
            s += board[i+1][j];
            s += board[i+2][j];
            s += board[i+2][j-1];
            result = max(result,s);
        }
    }

    for(int i = 0; i<N-2; i++){
        for(int j = 0; j<M-1; j++){
            int s = 0;
            s += board[i][j+1];
            s += board[i+1][j];
            s += board[i+2][j];
            s += board[i+2][j];
            result = max(result,s);
        }
    }

    for(int i = 0; i<N-2; i++){
        for(int j = 1; j<M; j++){
            int s = 0;
            s += board[i][j-1];
            s += board[i+1][j];
            s += board[i+2][j];
            s += board[i+2][j];
            result = max(result,s);
        }
    }
    
    for(int i = 0; i<N-2; i++){
        for(int j = 0; j<M-1; j++){
            int s = 0;
            s += board[i][j];
            s += board[i][j+1];
            s += board[i][j+2];
            s += board[i+1][j];
            result = max(result,s);
        }
    }

    for(int i = 0; i<N-1; i++){
        for(int j = 0; j<M-2; j++){
            int s = 0;
            s += board[i][j];
            s += board[i][j+1];
            s += board[i][j+2];
            s += board[i+1][j+2];
            result = max(result,s);
        }
    }

    for(int i = 1; i<N; i++){
        for(int j = 0; j<M-2; j++){
            int s = 0;
            s += board[i][j];
            s += board[i][j+1];
            s += board[i][j+2];
            s += board[i-1][j];
            result = max(result,s);
        }
    }

    for(int i = 1; i<N; i++){
        for(int j = 0; j<M-2; j++){
            int s = 0;
            s += board[i][j];
            s += board[i][j+1];
            s += board[i][j+2];
            s += board[i-1][j+2];
            result = max(result,s);
        }
    }

    return result;

}

int check_d(){

    for(int i = 0; i<N-1; i++){
        for(int j = 0 ; j<M-2; j++){
            int s = 0;
            s += board[i][j];
            s += board[i][j+1];
            s += board[i][j+2];
            s += board[i+1][j+1];
            result = max(result,s);
        }
    }

    for(int i = 1; i<N; i++){
        for(int j = 0 ; j<M-2; j++){
            int s = 0;
            s += board[i][j];
            s += board[i][j+1];
            s += board[i][j+2];
            s += board[i-1][j+1];
            result = max(result,s);
        }
    }

    for(int i = 0; i<N-2; i++){
        for(int j = 0 ; j<M-1; j++){
            int s = 0;
            s += board[i][j];
            s += board[i+1][j];
            s += board[i+2][j];
            s += board[i+1][j+1];
            result = max(result,s);
        }
    }

    for(int i = 0; i<N-2; i++){
        for(int j = 1 ; j<M; j++){
            int s = 0;
            s += board[i][j];
            s += board[i+1][j];
            s += board[i+2][j];
            s += board[i+1][j-1];
            result = max(result,s);
        }
    }

    return result;

}

int check_f(){
    for(int i = 0 ; i<N-2; i++){
        for(int j = 0; j<M-1; j++){
            int s= 0;
            s += board[i][j];
            s += board[i+1][j];
            s += board[i+1][j+1];
            s += board[i+2][j+1];
            result = max(result,s);
        }
    }

    for(int i = 0 ; i<N-2; i++){
        for(int j = 1; j<M; j++){
            int s= 0;
            s += board[i][j];
            s += board[i+1][j];
            s += board[i+1][j-1];
            s += board[i+2][j-1];
            result = max(result,s);
        }
    }

    for(int i = 0 ; i<N-1; i++){
        for(int j = 0; j<M-2; j++){
            int s= 0;
            s += board[i][j];
            s += board[i][j+1];
            s += board[i+1][j+1];
            s += board[i+1][j+2];
            result = max(result,s);
        }
    }

    for(int i = 0 ; i<N-1; i++){
        for(int j = 2; j<M; j++){
            int s= 0;
            s += board[i][j];
            s += board[i][j-1];
            s += board[i+1][j-1];
            s += board[i+1][j-2];
            result = max(result,s);
        }
    }
    return result;
}


int main(){
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> board[i][j];
        }
    }

    check_a();
    check_b();
    check_c();
    check_d();
    check_f();
    cout << result << endl;
    return 0;
}