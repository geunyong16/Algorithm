#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <string>

using namespace std;

int visited[10004];
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> v;

void set(pair<int, int>& most) {
	while (visited[most.second] != 0) {
		most.second--;
		if (most.second == 0)
			return;
	}
	visited[most.second] = most.first;
	return;
}

void go() {
	while (!pq.empty()) {
		pair<int, int> most = pq.top();
		pq.pop();
		set(most);
	}
	return;
}

int main() {
	int n, d, p, sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p >> d;
		pq.push({ p, d });
	}

	go();

	for (auto i : visited) {
		sum += i;
	}
	cout << sum << "\n";

	return 0;
}