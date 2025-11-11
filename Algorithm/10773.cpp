#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	int k, temp;
	cin >> k;
	stack<int> s;
	for (int i = 0; i < k; ++i) {
		cin >> temp;
		if (temp == 0)
			s.pop();
		else
			s.push(temp);
	}

	if (s.empty())
		cout << 0;
	else {
		int sum = 0;
		while (!s.empty()) {
			sum += s.top();
			s.pop();
		}
		cout << sum;
	}

	return 0;

}