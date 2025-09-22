#include <iostream>

using namespace std;

int n, m, j, drop_pos, s_pos, e_pos;
int arr[11];

bool isRange() {
	if (s_pos <= drop_pos && drop_pos <= e_pos)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	cin >> j;
	int ret = 0;
	while (j > 0) {
		cin >> drop_pos;
		s_pos = 1;
		e_pos = s_pos + m - 1;
		if (!isRange()) {
			if (s_pos > drop_pos) {
				ret += (s_pos - drop_pos);
				s_pos = drop_pos;
			}
			else {
				ret += (drop_pos - e_pos);
				s_pos += (drop_pos - e_pos);
			}
		}
		--j;
	}
	cout << ret << '\n';
	return 0;
}