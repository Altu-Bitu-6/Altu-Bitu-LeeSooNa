#include <iostream>
#include <string>

using namespace std;



int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n;
	cin >> n; //반복 횟수 (1<= n <= 3,000,000)

	string s; //연산 명령
	int x; //연산할 수

	int S = 0; // 집합

	while (n--) {
		cin >> s; //명령 입력

		if (s == "add") {
			cin >> x;
			S |= (1 << x);
		}
		else if (s == "remove") {
			cin >> x;
			S &= ~(1 << x);

		}
		else if (s == "check") {
			cin >> x;
			if (S & (1 << x)) {//x가 S에 존재하면
				cout << "1\n";
			}
			else {//x가 S에 존재하지 않으면
				cout << "0\n";
			}
		}
		else if (s == "toggle") {
			cin >> x;
			if (S & (1 << x)) {//x가 S에 존재하면
				S &= ~(1 << x); //remove 연산
			}
			else {
				S |= (1 << x); //add 연산
			}
		}
		else if (s == "all") {
			S = (1 << 21) - 1; //모두 1

		}
		else if (s == "empty") {
			S = 0; //모두 0
		}
	}
	return 0;
}