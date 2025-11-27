#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int N, mnum;
int arr[1000004];
int NGE[1000004];
list<int> lst;

int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	lst.push_back(arr[N]);
	for (int i = N; i > 0; --i) {
		if (arr[i] < lst.front()) {
			NGE[i] = lst.front();
			lst.push_front(arr[i]);
		}
		else if (arr[i] >= lst.back()) {
			NGE[i] = -1;
			lst.clear();
			lst.push_back(arr[i]);
		}
		else {
			while (arr[i] >= lst.front()) {
				lst.pop_front();
			}
			NGE[i] = lst.front();
			lst.push_front(arr[i]);
		}
	}


	for (int i = 1; i <= N; ++i)
		cout << NGE[i] << " ";
	return 0;
}