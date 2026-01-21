#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
string alpha[20004];

bool compare(string& first, string& second) {
	if (first.size() != second.size())
		return first.size() < second.size();
	return first < second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> alpha[i];

	sort(begin(alpha), begin(alpha) + N, compare);

	cout << alpha[0] << '\n';
	for (int i = 1; i < N; ++i) {
		string prev = alpha[i - 1];
		if (prev == alpha[i])
			continue;
		cout << alpha[i] << "\n";
	}

	return 0;
}