#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// 백준 2309 문제

/// <summary>
/// 내가 푼 코드
/// </summary>
/*
int main() {
	int temp, sum = 0;
	vector<int> v;
	
	for (int i = 0; i < 9; ++i) {
		cin >> temp;
		sum += temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	int i, j, flag = 0;
	for (i=0; i < 9; ++i) {
		for (j=0; j < 9; ++j) {
			if (i == j) continue;
			if (sum - v[i] - v[j] == 100)
				flag = 1;
			if (flag == 1)
				break;
		}
		if (flag == 1)
			break;
	}

	for (int k = 0; k < 9; ++k) {
		if (k != i && k != j)
			cout << v[k] << endl;
	}
}
*/


/// <summary>
/// 순열을 이용해서 하는 방법
/// 수가 작기 때문에 가능한 방법임
/// </summary>
/// 
/*
int a[9];

int main() {
	for (int i = 0; i < 9; ++i)
		cin >> a[i];

	sort(a, a + 9);

	do {
		int sum = 0;
		for (int i = 0; i < 7; ++i)
			sum += a[i];
		if (sum == 100)
			break;
	} while (next_permutation(a, a + 9));

	for (int i = 0; i < 7; ++i) cout << a[i] << endl;

	return 0;
}
*/

/// <summary>
/// 조합을 이용한 방식
/// </summary>
/*
int sum = 0, a[9];
pair<int, int> p;

void solve() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (i == j) continue;
			if (sum - a[i] - a[j] == 100) {
				p = { i,j };
				return;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 9; ++i) {
		cin >> a[i];
		sum += a[i];
	}

	sort(a, a + 9);

	solve();

	for (int i = 0; i < 9; ++i) {
		if (i != p.first && i != p.second)
			cout << a[i] << endl;
	}
}
*/

/// <summary>
/// 순열을 이용해서 풀 수 있기 때문에 순열을 재귀함수로 구현해서 문제를 품
/// </summary>

int n = 9, r = 7;
int a[9];

void solve() {
	int sum = 0;
	for (int i = 0; i < r; ++i)
		sum += a[i];

	if (sum == 100) {
		sort(a, a + 7);
		for (int i = 0; i < r; ++i)
			cout << a[i] << endl;
		exit(0);
	}
	return;
}

void makePermutation(int n, int r, int depth) {
	if (r == depth) {
		solve();
		return;
	}
	for (int i = depth; i < n; ++i) {
		swap(a[i], a[depth]);
		makePermutation(n, r, depth + 1);
		swap(a[i], a[depth]);
	}
}


int main() {
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	makePermutation(n, r, 0);
	
	return 0;
}