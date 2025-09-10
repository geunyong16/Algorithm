#include <iostream>
#include <stack>

using namespace std;

int T, N, M, K;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void DFS(int y, int x, int arr[][54], int visited[][54]) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (arr[ny][nx] == 0) continue;
		if (visited[ny][nx]) continue;
		DFS(ny, nx, arr, visited);
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for (int s = 0; s < T; ++s) {
		cin >> M >> N >> K;
		int arr[54][54] = { 0 };
		int visited[54][54] = { 0 };
		int x, y, cnt = 0;
		for (int i = 0; i < K; ++i) {
			cin >> x >> y;
			arr[y][x] = 1;
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (visited[i][j] == 0 && arr[i][j]) {
					DFS(i, j, arr, visited);
					++cnt;
				}
			}
		}

		cout << cnt << '\n';
	}
	return 0;
}