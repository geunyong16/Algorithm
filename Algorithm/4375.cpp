#include <iostream>
#include <string>

using namespace std;

long long n;

void solve(long long n) {
	string len = "1";
	while (true) {
		long long num = atoll(len.c_str());
		if (num < n) {}
		else if (num % n == 0) {
			cout << len.size() << '\n';
			break;
		}
		len += '1';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (!cin.eof()) {
		cin >> n;
		solve(n);
	}

	return 0;
}