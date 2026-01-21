#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

string subject, grade;
double credit, accumulatedScore, total_credit;

map<string, double> gradeToScore;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	gradeToScore.insert({ "A+",4.5 });
	gradeToScore.insert({ "A0",4.0 });
	gradeToScore.insert({ "B+",3.5 });
	gradeToScore.insert({ "B0",3.0 });
	gradeToScore.insert({ "C+",2.5 });
	gradeToScore.insert({ "C0",2.0 });
	gradeToScore.insert({ "D+",1.5 });
	gradeToScore.insert({ "D0",1.0 });
	gradeToScore.insert({ "F",0.0 });

	for (int i = 0; i < 20; ++i) {
		cin >> subject >> credit >> grade;
		if (grade == "P")
			continue;
		accumulatedScore += gradeToScore[grade] * credit;
		total_credit += credit;
	}

	cout << fixed;
	cout.precision(6);
	cout << accumulatedScore / total_credit;

	return 0;
}