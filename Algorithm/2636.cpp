#include <iostream>
#include <vector>

using namespace std;


int n, m, ret, rst;
int arr[104][104];
int visited[104][104];
vector<pair<int, int>> point;
vector<pair<int, int>> update;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void DFS(int y, int x) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m || arr[ny][nx] == 1 || visited[ny][nx] == 1)
			continue;
		DFS(ny, nx);
	}

	return;
}

void go() {
	if (point.size() <= 0) return;
	++rst;
	ret = point.size();
	for (int i = 0; i < point.size(); ++i) {
		int y = point[i].first;
		int x = point[i].second;
		for (int j = 0; j < 4; ++j) {
			int ny = y + dy[j];
			int nx = x + dx[j];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if (visited[ny][nx]) {
				arr[y][x] = 0;
				update.push_back({ ny,nx });
				point.erase(point.begin() + i, point.begin() + i + 1);
				--i;
				break;
			}
		}
	}

	for (auto u : update) {
		DFS(u.first, u.second);
	}

	update.clear();

	go();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j])
				point.push_back({ i,j });
		}
	}

	//바깥 공기를 모두 방문처리
	DFS(0, 0);

	go();

	cout << rst << "\n" << ret;

	return 0;
}
