#include <iostream>

using namespace std;

int arr[70][70];
int N;

void check(int s_i, int s_j, int size) {
	if (size == 0)
		return;
	int flag = 0;
	for (int k = 0; k < size; ++k) {
		for (int s = 0; s < size; ++s) {
			if (arr[s_i + k][s_j + s] == 1)
				++flag;
		}
	}


	if (flag == 0) cout << 0;
	else if (flag == size * size) cout << 1;
	else {
		cout << '(';
		check(s_i, s_j, size / 2);
		check(s_i, s_j + size / 2, size / 2);
		check(s_i + size / 2, s_j, size / 2);
		check(s_i + size / 2, s_j + size / 2, size / 2);
		cout << ')';
	}
}


int main() {
	cin >> N;
	string input;
	for (int i = 0; i < N; ++i) {
		cin >> input;
		for (int j = 0; j < input.size(); ++j) {
			arr[i][j] = input[j] - '0';
		}
	}

	check(0, 0, N);
}