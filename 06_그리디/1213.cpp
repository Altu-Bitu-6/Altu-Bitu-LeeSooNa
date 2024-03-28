#include <iostream>
#include <string>

using namespace std;

//팰린드롬이란 거꾸로 읽어도 같은 문장이나 단어를 의미


//알파벳 개수를 담을 배열 생성
int alphabet[26];

string pal(string s) {
    int odd = -1;
    string result = "";

    for (int i = 0; i < s.size(); i++) { //입력된 문자열의 알파벳별 개수
        alphabet[s[i] - 'A']++;
    }

    //앞부분
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] % 2 != 0) { //개수가 홀수인 알파벳 중에 
            if (odd != -1) { //2개이상이면 실패
                return "I'm Sorry Hansoo";
            }
            odd = i; //1개라면 odd는 i번째 문자임
        }

        int index = alphabet[i] / 2;

        for (int j = 0; j < index; j++) { //i번째 알파벳을 절반 개수만큼 추가
            result += i + 'A';
        }
    }

    //중간(존재한다면)
    if (odd != -1) { //개수가 홀수인 알파벳이 존재
        result += odd + 'A'; //팰린드롬에 추가
    }

    //뒷부분
    for (int i = 25; i >= 0; i--) { //거꾸로
        for (int j = 0; j < alphabet[i]/2; j++) { //알파벳을 절반 개수만큼 추가
            result += i + 'A';
        }
    }
    return result;
}

int main() {
    string input;
    cin >> input;

    cout << pal(input);

    return 0;

}