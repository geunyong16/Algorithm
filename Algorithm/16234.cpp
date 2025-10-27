#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, l, r, cnt;
int arr[54][54], visited[54][54];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void DFS(int here_y, int here_x, vector<pair<int, int>>& lst) {
	visited[here_y][here_x] = 1;
	lst.push_back({ here_y,here_x });

	for (int i = 0; i < 4; ++i) {
		int new_y = here_y + dy[i];
		int new_x = here_x + dx[i];
		if (new_y < 0 || new_x < 0 || new_y >= n || new_x >= n || visited[new_y][new_x])
			continue;
		int dif = abs(arr[new_y][new_x] - arr[here_y][here_x]);
		if (l <= dif && dif <= r)
			DFS(new_y, new_x, lst);
	}

	return;
}

bool check() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < 4; ++k) {
				int n_i = i + dy[k];
				int n_j = j + dx[k];

				if (n_i < 0 || n_j < 0 || n_i >= n || n_j >= n)
					continue;
				int dif = abs(arr[n_i][n_j] - arr[i][j]);
				if (l <= dif && dif <= r)
					return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> l >> r;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];
	}

	while (check()) {
		vector<vector<pair<int, int>>> vlst;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (visited[i][j])
					continue;
				vector<pair<int, int>> lst;
				DFS(i, j, lst);
				vlst.push_back(lst);
			}
		}
		for (int i = 0; i < vlst.size(); ++i) {
			if (vlst[i].size() == 1)
				continue;
			int temp = 0;
			for (int j = 0; j < vlst[i].size(); ++j)
				temp += arr[vlst[i][j].first][vlst[i][j].second];
			int div = temp / vlst[i].size();
			for (int j = 0; j < vlst[i].size(); ++j)
				arr[vlst[i][j].first][vlst[i][j].second] = div;
		}
		memset(visited, 0, sizeof(visited));
		++cnt;
	}

	cout << cnt;
	return 0;
}