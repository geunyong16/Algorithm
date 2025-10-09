#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool check(string s) {

	stack<int> st;	// 0 == ¼Ò°ıÈ£  1 == ´ë°ıÈ£
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(')
			st.push(0);
		else if (s[i] == '[')
			st.push(1);


		if (s[i] == ')') {
			if (st.size() && st.top() == 0)
				st.pop();
			else
				return false;
		}
		if (s[i] == ']') {
			if (st.size() && st.top() == 1)
				st.pop();
			else
				return false;
		}
	}

	if (st.size())
		return false;
	else
		return true;
}

int main() {
	string s;
	while (getline(cin, s)) {
		if (s == ".")
			return 0;

		if (check(s))
			cout << "yes\n";
		else
			cout << "no\n";
	}
}