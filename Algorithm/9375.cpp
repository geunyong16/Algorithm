#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
bool find(vector<string> vec, string kind) {
	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i] == kind)
			return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int test, N;
	string clothes, kind;
	cin >> test;

	for (int i = 0; i < test; ++i) {
		cin >> N;
		map<string, int> fashion;
		vector<string> kind_vec;
		for (int j = 0; j < N; ++j) {
			cin >> clothes >> kind;
			fashion[kind]++;
			if (!find(kind_vec, kind))
				kind_vec.push_back(kind);
		}
		
		int count = 1;
		for (int j = 0; j < kind_vec.size(); ++j) {
			count *= fashion[kind_vec[j]] + 1;
		}
		
		cout << count - 1 << "\n";
	}
}
*/

int main() {
	int t, n;
	string c, k;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n;
		map<string, int> kind;
		for (int j = 0; j < n; ++j) {
			cin >> c >> k;
			kind[k]++;
		}

		long long result = 1;
		for (auto c : kind) {
			result *= (long long)(c.second + 1);
		}

		cout << result - 1 << "\n";
	}
}