#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;
#define MAX 505

///이해해보기

int dis[MAX][MAX];
int dp[MAX][MAX];
int N, K;
vector<pair<int, int> > v;

int solve(int idx, int k) {
	if (idx == 1)return 0;
	if (dp[idx][k]!=-1) return dp[idx][k];

	int min_n = 987654321;
	for (int i = 0; i <= k; i++) {
		if (idx - i-1 < 1) break;
		min_n = min(solve(idx - i-1, k - i) + dis[idx-i-1][idx], min_n);
	}

    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

	return dp[idx][k] = min_n;
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N-1; i++) {
		for (int j = i+1; j <= N-1; j++) {
			dis[i+1][j+1] = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
		}
	}
	cout << solve(N, K) << '\n';

    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}