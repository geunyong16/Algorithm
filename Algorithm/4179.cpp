#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int r, c;
int visited[1004][1004];	//해당 공간에 들어간 시간은 = visited[i][j] - 1
int arr[1004][1004];
pair<int, int> start;

int main() {
	queue<pair<int, int>> fire;
	queue<pair<int, int>> person;

	cin >> r >> c;
	string temp;
	for (int i = 0; i < r; ++i) {
		cin >> temp;
		for (int j = 0; j < temp.size(); ++j) {
			if (temp[j] == '#')
				arr[i][j] = 0;
			else if (temp[j] == '.')
				arr[i][j] = 1;
			else if (temp[j] == 'F') {
				arr[i][j] = -1;
				visited[i][j] = -1;
				fire.push({ i,j });
			}
			else if (temp[j] == 'J') {
				arr[i][j] = 2;
				start.first = i;
				start.second = j;
				person.push({ i,j });
			}
		}
	}

	while (!fire.empty()) {
		int y = fire.front().first;
		int x = fire.front().second;
		fire.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (visited[ny][nx] != 0) continue;
			if (arr[ny][nx] == 0) continue;
			visited[ny][nx] = visited[y][x] - 1;
			fire.push({ ny,nx });
		}
	}

	visited[start.first][start.second] = 1;

	while (!person.empty()) {
		int y = person.front().first;
		int x = person.front().second;
		person.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) {
				cout << visited[y][x];
				return 0;
			}
			if (visited[ny][nx] > 0) continue;
			if (visited[ny][nx] < 0 && abs(visited[ny][nx]) <= visited[y][x] + 1) continue;
			if (arr[ny][nx] == 0) continue;
			visited[ny][nx] = visited[y][x] + 1;
			person.push({ ny,nx });
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}