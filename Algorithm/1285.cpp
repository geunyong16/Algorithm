#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[24], ret;
string s;

void go(int here) {
	if (here = n + 1) {
		int sum = 0;
		//i는 열의 이진 번호
		for (int i = 1; i <= (1 << (n - 1)); i *= 2) {
			int cnt = 0;
			//j는 행의 번호
			for (int j = 1; j <= n; j++) {
				if (arr[j] & i)
					cnt++;
			}
			sum += min(cnt, n - cnt);
		}
		ret = min(ret, sum);
		return;
	}

	go(here + 1);
	arr[here] = ~arr[here];
	go(here + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s;
		int value = 1;
		for (int j = 0; j < n; ++j) {
			if (s[j] == 'T')
				arr[i] |= value;
			value *= 2;
		}
	}

	go(1);

	cout << ret;
	return 0;
}