#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[104][104];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void DFS(int y, int x, int visited[][104], int i) {
	visited[y][x] = 1;
	for (int k = 0; k < 4; ++k) {
		int ny = y + dy[k];
		int nx = x + dx[k];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (arr[ny][nx] <= i) continue;
		if (visited[ny][nx] == 1) continue;
		DFS(ny, nx, visited, i);
	}

	return;
}

int main() {
	cin >> N;
	int temp, max_limit = 0, min_limit = 100;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> temp;
			max_limit = max(max_limit, temp);
			min_limit = min(min_limit, temp);
			arr[i][j] = temp;
		}
	}

	int max_cnt = 0;
	for (int i = min_limit - 1; i <= max_limit; ++i) {
		int visited[104][104] = { 0 };
		int cnt = 0;
		for (int k = 0; k < N; ++k) {
			for (int s = 0; s < N; ++s) {
				if (visited[k][s] == 0 && arr[k][s] > i) {
					DFS(k, s, visited, i);
					++cnt;
				}
			}
		}
		max_cnt = max(max_cnt, cnt);
	}

	cout << max_cnt << '\n';
	return 0;

}