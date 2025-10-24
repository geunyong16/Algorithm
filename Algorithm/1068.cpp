#include <iostream>
#include <vector>

using namespace std;

int arr[54], child[54];
int n, e;
vector<int> lst;


bool F_DFS(int index) {
	if (index < 0) return false;
	if (index == e)
		return true;
	return F_DFS(arr[index]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	cin >> e;

	for (int i = 0; i < n; ++i) {
		if (F_DFS(i))
			lst.push_back(i);
	}

	for (auto i : lst) {
		arr[i] = -2;
	}

	for (int i = 0; i < n; ++i) {
		if (arr[i] < 0)
			continue;
		child[arr[i]]++;
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] >= -1 && child[i] == 0)
			++cnt;
	}

	cout << cnt;
	return 0;
}