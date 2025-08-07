#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/*
vector<int> temp;

int Sum(int index, int k) {
	int sum = 0;
	for (int i = index; i < index + k; ++i)
		sum += temp[i];
	return sum;
}

int main() {
	int N, K, t;
	cin >> N >> K;
	
	for (int i = 0; i < N; ++i) {
		cin >> t;
		temp.push_back(t);
	}

	int max_sum = INT_MIN;
	for (int i = 0; i <= N - K; ++i) {
		int temp_sum = Sum(i, K);
		max_sum = max(max_sum, temp_sum);
	}

	cout << max_sum << endl;

	return 0;
}
*/

int psum[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K, temp;
	psum[0] = 0;
	cin >> N >> K;

	for (int i = 1; i <= N; ++i) {
		cin >> temp;
		psum[i] = psum[i - 1] + temp;
	}

	int max_sum = INT_MIN;

	for (int i = K; i <= N; ++i) {
		max_sum = max(max_sum, psum[i] - psum[i - K]);
	}

	cout << max_sum << "\n";
	return 0;
}