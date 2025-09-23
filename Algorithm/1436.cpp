#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	long long ret;
	int cnt = 0;

	for (long long i = 666; cnt < n; ++i) {
		if (to_string(i).find("666") != string::npos) {
			++cnt;
			ret = i;
		}
	}

	cout << ret;
}