#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int n, A, B, sumA, sumB;
string pre, t;

void print() {
	cout << setw(2) << setfill('0') << sumA / 60 << ':' << setw(2) << setfill('0') << sumA % 60 << '\n';
	cout << setw(2) << setfill('0') << sumB / 60 << ':' << setw(2) << setfill('0') << sumB % 60 << '\n';
}

int	changeTimeToSecond(string time) {
	return atoi(time.substr(0, 2).c_str()) * 60 + atoi(time.substr(3).c_str());
}

void go(int& sum, string t) {
	sum += changeTimeToSecond(t) - changeTimeToSecond(pre);
}

int main() {
	cin >> n;
	int team;
	for (int i = 0; i < n; ++i) {
		cin >> team >> t;

		if (A < B) go(sumB, t);
		else if (A > B) go(sumA, t);

		team == 1 ? ++A : ++B;

		pre = t;
	}

	if (A > B) go(sumA, "48:00");
	else if (A < B) go(sumB, "48:00");

	print();
}