#include <iostream>

using namespace std;

int cnt[26], N, flag = 0;
string name;

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> name;
		cnt[name[0] - 97]++;
	}

	for (int i = 0; i < 26; ++i) {
		if (cnt[i] >= 5) {
			cout << (char)(i + 97);
			flag = 1;
		}
	}

	if (flag == 0)
		cout << "PREDAJA";

	return 0;
}