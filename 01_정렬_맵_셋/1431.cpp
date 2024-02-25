#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std; 


bool cmp(string n1, string n2) {

	int sum1 = 0, sum2 = 0;
	int n1_length = n1.length();
	int n2_length = n2.length();


	if (n1_length != n2_length){
		return n1_length < n2_length;
	}

	for (int i = 0; i < n1_length; i++) {

		if ('0' <= n1[i] && n1[i] <= '9') {
			sum1 += n1[i] - '0';
		}

		if ('0' <= n2[i] && n2[i] <= '9') {
			sum2 += n2[i] - '0';
		}
	}

	if (sum1 != sum2) {
			return sum1 < sum2;
	}

	return n1< n2;
}

int main() {

	int n;
	cin >> n;
	vector<string> numbers;
	numbers.assign(n, {});

	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	
	sort(numbers.begin(), numbers.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << numbers[i]<< '\n';
	}
	
	return 0;
}

