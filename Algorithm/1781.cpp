#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, dead, cup;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> ret;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> dead >> cup;
		v.push_back({ dead,cup });
	}

	sort(v.begin(), v.end());

	for (auto t : v) {
		ret.push(t.second);
		if (ret.size() > t.first)
			ret.pop();
	}

	int sum = 0;
	while (ret.size()) {
		sum += ret.top();
		ret.pop();
	}
	cout << sum;
}