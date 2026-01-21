#include <iostream>
#include <algorithm>

using namespace std;

int inp1, inp2, inp3;

int main() {
	cin >> inp1 >> inp2 >> inp3;

	if (inp1 == inp2 && inp2 == inp3)
		cout << 10000 + inp1 * 1000;
	else if (inp1 == inp2 || inp2 == inp3 || inp3 == inp1) {
		if (inp1 == inp2 || inp1 == inp3)
			cout << 1000 + inp1 * 100;
		else
			cout << 1000 + inp2 * 100;
	}
	else
		cout << max(max(inp1, inp2), inp3) * 100;

	return 0;
}