#include <iostream>
#include <algorithm>
#include <stack>
#include <deque>
#include <map>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	map<string, int> m;

	for (int i = 0; i < s.size(); ++i) {
		string t;
		for (int j = i; j < s.size(); ++j) {
			t += s[j];
			m[t]++;
		}
	}

	cout << m.size();
}