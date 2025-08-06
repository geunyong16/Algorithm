#include <iostream>
#include <string>

using namespace std;

int main() {
	string S;
	int a[26] = { 0 };
	cin >> S;

	for (int i = 0; i < S.size(); ++i) 
		++a[S[i] - 97];

	for (int i : a)cout << i << " ";
}