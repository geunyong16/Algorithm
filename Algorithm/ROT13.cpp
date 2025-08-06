#include <iostream>
#include <string>

using namespace std;

/*
int main() {
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= 97 && s[i] <= 122) {
			int index = (int)(s[i]-97) + 13;
			if (index >= 26)
				index -= 26;
			s[i] = 97 + index;
		}
		else if (s[i] >= 65 && s[i] <= 90) {
			s[i] += 13;
			if (s[i] > 90) {
				int temp = s[i] - 91;
				s[i] = 65 + temp;
			}
		}
	}

	cout << s << endl;
}
*/

int main() {
	string s;
	getline(cin, s);
	
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= 65 && s[i] <= 90) {
			if (s[i] + 13 > 90)	s[i] -= 13;
			else s[i] += 13;
		}
		else if (s[i] >= 97 && s[i] <= 122) {
			if (s[i] + 13 > 122) s[i] -= 13;
			else s[i] += 13;
		}
	}

	cout << s;

	return 0;
}