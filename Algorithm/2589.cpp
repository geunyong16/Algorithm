#include <iostream>
#include <queue>
#include <string>
#include <climits>

using namespace std;

string s;
int ret = 0, n, m;
int arr[54][54];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int visited[54][54];

void BFS(int y, int x) {
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> que;
	visited[y][x] = 1;
	que.push({ y,x });

	while (!que.empty()) {
		int cy = que.front().first;
		int cx = que.front().second;
		que.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || arr[ny][nx] == 0 || visited[ny][nx] != 0)
				continue;

			visited[ny][nx] = visited[cy][cx] + 1;
			ret = max(ret, visited[ny][nx] - 1);
			que.push({ ny,nx });
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == 'L')
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (arr[i][j])
				BFS(i, j);
		}
	}


	cout << ret;
	return 0;
}