#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true) { //마지막 온점

        string input;
        getline(cin, input); //띄어쓰기 포함 입력

        bool result = true;

        stack<char> s; //괄호 스택 정의

        if (input == ".") { break; } //마지막 문장 확인

        for (int i = 0; i < input.length(); i++) { //한 문장에서

            if (input[i] == '(') {
                s.push('(');
            }
            else if (input[i] == '[') {
                s.push('[');
            }

            if (input[i] == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                }
                else {
                    result = false;
                    break;
                }
            }
            else if (input[i] == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                }
                else {
                    result = false;
                    break;
                }
            }

        }

        //결과 출력
        if (s.empty()&&result) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }


    }   
    return 0;
}
