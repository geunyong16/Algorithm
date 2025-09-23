#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

map<int, int> mp; // key : 값, value : 횟수, map을 사용하는 이유는 횟수를 측정하는 것이기 때문에 중복 허용 x
map<int, int> mp_first; // key : 값, value : 처음 등장한 index, map을 사용하는 이유는 탐색 시간이 O(log n)이고, 중복 허용 x

/// <summary>
/// first는 횟수
/// second는 값
/// </summary>
bool compare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first == p2.first)
		return mp_first[p1.second] < mp_first[p2.second];
	return p1.first > p2.first;
}

int main() {
	int n, c;
	cin >> n >> c;

	int temp;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		mp[temp]++;
		if (mp_first.find(temp) == mp_first.end()) {
			mp_first[temp] = i;
		}
	}

	vector<pair<int, int>> v;
	for (auto m : mp) {
		v.push_back({ m.second,m.first });
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].first; ++j)
			cout << v[i].second << " ";
	}
}