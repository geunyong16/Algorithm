#include <iostream>

using namespace std;

typedef long long ll;

ll A, B, C;

//a´Â °öÇÏ´Â ¼ö, b´Â °öÇÏ´Â È½¼ö
ll go(ll a, ll b) {
	if (b == 1)
		return a % C;
	ll rest = go(a, b / 2);
	rest = (rest * rest) % C;
	if (b % 2) rest = (rest * a) % C;
	return rest;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B >> C;
	cout << go(A, B) << '\n';
	return 0;
}