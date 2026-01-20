#include <iostream>
#include <algorithm>

using namespace std;

int H, M;

int main() {
	cin >> H >> M;

	if (M < 45) {
		if (H == 0)
			cout << 23 << " " << M + 15;
		else
			cout << H - 1 << " " << M + 15;
	}
	else
		cout << H << " " << M - 45;
	return 0;
}