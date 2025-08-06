#include <iostream>

using namespace std;

int a[100001], b, c, psum[100001], n, m;

/*
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 0; i < m; ++i) {
		cin >> b >> c;
		int sum = 0;
		for (int i = b; i <= c; ++i) {
			sum += a[i];
		}
		cout << sum << endl;
	}
}
*/

int main() {
	cin >> n >> m;
	psum[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> b >> c;
		cout << psum[c] - psum[b - 1] << endl;
	}
}