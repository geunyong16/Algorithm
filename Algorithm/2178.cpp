#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, M, cnt = 0;
int arr[104][104];
int visited[104][104];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void BFS() {
	queue<pair<int, int>> que;
	visited[0][0] = 1;
	que.push({ 0,0 });
	while (!que.empty()) {
		int y = que.front().first;
		int x = que.front().second;
		que.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (arr[ny][nx] == 0 || visited[ny][nx] != 0) continue;
			visited[ny][nx] = visited[y][x] + 1;
			que.push({ ny,nx });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	string ipt;
	for (int i = 0; i < N; ++i) {
		cin >> ipt;
		for (int j = 0; j < ipt.size(); ++j) {
			int temp = ipt[j] - '0';
			arr[i][j] = temp;
		}
	}

	BFS();

	cout << visited[N - 1][M - 1] << '\n';
	return 0;
}