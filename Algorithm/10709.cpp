#include <vector>
#include <iostream>

using namespace std;

int arr[104][104];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int h, w;
	string c;
	cin >> h >> w;

	for (int i = 0; i < h; ++i) {
		cin >> c;
		for (int j = 0; j < w; ++j) {
			if (c[j] == 'c') {
				arr[i][j] = 0;
			}
			else arr[i][j] = -1;
		}
	}

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (arr[i][j] == 0) {
				int cnt = 0;
				while (arr[i][j + 1] == -1) {
					++cnt;
					++j;
					arr[i][j] = cnt;
				}
			}
		}
	}

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j)
			cout << arr[i][j] << " ";
		cout << '\n';
	}
}