#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string S, P, ret = "";
	cin >> S >> P;
	for (char s : S) {
		ret += s;
		if (ret.size() >= P.size() && ret.substr(ret.size() - P.size(), P.size()) == P)
			ret.erase(ret.end() - P.size(), ret.end());
	}
	if (ret != "")
		cout << ret;
	else
		cout << "FRULA";
}