#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<pair<int,int> >pt;
int map[100][100];
void make_dragon(vector<pair<int, int> > &pt,int cnt,int g){
	pair<int,int> dis;
	pair<int,int> prev;
	prev = make_pair(pt[pt.size()-1].first,pt[pt.size()-1].second);
	if(cnt == g) return;
	for(int i = pt.size()-1; i>0 ; i--){
		dis = make_pair(pt[i].first - pt[i-1].first,pt[i].second - pt[i-1].second);
		cout << "dis:"<< dis.first << " " << dis.second << endl;
		pt.push_back(make_pair(prev.first + dis.second,prev.second - dis.first));
		cout << "prev:"<<pt[pt.size()-1].first<<" " << pt[pt.size()-1].second << endl;
		prev = make_pair(prev.first + dis.second,prev.second - dis.first);
		map[pt[pt.size()-1].first][pt[pt.size()-1].second] = 1;
	}
	for(int i = 0; i < 10; i++){
		for(int j = 0 ; j < 10; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	make_dragon(pt,cnt+1,g);

	
}
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int main(){
	int N,x,y,d,g;
	cin >> N;
	for(int i = 0; i<N ; i++){
		pt.resize(0);
		cin >> x >> y >> d >> g;
		map[x][y] = 1;
		map[x+dx[d]][y+dy[d]] = 1;
		pt.push_back(make_pair(x,y));
		pt.push_back(make_pair(x+dx[d],y+dy[d]));
		make_dragon(pt,0,g);
	}
	cout << endl;
	for(int i = 0; i < 10; i++){
		for(int j = 0 ; j < 10; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
