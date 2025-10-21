#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>

using namespace std;

int n, flag, ret = INT_MAX, total_sum;
int arr[10];
int visited[10];
vector<vector<int>> adj_list;

void DFS(vector<int>& list, int u) {
	for (auto v : adj_list[u]) {	//u와 연결되어있는 v
		int vflag = 0;
		for (auto c : list) {
			if (c == v)
				vflag = 1;
		}
		if (visited[v] == 0 && vflag) {
			visited[v] = 1;
			DFS(list, v);
		}
	}
}

bool check(vector<int>& cc, vector<int>& ss) {
	if (cc.size() == n || ss.size() == n)
		return false;

	memset(visited, 0, sizeof(visited));

	/// cs구역에 있는 놈들끼리 연결이 되어있는지
	/// 나머지 구역에 있는 놈들끼리 연결이 되어있는지 판단하기
	visited[cc[0]] = 1;
	DFS(cc, cc[0]);

	visited[ss[0]] = 1;
	DFS(ss, ss[0]);

	for (int i = 0; i < n; ++i) {
		if (visited[i] == 0)
			return false;
	}
	return true;
}

int cal_dif(vector<int>& cc) {
	int sum = 0;
	for (auto c : cc) {
		sum += arr[c];
	}

	return abs(total_sum - 2 * sum);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		total_sum += arr[i];
	}

	int cnt, num;
	for (int i = 0; i < n; ++i) {
		cin >> cnt;
		vector<int> list;
		for (int j = 0; j < cnt; ++j) {
			cin >> num;
			list.push_back(num - 1);
		}
		adj_list.push_back(list);
	}

	for (int i = 1; i < (1 << n); ++i) {
		vector<int>cc;
		vector<int>ss;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j))
				cc.push_back(j);
			else
				ss.push_back(j);
		}
		if (check(cc, ss)) {
			flag = 1;
			ret = min(ret, cal_dif(cc));
		}
	}

	if (flag)
		cout << ret;
	else
		cout << -1;
}