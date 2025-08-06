#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
int main() {
	string s;
	cin >> s;
	
	for (int i = 0; i < s.size() / 2; ++i) {
		if (s[i] != s[s.size() - 1 - i]) {
			cout << 0 << endl;
			return 0;
		}
	}
	cout << 1 << endl;

	return 0;
}
*/

int main() {
	string s, temp;
	cin >> s;
	temp = s;
	reverse(temp.begin(), temp.end());
	if (s == temp)
		cout << 1 << endl;
	else
		cout << 0 << endl;

	return 0;
}