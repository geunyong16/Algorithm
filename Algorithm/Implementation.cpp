#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
/*
int main() {
	string dopa = "umzunsik";

	//Q1
	for (int i = 0; i < 3; ++i)
		cout << dopa[i] << " ";  
	cout << endl;

	//Q2
	for (int i = dopa.length() - 1; i >= 0; --i)
		cout << dopa[i] << " ";
	cout << endl;

	//Q3
	for (int i = 0; i <= dopa.length() / 2 - 1; ++i) {
		int temp = dopa[i];
		dopa[i] = dopa[dopa.length() - i - 1];
		dopa[dopa.length() - i - 1] = temp;
	}
	dopa += "umzunsik";
	for (int i = 0; i < dopa.length(); ++i)
		cout << dopa[i] << " ";
	cout << endl;
}
*/
/*
int main() {
	string dopa = "umzunsik";
	
	//Q1
	cout << dopa.substr(0, 3) << endl;
	
	//Q2
	reverse(dopa.begin(), dopa.end());
	cout << dopa << endl;

	//Q3
	dopa += "umzunsik";
	cout << dopa << endl;
}
*/

int main() {
	int N, temp;
	double sum = 0;
	vector<int> v;

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> temp;
		sum += temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size();++i) cout << v[i] << " ";
	cout << endl;

	cout << fixed << setprecision(2) << sum / N;
}