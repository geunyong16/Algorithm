#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<char, int> mp;

bool check(string s) {
	int flag = 0;
	//모음이면 0, 자음이면 1저장
	vector<int> arr;
	for (int i = 0; i < s.size(); ++i) {
		if (mp.find(s[i]) != mp.end()) {
			++flag;
			arr.push_back(0);
		}
		else arr.push_back(1);
		if (i > 0 && s[i - 1] == s[i] && s[i] != 'e' && s[i] != 'o')
			return false;
	}

	if (flag == 0)
		return false;

	int pp;
	int p;
	for (int i = 2; i < arr.size(); ++i) {
		pp = arr[i - 2];
		p = arr[i - 1];
		if (pp == p && p == arr[i])
			return false;
	}
	return true;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	mp['a'];
	mp['e'];
	mp['i'];
	mp['o'];
	mp['u'];

	while (cin >> s) {
		if (s == "end")
			break;
		if (check(s))
			cout << '<' << s << "> is acceptable.\n";
		else
			cout << '<' << s << "> is not acceptable.\n";
	}
}