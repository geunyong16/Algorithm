#include <algorithm>
#include <iostream>

using namespace std;

int r, c, ret;
char arr[24][24];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

/// <summary>
/// 현재 위치 {y,x}에서 이동할 수 있는 곳이 있다면 go를 실행
/// </summary>
/// <param name="y">현재 y</param>
/// <param name="x">현재 x</param>
/// <param name="num">26자리 비트마스킹한 것</param>
/// <param name="cnt">총 몇 개 비트마스킹 했는지</param>
void go(int y, int x, int num, int cnt) {
	ret = max(ret, cnt);
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;

		int new_num = 1 << ((int)(arr[ny][nx] - 'A'));
		if ((num & new_num) == 0)
			go(ny, nx, num | new_num, cnt + 1);
	}

	return;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j)
			cin >> arr[i][j];
	}

	go(0, 0, (1 << (int)(arr[0][0] - 'A')), 1);
	cout << ret;
	return 0;
}