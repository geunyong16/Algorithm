#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	string name, order;
	vector<string> book_vec;
	map<string, int> book_map;
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		cin >> name;
		book_vec.push_back(name);
		book_map.insert({ name, i + 1 });
	}

	for (int i = 0; i < M; ++i) {
		cin >> order;
		if (atoi(order.c_str()) == 0)
			cout << book_map[order] << "\n";
		else
			cout << book_vec[atoi(order.c_str()) - 1] << "\n";
	}
	
}
