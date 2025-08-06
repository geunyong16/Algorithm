#include <iostream>

using namespace std;

int cnt[101];

int main() {
	int A, B, C, s, e;
	cin >> A >> B >> C;
	
	for (int i = 0; i < 3; ++i) {
		cin >> s >> e;
		for (int j = s; j < e; ++j) {
			cnt[j]++;
		}
	}

	int sum = 0;
	for (int i = 0; i < 100; ++i) {
		if (cnt[i] == 0)
			continue;
		else if (cnt[i] == 1)
			sum += A;
		else if (cnt[i] == 2)
			sum += 2*B;
		else if (cnt[i] == 3)
			sum += 3*C;
	}

	cout << sum << endl;

	return 0;
}