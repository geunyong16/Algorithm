#include <iostream>
#include <algorithm>
#include <stack>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	deque<int> dq;
	int n, x, o;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> o;
		if (o == 1) {
			cin >> x;
			dq.push_front(x);
		}
		else if (o == 2) {
			cin >> x;
			dq.push_back(x);
		}
		else if (o == 3) {
			if (dq.size()) {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else
				cout << -1 << "\n";
		}
		else if (o == 4) {
			if (dq.size()) {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else
				cout << -1 << "\n";
		}
		else if (o == 5) {
			cout << dq.size() << "\n";
		}
		else if (o == 6) {
			cout << dq.empty() << "\n";
		}
		else if (o == 7) {
			if (dq.size()) {
				cout << dq.front() << "\n";
			}
			else
				cout << -1 << "\n";
		}
		else if (o == 8) {
			if (dq.size()) {
				cout << dq.back() << "\n";
			}
			else
				cout << -1 << "\n";
		}
	}
}