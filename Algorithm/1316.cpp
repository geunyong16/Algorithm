#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

bool groupWord(string s) {
	map<char, int> dupl;
	char prev = s[0];
	dupl[prev]++;
	for (int i = 1; i < s.size(); ++i) {
		if (prev == s[i])
			continue;

		dupl[s[i]]++;
		prev = s[i];
	}

	for (auto d : dupl) {
		if (d.second >= 2)
			return false;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, ret = 0;
	string inp;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> inp;
		if (groupWord(inp)) {
			++ret;
		}
	}
	cout << ret << '\n';
	return 0;
}