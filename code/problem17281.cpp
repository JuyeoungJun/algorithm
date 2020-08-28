#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

deque<int> score;
int play[51][10];
int check[10];
int N;
int finresult = 0;
vector<int> order;

int make_order(){
    //cout << order.size() << endl;
    /*
    for(int i = 0; i<9;i++){
        cout << check[i] << " ";
    }
    cout << endl;
    for(int i = 0; i<order.size();i++){
        cout << order[i] << " ";
    }
    cout << endl;*/
    if(order.size() == 9){
        /*
        for(int i = 0; i<9;i++){
            cout << order[i] << " ";
        }
        cout << endl;*/
       int result = 0;
       int outcount = 0;
       int ord = 0;
       int base[3];
       for(int i = 0; i<3 ;i++){
           base[i] = 0;
       }
       for(int i = 0; i<N; i++){
           //cout << "ining: " << i << endl;
           while(1){
               /*
               cout << "ord: "<<ord << endl;
               cout << "outcount: : " << outcount << endl;
               cout << "result: " << result << endl;
               for(int i = 0; i<3; i++){
                   cout << "i" << i<<": " << base[i] << " ";
               }
               cout << endl;*/
               if(play[i][order[ord]] == 0 ){
                   outcount ++;
                   ord = (ord+1)%9;
                   if(outcount == 3){
                       outcount = 0;
                       for(int i = 0; i<3; i++){
                           base[i] = 0;
                       }
                       break;
                   }
               }
               else{
                   if(play[i][order[ord]] ==4){
                       for(int i = 0; i<3 ; i++){
                           
                           if(base[i] == 1){
                               result += 1;
                           }
                           base[i] = 0;
                       }
                       result ++;
                       ord = (ord+1)%9;
                   }
                   else if(play[i][order[ord]] == 3){
                       for(int i =0; i<3 ;i++){
                           if(base[i] == 1){
                               result += 1;
                           }
                           base[i] = 0;
                           
                       }
                       base[2] = 1;
                       ord = (ord+1)%9;
                   }
                   else if(play[i][order[ord]] == 2){
                       for(int i= 1 ;i<3;i++){
                           
                           if(base[i] == 1){
                               result+=1;
                           }
                           base[i] = 0;
                       }
                       if(base[0] == 1){
                           base[2] = 1;
                           base[0] = 0;
                       }
                       base[1] = 1;
                       ord = (ord+1)%9;
                   }
                   else if(play[i][order[ord]] == 1){
                       if(base[2] == 1){
                           result+=1;
                           base[2] = 0;
                       }
                       if(base[1] == 1){
                           base[2] = 1;
                           base[1] = 0;
                       }
                       if(base[0] == 1){
                           base[1] =1;
                           base[0] = 0;
                       }
                       base[0] = 1;
                       ord = (ord+1)%9;
                   }
               }
           }
        }

        //cout << "result: " << result << endl;
        /*
        if(result == 58){
            cout << "hi" << endl;
            exit(1);
        }*/
        finresult = max(result,finresult);
        return finresult;
    }
    if(order.size() == 3){
        order.push_back(0);
        make_order();
        order.pop_back();
    }
    else{
        for(int i = 1; i<9;i++){
            if(check[i] == 0){
                check[i] = 1;
                order.push_back(i);
                make_order();
                check[i] = 0;
                order.pop_back();
            }
        }
    }
    return 0;
}

int main(){
    cin >> N;
    check[0] = 1;
    for(int i = 0; i<N ; i++){
        for(int j = 0; j<9 ; j++){
            cin >> play[i][j];
        }
    }

    make_order();

    cout<<finresult << endl;
    return 0;
}