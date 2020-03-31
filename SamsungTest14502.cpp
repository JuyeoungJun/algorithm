#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int map[9][9];
int temp[9][9];
int N,M,result;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void BFS(){
	int afterSpread[9][9];
	for(int i = 0; i<N; i++){
		for(int j = 0 ; j<M ;j++){
			afterSpread[i][j] = temp[i][j];
			
		}
	}
	queue<pair<int,int> > q;
	for(int i = 0; i < N; i++){
		for(int j = 0; j< M; j++){
			if(afterSpread[i][j] == 2)
				q.push(make_pair(i,j));
		}
	}
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for(int i = 0; i<4; i++){
			int nextY = y + dy[i];
			int nextX = x + dx[i];

			if(0 <= nextY && nextY < N && 0<=nextX && nextX < M){
				if(afterSpread[nextY][nextX] == 0)
				{
					afterSpread[nextY][nextX] = 2;
					q.push(make_pair(nextY,nextX));
				}
			}
			
		}
	}
	int safe = 0;
//	cout << "---------------"<<endl;
	for(int i = 0; i<N; i++){
		for(int j = 0; j<M ; j++){
	//		cout << afterSpread[i][j];
			if(afterSpread[i][j] == 0)
				safe++;
		}
//		cout << endl;
	}
	result = max(result,safe);
}
void makewall(int cnt){
	if(cnt == 3){
		BFS();
		return;
	}

	for(int i = 0; i<N; i++){
		for(int j = 0; j<M; j++){
			if(temp[i][j] == 0){
				temp[i][j] = 1;
				makewall(cnt+1);
				temp[i][j] = 0;
			}
		}
	}

}
int main(){
	cin >> N >> M;
	for(int i = 0; i<N ; i++){
		for(int j = 0; j<M; j++){
			cin >> map[i][j];
		}
	}

	for(int i = 0; i<N; i++){
		for(int j = 0; j<M ; j++){
			if(map[i][j] == 0){
				for(int k = 0; k<N; k++){
					for(int l = 0; l<M; l++){
						temp[k][l] = map[k][l];
					}
				}
				temp[i][j] = 1;
				makewall(1);
				temp[i][j] = 0;
			}
		}
	}
	cout << result;

}
