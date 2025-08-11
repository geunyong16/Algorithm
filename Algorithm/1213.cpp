#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


/// <summary>
/// 
/// 내가 순열을 이용해서 짠 알고리즘 <- 시간 초과
/// </summary>
/*
bool func(string input) {
	string origin_input = input;
	reverse(origin_input.begin(), origin_input.end());
	if (origin_input == input)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string input;
	cin >> input;

	sort(input.begin(), input.end());

	do {
		if (func(input)) {
			cout << input << "\n";
			return 0;
		}
	} while (next_permutation(input.begin(), input.end()));

	cout << "I'm Sorry Hansoo" << "\n";
	return 0;
}
*/

/// <summary>
/// 내가 짠 알고리즘 -> 성공
/// </summary>
/*
int index[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string input;
	cin >> input;

	for (int i = 0; i < input.size(); ++i) {
		index[(int)input[i] - 'A']++;
	}

	int flag = 0;
	int mid_index = 26;
	string result;

	for (int i = 0; i < 26; ++i) {
		if (index[i]) {
			if (index[i] % 2 == 1) {
				flag++;
				mid_index = i;
				index[i]--;
			}
			if (flag == 2) {
				cout << "I'm Sorry Hansoo\n";
				return 0;
			}
			for (int j = 0; j < index[i] / 2; ++j)	
				result += i + 'A';
		}
	}

	string re_result = result;

	reverse(re_result.begin(), re_result.end());

	if (mid_index < 26)
		result += mid_index + 'A';

	result += re_result;

	cout << result << "\n";
	return 0;
}
*/

string input, result;
int cnt[200], flag;
char mid;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> input;
	for (auto a : input)cnt[a]++;

	for (int i = 'Z'; i >= 'A'; --i) {
		if (cnt[i]) {
			if (cnt[i] & 1) {
				flag++;
				mid = (char)i;
				cnt[i]--;
			}
			if (flag == 2) {
				cout << "I'm Sorry Hansoo\n";
				return 0;
			}
			for (int j = 0; j < cnt[i]; j += 2) {
				result = (char)i + result;
				result += (char)i;
			}
		}
	}
	if (mid) result.insert(result.begin() + result.size() / 2, mid);

	cout << result;
}