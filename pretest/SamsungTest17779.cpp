#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;
int N,maxx,minn;
int map[21][21];
int visit[21][21];
int people[5];
int ans = 987654321;

void devide(int x,int y, int done, int dtwo){
	memset(people,0,sizeof(people));
	memset(visit,0,sizeof(visit));
	for(int i = 0; i<=done; i++)
	{
		visit[x+i][y-i] = 1;
		visit[x+dtwo+i][y+dtwo-i] = 1;
		people[4] += map[x+i][y-i] + map[x+dtwo+i][y+dtwo-i];
	}
	for(int i = 1; i<dtwo; i++){
		visit[x+i][y+i] = 1;
		visit[x+done+i][y-done+i] = 1;
		people[4] += map[x+i][y+i] + map[x+done+i][y-done+i];
	}

	for(int i = 0; i<done; i++){
		int j = 0;
		while(!visit[x+i+j+1][y-i]){
			visit[x+i+j+1][y-i] = 1;
			people[4] += map[x+i+j+1][y-i];
			j++;
		}
	}
	for(int i = 1; i<dtwo; i++){
		int j = 0;
		while(!visit[x+i+j+1][y+i]){
			visit[x+i+j+1][y+i] = 1;
			people[4] += map[x+i+j+1][y+i];
			j++;
		}
	}
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			if(visit[i][j] == 1) continue;
			if(i<x+done && j <= y){
				people[0] += map[i][j];
			}
			else if(i<=x+dtwo && y<j){
				people[1] += map[i][j];
			}
			else if(x+done <= i && j<y-done+dtwo){
				people[2] += map[i][j];
			}
			else if(x+dtwo < i && y-done+dtwo <= j){
				people[3] += map[i][j];
			}
		}
	}
//	cout<< people[4]<<endl;
	pair<int *,int*> p = minmax_element(people,people+5);
	ans = min(ans,int(*p.second - *p.first));
	//cout << "ans:"<<ans <<endl;
}

void getScore(int x, int y){
	for(int i = 1; i<N-1; i++){
		for(int j = 1 ; j<N-1 ; j++){
			if(x+i+j <= N && y+j <= N && y-j >= 1)
				devide(x,y,i,j);
		}
	}
}
int main(){
	cin >> N;
	int result = 0;
	for(int i = 1; i<= N; i++){
		for(int j = 1 ; j<=N ; j++){
			cin >> map[i][j];
		}
	}
	
	for(int i = 1; i<N; i++){
		for(int j = 2; j<N; j++){
			getScore(i,j);
		}
	}
	cout << ans;
}
