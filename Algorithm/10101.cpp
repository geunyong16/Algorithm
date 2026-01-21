#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> triangle(3);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> triangle[0] >> triangle[1] >> triangle[2];

	sort(begin(triangle), end(triangle));

	if (triangle[0] + triangle[1] + triangle[2] != 180)
		cout << "Error";
	else if (triangle[0] == triangle[1] && triangle[1] == triangle[2])
		cout << "Equilateral";
	else if (triangle[0] == triangle[1] || triangle[1] == triangle[2])
		cout << "Isosceles";
	else
		cout << "Scalene";

	return 0;
}