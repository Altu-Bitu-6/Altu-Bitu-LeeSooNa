#include <iostream>
#include <queue>


using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n>> k; 

    queue<int> q;

    //번호순으로 queue 원소 생성
    for (int i = 1; i < n+1; i++) {
        q.push(i);
    }

    cout << "<";

    while (q.size() > 1) { //q 크기만큼 반복

        for (int i = 0; i < k-1; i++) { //앞에서부터 k-1개를 push하고 pop하여 제거
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", "; //front에 제거할 대상이 남고 이를 출력
        q.pop();
    }
    cout <<q.front()<< ">";
    return 0;
}
