#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

vector<string> v;

bool comp(string s1, string s2) {
	if (s1.size() == s2.size())
		return s1 < s2;
	return s1.size() < s2.size();
}

string remove_zero(string s) {
	while (s.size() && s.front() == '0') {
		s.erase(s.begin());
	}

	if (s.size() == 0)
		return "0";
	return s;
}

void Func(string s) {
	string temp = "";
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= 65 && temp.size()) {
			v.push_back(remove_zero(temp));
			temp = "";
		}
		else if (s[i] <= 65)
			temp += s[i];
	}
	if (temp.size() != 0)
		v.push_back(remove_zero(temp));
}

int main() {
	int n;
	string s;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> s;
		Func(s);
	}

	sort(v.begin(), v.end(), comp);

	for (auto i : v)
		cout << i << '\n';
}