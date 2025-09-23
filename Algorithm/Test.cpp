#include <iostream>

using namespace std;

bool isVow(int idx) {
	return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

int main() {
	string s;
	while (cin >> s) {
		if (s == "end")
			break;

		int flag = 0;	//0이면 accept, 1이면 not accept
		int v_cnt = 0, c_cnt = 0;
		int prev;
		bool is_include_vow = false;
		for (int i = 0; i < s.size(); ++i) {
			int idx = s[i];
			if (isVow(idx)) {
				v_cnt++;
				c_cnt = 0;
				is_include_vow = true;
			}
			else {
				v_cnt = 0;
				c_cnt++;
			}

			if (v_cnt == 3 || c_cnt == 3) flag = 1;

			if (i >= 1 && prev == idx && (prev != 'e' && prev != 'o'))
				flag = 1;

			prev = idx;
		}
		if (!is_include_vow) flag = 1;
		if(flag)
			cout << '<' << s << "> is not acceptable.\n";
		else
			cout << '<' << s << "> is acceptable.\n";
	}
}