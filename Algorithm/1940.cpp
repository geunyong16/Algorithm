#include <iostream>
#include <vector>

using namespace std;

/*
int arr[15000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	
	int cnt = 0;
	for(int i=0;i<N;++i){
		if (arr[i] == 0)
			continue;

		for (int j = i + 1; j < N; ++j) {
			if (arr[j] == 0)
				continue;

			if (arr[i] + arr[j] == M) {
				++cnt;
				arr[i] = 0;
				arr[j] = 0;
				break;
			}

		}
	}

	cout << cnt;
}
*/

vector<int> arr;
vector<int> temp;
int N, M;

void FUN(int start,int cnt, vector<int>temp) {
	if (temp.size() == 2) {
		if (arr[temp[0]] + arr[temp[1]] == M)
			++cnt;
		return;
	}

	for (int i = start; i < N; ++i) {
		temp.push_back(arr[i]);
		FUN(i+1, cnt, temp);
		temp.pop_back();
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];


	int cnt = 0;
	FUN(0, cnt, temp);

	cout << cnt;
}