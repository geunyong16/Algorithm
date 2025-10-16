#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n, mp, mf, ms, mv, rst = INT_MAX;
int arr[15][5];

bool check(vector<int>& idx) {
	int tp = 0, tf = 0, ts = 0, tv = 0;
	for (auto i : idx) {
		tp += arr[i][0];
		tf += arr[i][1];
		ts += arr[i][2];
		tv += arr[i][3];
	}
	if (tp < mp || tf < mf || ts < ms || tv < mv)
		return false;
	return true;
}

int calcul(vector<int>& idx) {
	int result = 0;
	for (auto i : idx) {
		result += arr[i][4];
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> mp >> mf >> ms >> mv;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j)
			cin >> arr[i][j];
	}

	vector<int> ret;
	for (int i = 1; i < (1 << n); ++i) {
		vector<int> idx;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				idx.push_back(j);
			}
		}

		if (check(idx)) {
			if (rst > calcul(idx)) {
				rst = calcul(idx);
				ret.clear();
				ret = idx;
			}
			else if (rst == calcul(idx)) {
				for (int k = 0; k < min(idx.size(), ret.size()); ++k) {
					if (idx[k] < ret[k]) {
						ret.clear();
						ret = idx;
						break;
					}
					else if (idx[k] == ret[k])
						continue;
					else
						break;
				}
			}
		}
	}
	if (ret.size()) {
		cout << rst << '\n';
		for (auto r : ret)
			cout << r + 1 << " ";
		cout << '\n';
	}
	else {
		cout << -1 << '\n';
	}
	return 0;
}