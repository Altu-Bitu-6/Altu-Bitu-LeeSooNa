#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x;
    priority_queue<int, vector<int>, greater<int> > max_heap;

    //입력
    cin >> n;

    for (int i = 0; i < n*n; i++) {
        cin >> x;
        max_heap.push(x);

        if(max_heap.size() > n) { //size를 n
            max_heap.pop();
        }
    }


    cout << max_heap.top() << "\n"; //n번째 큰 수

    return 0;

}