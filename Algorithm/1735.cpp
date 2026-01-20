#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int A1, B1, A2, B2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A1 >> B1
		>> A2 >> B2;

	int A = A1 * B2 + A2 * B1;
	int B = B1 * B2;

	int max_gcd = gcd(A, B);
	A /= max_gcd;
	B /= max_gcd;

	cout << A << " " << B;

	return 0;
}