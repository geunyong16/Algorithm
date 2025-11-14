#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

int visited[10004];
int n, m, cnt, here, there;
vector<int> ret;

int main() {
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; ++i) {
		cin >> there >> here;
		adj[here].push_back(there);
	}

	for (int i = 1; i <= n; ++i) {
		memset(visited, 0, sizeof(visited));
		int temp = 1;
		queue<int> que;
		visited[i] = 1;
		que.push(i);
		while (!que.empty()) {
			int here = que.front();
			que.pop();

			for (int j = 0; j < adj[here].size(); ++j) {
				if (visited[adj[here][j]] == 0) {
					visited[adj[here][j]] = 1;
					que.push(adj[here][j]);
					++temp;
				}
			}
		}
		if (cnt < temp) {
			cnt = temp;
			ret.clear();
			ret.push_back(i);
		}
		else if (cnt == temp)
			ret.push_back(i);
	}


	for (auto i : ret)
		cout << i << " ";
	return 0;
}