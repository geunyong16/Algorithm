#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int rst = INT_MIN;
int n, m;
vector<vector<int>> arr;	// 0 빈칸   1 벽   2 바이러스
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

// 안전구역의 넓이를 구하는 함수
int calculate(vector<vector<int>>& v) {
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j] == 0)
				++cnt;
		}
	}

	return cnt;
}


// 바이러스가 퍼지는 함수
void diffuse(vector<vector<int>>& v) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j] == 2) {
				queue<pair<int, int>> que;
				que.push({ i,j });
				while (que.size()) {
					int y = que.front().first;
					int x = que.front().second;
					que.pop();

					for (int k = 0; k < 4; ++k) {
						int ny = y + dy[k];
						int nx = x + dx[k];

						if (ny < 0 || nx < 0 || ny >= n || nx >= m || v[ny][nx] == 2 || v[ny][nx] == 1)
							continue;

						v[ny][nx] = 2;
						que.push({ ny,nx });
					}
				}
			}
		}
	}
}

// 벽 3개를 선택하는 함수
void choice(int r) {
	if (r == 3) {
		vector<vector<int>> v(arr);
		diffuse(v);
		rst = max(rst, calculate(v));
		return;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				choice(r + 1);
				arr[i][j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> ar;
	for (int i = 0; i < 10; ++i)
		ar.push_back(0);

	for (int i = 0; i < 10; ++i)
		arr.push_back(ar);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];
	}

	choice(0);

	cout << rst;
	return 0;
}