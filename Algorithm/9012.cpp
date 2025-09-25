#include <iostream>
#include <stack>

using namespace std;

bool Func(string input) {
	stack<char> s;

	for (int i = 0; i < input.size(); ++i) {
		if (input[i] == '(')
			s.push('(');
		else {
			if (s.size() == 0)
				return false;
			s.pop();
		}
	}

	if (s.size() == 0)
		return true;
	return false;
}

int main() {
	int T;
	string input;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> input;
		if (Func(input))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}