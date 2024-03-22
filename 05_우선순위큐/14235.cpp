#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, a, g;
    priority_queue <int> pq;

    //입력
    cin >> n; //방문 횟수

    for (int i = 0; i < n; i++) {
        cin >> a;

        //아이들을 만난 경우
        if (a == 0) {
            //선물이 없다면
            if (pq.empty()) {
                cout << -1<< "\n";
                continue; //<<segmentation fault해결?
            }
            //선물이 있다면
            cout << pq.top() << "\n";
            pq.pop();
        }

        //선물을 충전
        while (a--) {
            cin >> g;
            pq.push(g);
        }
    }

    return 0;
}