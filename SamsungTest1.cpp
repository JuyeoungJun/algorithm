#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
	int N;
	cin >> N;
	vector<vector<int> > play(N,vector<int>(9,0));
	vector<int> v(8);
	for(int i = 1; i<9 ; i++){
		v[i-1] = i;
	}
	for(int col = 0; col<N; col++){
		int c;
		for(int row = 0; row<9; row++){
			cin >> play[col][row];
		}
	}
	int maxx= 0;
	int flag = 1;
	int out = 0;
	int outcount = 0;
	int order = 0;
	int score = 0;
	int siz = 0;
	queue<int> board;
	do{
		out = 0;
		outcount = 0;
		order = 0;
		for(int i=0; i<board.size();i++){
			board.pop();
		}
		for(int i=0; i<3; i++){
			board.push(0);
		}
		score = 0;
		while(out<N){
			if(outcount == 3){
				out ++;
				outcount = 0;
				continue;
			}
			if(order<3){
				if(play[out][v[order]] == 0){
					outcount ++;
					order = (order+1)%9;
					continue;
				}
				board.push(1);
				for(int i=0; i<play[out][v[order]]; i++){
					score += board.front();
					board.pop();
				}
				siz = board.size();
				for(int i=0; i<3-siz; i++){
					board.push(0);
				}
				order = (order + 1)%9;

			}
			else if(order == 3){
				if(play[out][0] == 0){
					outcount ++;
					order = (order + 1)%9;
					continue;
				}
				board.push(1);
				for(int i=0; i<play[out][0]; i++){
					score += board.front();
					board.pop();
				}
				siz = board.size();
				for(int i=0; i<3-siz; i++){
					board.push(0);
				}
				order = (order + 1)%9;

			}
			else{
				if(play[out][v[order-1]] == 0){
					outcount ++;
					order = (order + 1)%9;
					continue;
				}
				board.push(1);
				for(int i=0; i<play[out][v[order-1]]; i++){
					score += board.front();
					board.pop();
				}
				siz = board.size();
				for(int i=0; i<3-siz; i++){
					board.push(0);
				}
				order = (order + 1)%9;

			}
		}
		maxx = max(score,maxx);
	}while(next_permutation(v.begin(),v.end()));
	cout<<maxx<<endl;
	return 0;
}

