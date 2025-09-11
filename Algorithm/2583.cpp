#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [0][0] ~ [M][N]
// size = (M+1)x(N+1)
int visited[104][104];
vector<int> s;
int M, N, K, cnt;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };


int DFS(int y, int x) {
	visited[y][x] = 1;
	int sz = 1;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
		if (visited[ny][nx]) continue;
		sz += DFS(ny, nx);
	}

	return sz;
}

int main() {
	cin >> M >> N >> K;
	int s_x, s_y, l_x, l_y;
	for (int i = 0; i < K; ++i) {
		cin >> s_x >> s_y >> l_x >> l_y;
		for (int j = s_y; j < l_y; ++j) {
			for (int t = s_x; t < l_x; ++t) {
				visited[j][t] = 1;
			}
		}
	}

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (visited[i][j] == 0) {
				s.push_back(DFS(i, j));
				++cnt;
			}
		}
	}

	sort(s.begin(), s.begin() + cnt);

	cout << cnt << '\n';
	for (int t : s)
		cout << t << " ";
	return 0;
}