#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, cnt = 0;
	string w;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> w;
		stack<char> s;
		for (int j = 0; j < w.size(); ++j) {
			if (!s.empty() && s.top() == w[j]) s.pop();
			else s.push(w[j]);
		}
		if (s.empty())
			++cnt;
	}

	cout << cnt << '\n';
	return 0;
}