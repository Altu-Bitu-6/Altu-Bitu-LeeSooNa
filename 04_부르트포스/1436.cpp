#include <iostream>

using namespace std;


int number(int n) { 

	int index=0;
	int title;

	for (title=666; ; title++) { //666번부터 시작
		int tmp = title;

		while (tmp >= 666) { //666보다 작거나 같아질 때까지 반복
			if (tmp % 1000 == 666) {
				index++;
				break;
			}
			tmp /= 10; 
		}
		if (index == n) {
			return title;
			break;

		}
	}
	
}


int main() {
	int n;
	cin >> n;
	cout << number(n) << "\n";

	return 0;
}
