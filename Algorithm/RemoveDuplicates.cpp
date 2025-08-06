#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/* 첫 번째 방법
map<int, int> mp;

int main() {
	vector<int> v{ 1,1,2,2,3,3 };

	for (int i : v) {
		if (mp[i])
			continue;
		else
			mp[i] = 1;
	}

	vector<int> ret;
	for (auto i : mp) 
		ret.push_back(i.first);
	

	for (auto i : ret)
		cout << i << " ";
}
*/

vector<int> v = { 2,2,1,1,2,2,3,3,5,6,7,8,9 };
vector<int> s = { 4, 3, 3, 5, 1, 2, 3 };

int main() {
	auto it = unique(v.begin(), v.end());
	for (auto i : v)	cout << i << " ";
	cout << endl;

	cout << it - v.begin() << endl;


	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	for (auto i : s)
		cout << i << " ";
	cout << endl;

	return 0;
}