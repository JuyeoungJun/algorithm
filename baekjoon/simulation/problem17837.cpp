#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct horse
{
	int x, y, d;
} h[10];

int N, K;
int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };
int turn[] = { 0, 2, 1, 4, 3 };
int color[13][13];
vector<int> info[13][13];

int move(int i)
{
	int tx = h[i].x + dx[h[i].d];
	int ty = h[i].y + dy[h[i].d];

	// 2. 경계를 넘거나 파란 칸
	if (tx <= 0 || ty <= 0 || tx > N || ty > N || color[tx][ty] == 2)
	{
		// 방향 전환
		h[i].d = turn[h[i].d];

		tx = h[i].x + dx[h[i].d];
		ty = h[i].y + dy[h[i].d];

		// 반대 방향도 파랑
		if (tx <= 0 || ty <= 0 || tx > N || ty > N || color[tx][ty] == 2)
			return 0;
	}
	vector<int> &cur = info[h[i].x][h[i].y];
	vector<int> &next = info[tx][ty];
	auto s = find(cur.begin(), cur.end(), i);

	// 3. 빨간 칸 - 뒤집기
	if (color[tx][ty] == 1)
		reverse(s, cur.end());

	// 4. 이동
	for (auto it = s; it != cur.end(); ++it)
	{
		h[*it].x = tx, h[*it].y = ty;
		next.push_back(*it);
	}
	cur.erase(s, cur.end());
	return next.size();
}

int simulation()
{
	register int round, i, tx, ty, stack_cnt;

	for (round = 1; round <= 1000; ++round)
	{
		for (i = 0; i < K; ++i)
		{
			// 1. 자기 차레에 이동
			stack_cnt = move(i);

			// 5. 말이 4 이상 쌓이면 종료
			if (stack_cnt >= 4) return round;
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	register int i, j;
	for (i = 1; i <= N; ++i)
		for (j = 1; j <= N; ++j)
			cin >> color[i][j];

	for (i = 0; i < K; ++i)
	{
		horse& ho = h[i];
		cin >> ho.x >> ho.y >> ho.d;
		info[ho.x][ho.y].push_back(i);
	}
	cout << simulation();
	return 0;
}