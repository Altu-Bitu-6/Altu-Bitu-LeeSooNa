#include <iostream> 
#include <set>
#include <string>


using namespace std; 

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int sum = 0;
	string s;
	set<string> string_set;

	cin >> n >> m;


	for (int i = 0; i < n; i++) { //문자열 집합 생성
		cin >> s;
		string_set.insert(s);
	}

	for (int i = 0; i < m; i++) {//m개의 문자열 점검
		cin >> s;
		
		set<string>::iterator iter;
		iter=string_set.find(s); //find 함수는 iterator 반환

		if (iter != string_set.end()) {
			sum++;
		}
		
	}

	cout << sum;
}