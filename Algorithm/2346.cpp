#include <iostream>
#include <queue>

using namespace std;

struct Balloons {
	int index;
	int offset;
};

int N, offset;
deque<Balloons> balloons;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> offset;
		balloons.push_back({ i,offset });
	}

	while (balloons.size()) {
		cout << balloons.front().index << " ";
		offset = balloons.front().offset;
		balloons.pop_front();
		if (balloons.empty())
			return 0;
		if (offset > 0) {
			for (int i = 0; i < offset - 1; ++i) {
				balloons.push_back(balloons.front());
				balloons.pop_front();
			}
		}
		else {
			for (int i = 0; i < -offset; ++i) {
				balloons.push_front(balloons.back());
				balloons.pop_back();
			}
		}
	}
	return 0;
}